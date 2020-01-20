#ifndef PTUT_GAMEENGINE_HPP
#define PTUT_GAMEENGINE_HPP

#include "Window.hpp"
#include "Game.hpp"

class GameEngine {
private:
    const char* appName = "MandelBulb Renderer";
    const char* separator = " - ";

    Window window;
    Game game;

public:
    GameEngine();

    void loop();
};

#endif //PTUT_GAMEENGINE_HPP
