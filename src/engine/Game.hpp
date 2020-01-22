#ifndef PTUT_GAME_HPP
#define PTUT_GAME_HPP

#include "Shader.hpp"
#include "Scene.hpp"
#include "HUD.hpp"
#include "Renderer.hpp"
#include "WindowOpenGL.hpp"

class Game {
private:
    Renderer renderer;
    Scene scene;
    HUD hud;
    Camera camera;

public:
    void init();
    void input(WindowOpenGL& window);
    void update();
    void render();

};

#endif //PTUT_GAME_HPP
