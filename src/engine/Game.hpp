#ifndef PTUT_GAME_HPP
#define PTUT_GAME_HPP

#include "Shader.hpp"
#include "Scene.hpp"
#include "HUD.hpp"
#include "Renderer.hpp"

class Game {
private:
    Renderer renderer;
    Scene scene;
    HUD hud;
    Camera camera;

public:
    static void init();
    static void input();
    static void update();
    void render();

};

#endif //PTUT_GAME_HPP
