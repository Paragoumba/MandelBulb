/**
 * \file GameEngine.cpp
 * \brief The main loop of the program is located here
 * \author DUSSERVAIX V., OVEJERO D., TESSON L., VIOLLET R.
 * \date 22 January 2020
 *
 * In this class we instantiate everything, and we control the main loop
 */
#include <chrono>

#include "GameEngine.hpp"

#define FPS 60

/**
 * Constructor of GameEngine, Instantiate game, window
 *
 */
GameEngine::GameEngine() : game(), window(appName, 1920, 1080){

    game.init();

}

/**
 * Manage the main loop
 *
 */
void GameEngine::loop(){

    timespec waitingTime{0, 0};
    long waitingTimeNano = (long) (1.0 / FPS * 1'000'000'000.0);
    int i = 0;
    double start = glfwGetTime();

    while (!window.shouldClose()){

        window.setColor(std::cos(glfwGetTime()), 255, std::sin(glfwGetTime()), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        auto loopStart = std::chrono::high_resolution_clock::now();

        if (window.getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS){

            window.close();

        }

        game.input(window);
        game.update();
        game.render(window);

        waitingTime.tv_nsec = waitingTimeNano -
                std::chrono::duration_cast<std::chrono::nanoseconds>(
                        std::chrono::high_resolution_clock::now() - loopStart
                        ).count();
        nanosleep(&waitingTime, nullptr);

        if (glfwGetTime() - start >= 1){

            window.setTitle((std::string(appName) + separator + std::to_string(i) + "FPS").c_str());
            start = glfwGetTime();
            i = 0;

        }

        window.swapBuffers();
        glfwPollEvents();

        ++i;

    }

}