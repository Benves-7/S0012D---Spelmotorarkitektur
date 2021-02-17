fips_begin_app(MeshViewer windowed)
    fips_vs_warning_level(3)
    fips_files(
	MeshViewer.cc
	config.json
	GraphicsManager.h
	BaseComponent.h
	GameEntity.h
	GameEntityManager.h
	)
    oryol_shader(shaders.shd)
    fips_deps(Gfx Assets LocalFS Input IMUI ${PYTHON_LIBRARIES} cjson)
    oryol_add_web_sample(MeshViewer "Load and render .omsh mesh files" "emscripten" MeshViewer.jpg "MeshViewer/MeshViewer.cc")
fips_end_app()
