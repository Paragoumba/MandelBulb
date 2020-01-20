project(MandelBulb)
add_executable(MandelBulb main.cpp ../lib/glad.c
        engine/Camera.cpp engine/Game.cpp engine/GameEngine.cpp engine/HUD.cpp engine/Material.cpp engine/Mesh.cpp
        engine/Object.cpp engine/Renderer.cpp engine/Scene.cpp engine/Shader.cpp engine/Texture.cpp engine/Transformation.cpp engine/Window.cpp
        ModelPack/Data.cpp ModelPack/Fractal.cpp ModelPack/Fractal2D.cpp ModelPack/Fractal3D.cpp
        ModelPack/DataManager.cpp
        ControlerPack/Controller.cpp ControlerPack/DefaultController.cpp ControlerPack/EditController.cpp
        ObserverPack/Observable.cpp ObserverPack/Observer.cpp
        ViewPack/ViewWindow.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ldl -lglfw -lGL")