///-----------------------------------------------------------------------------
///  MeshViewer.cc
///-----------------------------------------------------------------------------
/// 
/// C:\Users\benja\AppData\Local\Programs\Python\Python39\libs


#include "Pre.h"
#include "Core/Main.h"
#include "Core/String/StringBuilder.h"
#include "Gfx/Gfx.h"
#include "IO/IO.h"
#include "IMUI/IMUI.h"
#include "Input/Input.h"
#include "LocalFS/LocalFileSystem.h"
#include "Assets/Gfx/MeshLoader.h"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/polar_coordinates.hpp"
#include "shaders.h"

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <Python.h>
#include <stdio.h>
#include <string.h>

#include "GraphicsManager.h"


using namespace Oryol;
namespace py = pybind11;
struct Model {
    int meshIndex;
    glm::mat4 transform;
    Id mesh;
    DrawState drawState;
    int numberOfMaterials;
    enum {
        Normals = 0,
        Lambert,
        Phong
    };
    struct Material {
        int shaderIndex = Phong;
        Id pipeline;
        glm::vec4 diffuse = glm::vec4(0.0f, 0.24f, 0.64f, 1.0f);
        glm::vec4 specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        float specPower = 32.0f;
    } materials[GfxConfig::MaxNumPrimGroups];
};
struct Mesh {
    DrawState drawState;
    int numberOfMaterials;
    MeshSetup setup;
};

class MeshViewerApp : public App {
public:
    AppState::Code OnInit()
    {
        py::initialize_interpreter();

        // setup IO system
        IOSetup ioSetup;
        ioSetup.FileSystems.Add("file", LocalFileSystem::Creator());
        IO::Setup(ioSetup);

        // setup rendering and input system
        auto gfxSetup = GfxSetup::WindowMSAA4(800, 512, "Oryol Mesh Viewer (Benves-7)");
        gfxSetup.HighDPI = true;
        gfxSetup.DefaultPassAction = PassAction::Clear(glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));
        Gfx::Setup(gfxSetup);
        Input::Setup();
        Input::SetPointerLockHandler([this](const InputEvent& event) -> PointerLockMode::Code {
            if (event.Button == MouseButton::Left) {
                if (event.Type == InputEvent::MouseButtonDown) {
                    if (!ImGui::IsAnyWindowHovered()) {
                        this->dragging = true;
                        return PointerLockMode::Enable;
                    }
                }
                else if (event.Type == InputEvent::MouseButtonUp) {
                    if (this->dragging) {
                        this->dragging = false;
                        return PointerLockMode::Disable;
                    }
                }
            }
            return PointerLockMode::DontCare;
            });

