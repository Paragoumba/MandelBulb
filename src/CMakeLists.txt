add_executable(MandelBulb main.cpp ../lib/glad.c engine/Shader.cpp engine/Transformation.cpp engine/Object.cpp
        engine/Camera.cpp engine/Renderer.cpp engine/GameEngine.cpp engine/Window.cpp engine/Game.cpp engine/Scene.cpp
        engine/Mesh.cpp engine/Material.cpp engine/Texture.cpp engine/exceptions/Exception.cpp engine/Utils.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lglfw -lGL -ldl")