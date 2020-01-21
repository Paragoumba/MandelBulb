#ifndef PTUT_GAME_HPP
#define PTUT_GAME_HPP

#include "Shader.hpp"
#include "Scene.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

class Game {
private:
    Renderer renderer;
    Scene scene;
    Camera camera;

public:
    void init();
    void input(Window& window);
    void update();
    void render();
};

#endif //PTUT_GAME_HPP
