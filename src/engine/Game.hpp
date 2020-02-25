#ifndef PTUT_GAME_HPP
#define PTUT_GAME_HPP

#include "Shader.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

/**
 * \class Game
 *
 * In this class there are several functions that can be used in order to manage the Game
 */
class Game {
private:
    Renderer renderer;
    Camera camera;

    float lightAngle = 0;

public:
    Camera getCamera();

    void init();
    void input(Window& window);
    void update();
    void render(Window& window);
};

#endif //PTUT_GAME_HPP