        // setup IMUI ui system
        IMUI::Setup();
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowRounding = 0.0f;
        style.TouchExtraPadding.x = 5.0f;
        style.TouchExtraPadding.y = 5.0f;
        ImVec4 defaultBlue(0.0f, 0.5f, 1.0f, 0.7f);
        style.Colors[ImGuiCol_TitleBg] = defaultBlue;
        style.Colors[ImGuiCol_TitleBgCollapsed] = defaultBlue;
        style.Colors[ImGuiCol_SliderGrab] = defaultBlue;
        style.Colors[ImGuiCol_SliderGrabActive] = defaultBlue;
        style.Colors[ImGuiCol_Button] = defaultBlue;
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.0f, 0.5f, 1.0f, 0.3f);
        style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.0f, 0.5f, 1.0f, 1.0f);
        style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.0f, 0.5f, 1.0f, 0.5f);
        style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.0f, 0.5f, 1.0f, 1.0f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.0f, 0.5f, 1.0f, 0.3f);
        style.Colors[ImGuiCol_Header] = defaultBlue;
        style.Colors[ImGuiCol_HeaderHovered] = defaultBlue;
        style.Colors[ImGuiCol_HeaderActive] = defaultBlue;

        this->shaders[Normals] = Gfx::CreateResource(NormalsShader::Setup());
        this->shaders[Lambert] = Gfx::CreateResource(LambertShader::Setup());
        this->shaders[Phong]   = Gfx::CreateResource(PhongShader::Setup());


        this->makeDrawStates();

        //this->createModel(0, glm::vec3(0, 0, 0));
        this->activeModel = 0;

        // setup projection and view matrices
        const float fbWidth = (const float)Gfx::DisplayAttrs().FramebufferWidth;
        const float fbHeight = (const float)Gfx::DisplayAttrs().FramebufferHeight;
        this->proj = glm::perspectiveFov(glm::radians(60.0f), fbWidth, fbHeight, 0.01f, 100.0f);

        // non-standard camera settings when switching objects
        // teapot:
        this->cameraSettings[2].dist = 0.8f;
        this->cameraSettings[2].height = 0.0f;

        gm = GraphicsManager();
        gm.loadResources();


        try
        {
            py::exec(R"(
                from example import *
                import random

                tiger1      = createModel(0, vec3(0,0,0))
                opelblitz   = createModel(1, vec3(4,0,0))
                tiger2      = createModel(0, vec3(-4,0,0))
                teapot      = createModel(2, vec3(0,5,0))

                setPosition(tiger2,      vec3(random.uniform(-5,5), random.uniform(-5,5), random.uniform(-5,5)))
                setPosition(opelblitz,   vec3(random.uniform(-5,5), random.uniform(-5,5), random.uniform(-5,5)))
            )");
        }
        catch (std::exception e)
        {
            fprintf(stderr, "%s\n", e.what());
        }

        return App::OnInit();
    }
    AppState::Code OnRunning() 
    {
        this->frameCount++;
        this->handleInput();
        this->updateCamera();
        this->updateLight();

        Gfx::BeginPass();
        this->drawUI();
        DrawState drawState;
        int size = MeshViewerApp::modelArray.Size();
        for (int i = 0; i < MeshViewerApp::modelArray.Size(); i++)
        {
            Model& m = MeshViewerApp::modelArray[i];
            drawState.Mesh[0] = m.mesh;
            if (!m.drawState.Pipeline.IsValid())
            {
                this->reAssign(m);   
            }
            else
            {
                Gfx::ApplyDrawState(m.drawState);
            }
            for (int j = 0; j < 3; j++)
            {
                this->applyVariables(i, j);
            }
            for (int j = 0; j < 3; j++)
            {
                Gfx::Draw(j);
            }
        }
        ImGui::Render();
        Gfx::EndPass();
        Gfx::CommitFrame();
        return Gfx::QuitRequested() ? AppState::Cleanup : AppState::Running;
    }
    AppState::Code OnCleanup()
    {
        IMUI::Discard();
        Input::Discard();
        Gfx::Discard();
        IO::Discard();
        return App::OnCleanup();
    }

    static int createModel(int index, glm::vec3 position)
    {
        Model& m = MeshViewerApp::modelArray.Add(Model());
        m.transform = glm::translate(glm::mat4(), position);
        m.meshIndex = index;

        return MeshViewerApp::modelArray.Size()-1;
    }
    static void setPosition(int index, glm::vec3 position)
    {
        MeshViewerApp::modelArray[index].transform = glm::translate(glm::mat4(), position);
    }
    static Array<Model> modelArray;
    static Array<Mesh> meshArray;
    GraphicsManager gm;

