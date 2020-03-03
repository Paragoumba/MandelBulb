#ifndef PTUT_GAMEENGINE_HPP
#define PTUT_GAMEENGINE_HPP

#include "Window.hpp"
#include "Game.hpp"

/**
 * \class GameEngine
 *
 * In this class we instantiate everything, and we control the main loop
 */
class GameEngine {
private:
    const char* appName = "MandelBulb Renderer";
    const char* separator = " - ";

    Window window;
    Game game;

public:
    GameEngine();

    void loop();
    int takeScreenshot(const char*);
};

#endif //PTUT_GAMEENGINE_HPP
