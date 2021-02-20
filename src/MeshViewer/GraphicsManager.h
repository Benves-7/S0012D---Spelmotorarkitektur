#pragma once
#include "cJSON.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace Oryol;
using namespace glm;
using namespace std;

struct graphicsObject
{
	int index;
	char* name;
	char* path;
	mat4 position;
	Id mesh;
	DrawState drawState;
	int numberofMaterials;
	enum { 
		Normals = 0,
		Lambert,
		Phong
	};
	struct Material
	{
		int shaderIndex;
		Id pipeline;
		vec4 diffuse;
		vec4 specular;
		float specPower;
	} material;
};
class GraphicsManager {
public:
	void loadResources()
	{
		const string s = "config.json";
		ifstream ifs;
		ifs.open(s, ifstream::in);

		string content((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
		printf(content.c_str(), "\n");
		cJSON* root = cJSON_Parse(content.c_str());
		cJSON* graphicsEntities = cJSON_GetObjectItem(root, "graphicsEntities");
		for (int i = 0; i < cJSON_GetArraySize(graphicsEntities); i++)
		{
			cJSON* graphicsEntity = cJSON_GetArrayItem(graphicsEntities, i);
			char* name = cJSON_GetObjectItem(graphicsEntity, "name")->valuestring;
			char* path = cJSON_GetObjectItem(graphicsEntity, "path")->valuestring;
			char* shader = cJSON_GetObjectItem(graphicsEntity, "shader")->valuestring;

			cJSON* material = cJSON_GetObjectItem(graphicsEntity, "material");
			cJSON* diffuseArray = cJSON_GetObjectItem(material, "diffuse"); 
			vec4 diffuse = vec4(
				cJSON_GetArrayItem(diffuseArray, 0)->valuedouble,
				cJSON_GetArrayItem(diffuseArray, 1)->valuedouble,
				cJSON_GetArrayItem(diffuseArray, 2)->valuedouble,
				cJSON_GetArrayItem(diffuseArray, 3)->valuedouble
			);
			cJSON* specularArray = cJSON_GetObjectItem(material, "specular");
			vec4 specular = vec4(
				cJSON_GetArrayItem(specularArray, 0)->valuedouble,
				cJSON_GetArrayItem(specularArray, 1)->valuedouble,
				cJSON_GetArrayItem(specularArray, 2)->valuedouble,
				cJSON_GetArrayItem(specularArray, 3)->valuedouble
			);
			float specularPower = (float)cJSON_GetObjectItem(material, "specularPower")->valuedouble;
			this->generateGraphicsObject(diffuse, specular, specularPower, i, path, name);
		}

	}
	Array<graphicsObject> getGraphicsObjectArray()
	{
		return graphicsObjectArray;
	}
	void generateNewDrawState(graphicsObject& object)
	{
		object.drawState.Mesh[0] = Gfx::LoadResource(MeshLoader::Create(MeshSetup::FromFile(object.path),
			[&object](MeshSetup& setup) {
				auto ps = PipelineSetup::FromLayoutAndShader(setup.Layout, Gfx::CreateResource(PhongShader::Setup()));
				ps.DepthStencilState.DepthWriteEnabled = true;
				ps.DepthStencilState.DepthCmpFunc = CompareFunc::LessEqual;
				ps.RasterizerState.CullFaceEnabled = true;
				ps.RasterizerState.SampleCount = 4;
				object.numberofMaterials = setup.NumPrimitiveGroups();
				object.drawState.Pipeline = Gfx::CreateResource(ps);
			}));
	}

private:
	Array<graphicsObject> graphicsObjectArray;
	void generateGraphicsObject(vec4 diffuse, vec4 specular, float specularPower, int meshIndex, char* path, char* name)
	{
		graphicsObject& object = this->graphicsObjectArray.Add(graphicsObject());
		object.name = name;
		object.path = path;
		object.position = mat4();
		object.index = meshIndex;

		object.material.diffuse = diffuse;
		object.material.specular = specular;
		object.material.specPower = specularPower;

		object.drawState.Mesh[0] = Gfx::LoadResource(MeshLoader::Create(MeshSetup::FromFile(path),
			[&object](MeshSetup& setup) {
				auto ps = PipelineSetup::FromLayoutAndShader(setup.Layout, Gfx::CreateResource(PhongShader::Setup()));
				ps.DepthStencilState.DepthWriteEnabled = true;
				ps.DepthStencilState.DepthCmpFunc = CompareFunc::LessEqual;
				ps.RasterizerState.CullFaceEnabled = true;
				ps.RasterizerState.SampleCount = 4;
				object.numberofMaterials = setup.NumPrimitiveGroups();
				object.drawState.Pipeline = Gfx::CreateResource(ps);
			}));
	}
};