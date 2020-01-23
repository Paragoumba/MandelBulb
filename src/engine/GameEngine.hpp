#ifndef PTUT_GAMEENGINE_HPP
#define PTUT_GAMEENGINE_HPP

#include <chrono>

#include "WindowOpenGL.hpp"
#include "Game.hpp"

class GameEngine {
private:
    const char* appName = "MandelBulb Renderer";
    const char* separator = " - ";

    WindowOpenGL window;
    Game game;

public:
    GameEngine();

    void loop();

    ~GameEngine();

};

#endif //PTUT_GAMEENGINE_HPP
