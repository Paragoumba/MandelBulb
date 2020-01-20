#include "GameEngine.hpp"

GameEngine::GameEngine() : window("Mandelbulb Renderer", 1920, 1080){

    game.init();

}

void GameEngine::loop(){

    while (!window.shouldClose()){

        if (window.getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS){

            window.close();

        }

        game.input();
        game.update();
        game.render();

        glfwPollEvents();
        window.swapBuffers();

    }

}