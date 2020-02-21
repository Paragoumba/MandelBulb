project(MandelBulb)

set(SOURCE_FILES main.cpp ../lib/glad.c ../lib/imgui/imgui.cpp ../lib/imgui/imgui_draw.cpp ../lib/imgui/imgui_widgets.cpp
        ../lib/imgui/imgui_impl_glfw.cpp ../lib/imgui/imgui_impl_opengl3.cpp engine/Shader.cpp engine/Transformation.cpp engine/Object.cpp
        engine/Camera.cpp engine/Renderer.cpp engine/GameEngine.cpp engine/Window.cpp engine/Game.cpp engine/Scene.cpp
        engine/Mesh.cpp engine/Material.cpp engine/Texture.cpp engine/exceptions/Exception.cpp engine/Utils.cpp engine/FractalParams.cpp)

add_executable(MandelBulb ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lglfw -lGL -ldl -std=c++17")