private:
    void handleInput()
    {
        // rotate camera with mouse if not UI-dragging
        if (Input::TouchpadAttached()) {
            if (!ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow)) {
                if (Input::TouchPanningStarted()) {
                    this->camera.startOrbital = this->camera.orbital;
                }
                if (Input::TouchPanning()) {
                    glm::vec2 diff = (Input::TouchPosition(0) - Input::TouchStartPosition(0)) * 0.01f;
                    this->camera.orbital.y = this->camera.startOrbital.y - diff.x;
                    this->camera.orbital.x = glm::clamp(this->camera.startOrbital.x + diff.y, glm::radians(minLatitude), glm::radians(maxLatitude));
                }
                if (Input::TouchPinchingStarted()) {
                    this->camera.startDistance = this->camera.dist;
                }
                if (Input::TouchPinching()) {
                    float startDist = glm::length(glm::vec2(Input::TouchStartPosition(1) - Input::TouchStartPosition(0)));
                    float curDist = glm::length(glm::vec2(Input::TouchPosition(1) - Input::TouchPosition(0)));
                    this->camera.dist = glm::clamp(this->camera.startDistance - (curDist - startDist) * 0.01f, minCamDist, maxCamDist);
                }
            }
        }
        if (Input::MouseAttached()) {
            if (this->dragging) {
                if (Input::MouseButtonPressed(MouseButton::Left)) {
                    this->camera.orbital.y -= Input::MouseMovement().x * 0.01f;
                    this->camera.orbital.x = glm::clamp(
                        this->camera.orbital.x + Input::MouseMovement().y * 0.01f,
                        glm::radians(minLatitude),
                        glm::radians(maxLatitude));
                }
            }
            this->camera.dist = glm::clamp(this->camera.dist + Input::MouseScroll().y * 0.1f, minCamDist, maxCamDist);
        }
    }
    void updateCamera()
    {
        if (this->camAutoOrbit) {
            this->camera.orbital.y += 0.01f;
            if (this->camera.orbital.y > glm::radians(360.0f)) {
                this->camera.orbital.y = 0.0f;
            }
        }
        this->eyePos = glm::euclidean(this->camera.orbital) * this->camera.dist;
        glm::vec3 poi = glm::vec3(0.0f, this->camera.height, 0.0f);
        this->view = glm::lookAt(this->eyePos + poi, poi, glm::vec3(0.0f, 1.0f, 0.0f));
        this->modelViewProj = this->proj * this->view;
    }
    void updateLight()
    {
        if (this->lightAutoOrbit) {
            this->lightOrbital.y += 0.01f;
            if (this->lightOrbital.y > glm::radians(360.0f)) {
                this->lightOrbital.y = 0.0f;
            }
        }
        this->lightDir = glm::euclidean(this->lightOrbital);
    }
    void drawUI()
    {
        const char* state;
        switch (Gfx::QueryResourceInfo(this->meshArray[this->modelArray[this->activeModel].meshIndex].drawState.Mesh[0]).State) {
        case ResourceState::Valid: state = "Loaded"; break;
        case ResourceState::Failed: state = "Load Failed"; break;
        case ResourceState::Pending: state = "Loading..."; break;
        default: state = "Invalid"; break;
        }

        IMUI::NewFrame();
        ImGui::SetNextWindowSize(ImVec2(240, 300));
        ImGui::SetNextWindowBgAlpha(0.25f);
        ImGui::Begin("Mesh Viewer", nullptr, 0);
        ImGui::PushItemWidth(130.0f);

        ImGui::RadioButton("M 1", &this->activeModel, 0); ImGui::SameLine();
        ImGui::RadioButton("M 2", &this->activeModel, 1); ImGui::SameLine();
        ImGui::RadioButton("M 3", &this->activeModel, 2);

        if (ImGui::Combo("##mesh", (int*)&this->modelArray[this->activeModel].meshIndex, this->meshNames, numMeshes)) {
            this->modelArray[this->activeModel].drawState = this->meshArray[this->modelArray[this->activeModel].meshIndex].drawState;
            this->modelArray[this->activeModel].numberOfMaterials = this->meshArray[this->modelArray[this->activeModel].meshIndex].numberOfMaterials;
        }
        ImGui::Text("state: %s\n", state);
        if (this->curMeshSetup.NumPrimitiveGroups() > 0) {
            ImGui::Text("primitive groups:\n");
            for (int i = 0; i < this->curMeshSetup.NumPrimitiveGroups(); i++) {
                ImGui::Text("%d: %d triangles\n", i, this->curMeshSetup.PrimitiveGroup(i).NumElements / 3);
            }
        }
        if (ImGui::CollapsingHeader("Camera")) {
            ImGui::SliderFloat("Dist##cam", &this->camera.dist, minCamDist, maxCamDist);
            ImGui::SliderFloat("Height##cam", &this->camera.height, minCamHeight, maxCamHeight);
            ImGui::SliderAngle("Long##cam", &this->camera.orbital.y, 0.0f, 360.0f);
            ImGui::SliderAngle("Lat##cam", &this->camera.orbital.x, minLatitude, maxLatitude);
            ImGui::Checkbox("Auto Orbit##cam", &this->camAutoOrbit);
            if (ImGui::Button("Reset##cam")) {
                this->camera.dist = 8.0f;
                this->camera.height = 1.0f;
                this->camera.orbital = glm::vec2(0.0f, 0.0f);
                this->camAutoOrbit = false;
            }
        }
        if (ImGui::CollapsingHeader("Light")) {
            ImGui::SliderAngle("Long##light", &this->lightOrbital.y, 0.0f, 360.0f);
            ImGui::SliderAngle("Lat##light", &this->lightOrbital.x, minLatitude, maxLatitude);
            ImGui::ColorEdit3("Color##light", &this->lightColor.x);
            ImGui::SliderFloat("Intensity##light", &this->lightIntensity, 0.0f, 5.0f);
            ImGui::Checkbox("Auto Orbit##light", &this->lightAutoOrbit);
            ImGui::Checkbox("Gamma Correct##light", &this->gammaCorrect);
            if (ImGui::Button("Reset##light")) {
                this->lightOrbital = glm::vec2(glm::radians(25.0f), 0.0f);
                this->lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
                this->lightIntensity = 1.0f;
                this->lightAutoOrbit = false;
            }
        }
        for (int i = 0; i < this->modelArray[this->activeModel].numberOfMaterials; i++) {
            this->strBuilder.Format(32, "Material %d", i);
            if (ImGui::CollapsingHeader(this->strBuilder.AsCStr())) {
                this->strBuilder.Format(32, "shader##mat%d", i);
                if (ImGui::Combo(strBuilder.AsCStr(), &this->modelArray[this->activeModel].materials[i].shaderIndex, this->shaderNames, numShaders)) {
                    this->createMaterials();
                }
                if ((Lambert == this->modelArray[this->activeModel].materials[i].shaderIndex) || (Phong == this->modelArray[this->activeModel].materials[i].shaderIndex)) {
                    this->strBuilder.Format(32, "diffuse##%d", i);
                    ImGui::ColorEdit3(this->strBuilder.AsCStr(), &this->modelArray[this->activeModel].materials[i].diffuse.x);
                }
                if (Phong == this->modelArray[this->activeModel].materials[i].shaderIndex) {
                    this->strBuilder.Format(32, "specular##%d", i);
                    ImGui::ColorEdit3(this->strBuilder.AsCStr(), &this->modelArray[this->activeModel].materials[i].specular.x);
                    this->strBuilder.Format(32, "power##%d", i);
                    ImGui::SliderFloat(this->strBuilder.AsCStr(), &this->modelArray[this->activeModel].materials[i].specPower, 1.0f, 512.0f);
                }
            }
        }
        ImGui::PopItemWidth();
        ImGui::End();
    }

    void createMaterials()
    {
        o_assert_dbg(this->mesh.IsValid());
        if (this->curMaterialLabel.IsValid()) {
            Gfx::DestroyResources(this->curMaterialLabel);
        }
        this->curMaterialLabel = Gfx::PushResourceLabel();
        Model m = this->modelArray[this->activeModel];
        for (int i = 0; i < this->modelArray[this->activeModel].numberOfMaterials; i++) {
            auto ps = PipelineSetup::FromLayoutAndShader(this->curMeshSetup.Layout, this->shaders[m.materials[i].shaderIndex]);
            ps.DepthStencilState.DepthWriteEnabled = true;
            ps.DepthStencilState.DepthCmpFunc = CompareFunc::LessEqual;
            ps.RasterizerState.CullFaceEnabled = true;
            ps.RasterizerState.SampleCount = 4;
            m.materials[i].pipeline = Gfx::CreateResource(ps);
        }
        Gfx::PopResourceLabel();
    }

    //void loadMesh(const char* path)
    //{
    //    // unload current mesh
    //    if (this->curMeshLabel.IsValid())
    //    {
    //        Gfx::DestroyResources(this->curMeshLabel);
    //        this->curMeshSetup = MeshSetup();
    //    }
    //    // load new mesh, use 'onloaded' callback to capture the mesh setup
    //    // object of the loaded mesh
    //    this->numMaterials = 0;
    //    this->curMeshLabel = Gfx::PushResourceLabel();
    //    this->mesh = Gfx::LoadResource(MeshLoader::Create(MeshSetup::FromFile(path), [this](MeshSetup& setup)
    //        {
    //            this->curMeshSetup = setup;
    //            this->numMaterials = setup.NumPrimitiveGroups();
    //            this->createMaterials();
    //        }));
    //    Gfx::PopResourceLabel();
    //}

    void applyVariables(int modelIndex, int materialIndex)
    {
        Model model = MeshViewerApp::modelArray[modelIndex];

        switch (model.materials[modelIndex].shaderIndex) {
        case Normals:
            // Normals shader
        {
            NormalsShader::vsParams vsParams;
            vsParams.mvp = this->modelViewProj * model.transform;
            Gfx::ApplyUniformBlock(vsParams);
        }
        break;
        case Lambert:
            // Lambert shader
        {
            LambertShader::vsParams vsParams;
            vsParams.mvp = this->modelViewProj * model.transform;
            vsParams.model = this->model * model.transform;
            Gfx::ApplyUniformBlock(vsParams);

            LambertShader::fsParams fsParams;
            fsParams.lightColor = this->lightColor * this->lightIntensity;
            fsParams.lightDir = this->lightDir;
            fsParams.matDiffuse = model.materials[modelIndex].diffuse;
            fsParams.gammaCorrect = this->gammaCorrect ? 1.0f : 0.0f;
            Gfx::ApplyUniformBlock(fsParams);
        }
        break;
        case Phong:
            // Phong shader
        {
            PhongShader::vsParams vsParams;
            vsParams.mvp = this->modelViewProj * model.transform;
            vsParams.model = this->model * model.transform;
            Gfx::ApplyUniformBlock(vsParams);

            PhongShader::fsParams fsParams;
            fsParams.eyePos = this->eyePos;
            fsParams.lightColor = this->lightColor * this->lightIntensity;
            fsParams.lightDir = this->lightDir;
            fsParams.matDiffuse = model.materials[modelIndex].diffuse;
            fsParams.matSpecular = model.materials[modelIndex].specular;
            fsParams.matSpecularPower = model.materials[modelIndex].specPower;
            fsParams.gammaCorrect = this->gammaCorrect ? 1.0f : 0.0f;
            Gfx::ApplyUniformBlock(fsParams);
        }
        break;

        default:
            o_error("Unknown shader index, FIXME!");
            break;
        }
    }

    static void makeDrawStates()
    {
        for (int i = 0; i < MeshViewerApp::numMeshes; i++)
        {
            Mesh& mesh = MeshViewerApp::meshArray.Add(Mesh());
            mesh.drawState.Mesh[0] = Gfx::LoadResource(MeshLoader::Create(MeshSetup::FromFile(MeshViewerApp::meshPaths[i]), [&mesh](MeshSetup& setup) {
                mesh.numberOfMaterials = setup.NumPrimitiveGroups();
                mesh.setup = setup;
                auto ps = PipelineSetup::FromLayoutAndShader(setup.Layout, Gfx::CreateResource(PhongShader::Setup()));
                ps.DepthStencilState.DepthWriteEnabled = true;
                ps.DepthStencilState.DepthCmpFunc = CompareFunc::LessEqual;
                ps.RasterizerState.CullFaceEnabled = true;
                ps.RasterizerState.SampleCount = 4;
                mesh.drawState.Pipeline = Gfx::CreateResource(ps);
            }));
        }
    }
    static void makeDrawState(int meshIndex)
    {
        Mesh& mesh = MeshViewerApp::meshArray[meshIndex];
        mesh.drawState.Mesh[0] = Gfx::LoadResource(MeshLoader::Create(MeshSetup::FromFile(MeshViewerApp::meshPaths[meshIndex]), [&mesh](MeshSetup& setup) {
            auto ps = PipelineSetup::FromLayoutAndShader(setup.Layout, Gfx::CreateResource(PhongShader::Setup()));
            ps.DepthStencilState.DepthWriteEnabled = true;
            ps.DepthStencilState.DepthCmpFunc = CompareFunc::LessEqual;
            ps.RasterizerState.CullFaceEnabled = true;
            ps.RasterizerState.SampleCount = 4;
            mesh.numberOfMaterials = setup.NumPrimitiveGroups();
            mesh.drawState.Pipeline = Gfx::CreateResource(ps);
            }));
    }
    void reAssign(Model& model)
    {
        if (MeshViewerApp::meshArray[model.meshIndex].drawState.Pipeline.IsValid())
        {
            model.drawState = MeshViewerApp::meshArray[model.meshIndex].drawState;
            model.numberOfMaterials = MeshViewerApp::meshArray[model.meshIndex].numberOfMaterials;
        }
        else
        {
            this->makeDrawState(model.meshIndex);
        }
    }

    int selectedID;
    char* buf = new char[512];

    int frameCount = 0;

    ResourceLabel curMeshLabel;
    MeshSetup curMeshSetup;
    Id mesh;
    glm::vec3 eyePos;
    glm::mat4 view;
    glm::mat4 proj;
    glm::mat4 model;
    glm::mat4 modelViewProj;

    int activeModel = -1;

    int curMeshIndex = 0;
    static const int numMeshes = 3;
    static const char* meshNames[numMeshes];
    static const char* meshPaths[numMeshes];
    static const int numShaders = 3;
    static const char* shaderNames[numShaders];
    enum {
        Normals = 0,
        Lambert,
        Phong
    };
    Id shaders[numShaders];
    ResourceLabel curMaterialLabel;
    bool gammaCorrect = true;

    struct CameraSetting {
        float dist = 8.0f;
        glm::vec2 orbital = glm::vec2(glm::radians(25.0f), 0.0f);
        float height = 1.0f;
        glm::vec2 startOrbital;
        float startDistance = 0.0f;
    } camera;
    bool camAutoOrbit = false;
    struct CameraSetting cameraSettings[numMeshes];

    glm::vec2 lightOrbital = glm::vec2(glm::radians(25.0f), 0.0f);
    glm::vec3 lightDir;
    glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    float lightIntensity = 1.0f;
    bool lightAutoOrbit = false;
    bool dragging = false;

    StringBuilder strBuilder;

    const float minCamDist = 0.5f;
    const float maxCamDist = 20.0f;
    const float minLatitude = -85.0f;
    const float maxLatitude = 85.0f;
    const float minCamHeight = -2.0f;
    const float maxCamHeight = 5.0f;
};

Array<Model> MeshViewerApp::modelArray;
Array<Mesh> MeshViewerApp::meshArray;

OryolMain(MeshViewerApp);

PYBIND11_EMBEDDED_MODULE(example, m)
{
    m.doc() = "pybind11 example plugin";

    py::class_<glm::vec3>(m, "vec3")
        .def(py::init<float, float, float>());
    py::class_<glm::vec4>(m, "vec4")
        .def(py::init<float, float, float, float>());

    m.def("createModel", &MeshViewerApp::createModel, py::return_value_policy::reference);
    m.def("setPosition", &MeshViewerApp::setPosition);
}

const char* MeshViewerApp::meshNames[numMeshes] = {
    "Tiger",
    "Blitz",
    "Teapot"
};
const char* MeshViewerApp::meshPaths[numMeshes] = {
    "root:tiger.omsh.txt",
    "root:opelblitz.omsh.txt",
    "root:teapot.omsh.txt"
};

const char* MeshViewerApp::shaderNames[numShaders] = {
    "Normals",
    "Lambert",
    "Phong"
};