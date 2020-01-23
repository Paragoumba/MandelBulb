project(MandelBulb)

set(SOURCE_FILES main.cpp ../lib/glad.c engine/Shader.cpp engine/Transformation.cpp engine/Object.cpp
        engine/Camera.cpp engine/Renderer.cpp engine/GameEngine.cpp engine/WindowOpenGL.cpp engine/Game.cpp engine/Scene.cpp
        engine/Mesh.cpp engine/Material.cpp engine/Texture.cpp engine/exceptions/Exception.cpp ViewPack/Application.hpp ViewPack/Application.cpp
        ViewPack/MocWindow.cpp ViewPack/Window.cpp engine/exceptions/MaterialException.hpp)

add_executable(MandelBulb ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lGL -ldl -lglfw")

find_package(Qt5Widgets REQUIRED)
target_link_libraries(MandelBulb Qt5::Widgets)