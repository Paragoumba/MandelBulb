#ifndef PTUT_GAME_HPP
#define PTUT_GAME_HPP

#include "Shader.hpp"
#include "Scene.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

/**
 * \class Game
 *
 * In this class there are serval functions that can be used in order to managed the Game
 */
class Game {
private:
    Renderer renderer;
    Scene scene;
    Camera camera;

    float lightAngle = 0;

public:
    void init();
    void input(Window& window);
    void update();
    void render(Window& window);
};

#endif //PTUT_GAME_HPP
