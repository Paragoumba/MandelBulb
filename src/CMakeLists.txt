project(MandelBulb)
add_executable(MandelBulb main.cpp ../lib/glad.c engine/Shader.cpp engine/Transformation.cpp engine/Object.cpp
        engine/Camera.cpp engine/Renderer.cpp engine/GameEngine.cpp engine/Game.cpp engine/Scene.cpp
        engine/HUD.cpp engine/Mesh.cpp engine/Material.cpp engine/Texture.cpp engine/Window.cpp engine/Window.hpp
        ModelPack/Data.cpp ModelPack/Data.hpp ModelPack/Fractal.cpp ModelPack/Fractal.hpp ModelPack/Fractal2D.cpp ModelPack/Fractal2D.hpp
        ModelPack/Fractal3D.cpp ModelPack/Fractal3D.hpp
        ViewPack/ViewWindow.cpp ViewPack/ViewWindow.hpp ModelPack/Loader.cpp ModelPack/Loader.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lglfw -lGL -ldl")