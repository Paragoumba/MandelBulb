#include <chrono>

#include "GameEngine.hpp"

GameEngine::GameEngine() : window("Mandelbulb Renderer", 1920, 1080){

    game.init();

}

void GameEngine::loop(){

    timespec waitingTime{0, 0};
    long waitingTimeNano = (long) (1.0 / 60 * 1'000'000'000.0);

    while (!window.shouldClose()){

        glClearColor(std::cos(glfwGetTime()), 255, std::sin(glfwGetTime()), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        auto loopStart = std::chrono::high_resolution_clock::now();

        if (window.getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS){

            window.close();

        }

        game.input();
        game.update();
        game.render();

        waitingTime.tv_nsec = waitingTimeNano - std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - loopStart).count();
        nanosleep(&waitingTime, nullptr);

        window.swapBuffers();
        glfwPollEvents();

    }
}
