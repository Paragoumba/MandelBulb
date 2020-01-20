#include "GameEngine.hpp"

GameEngine::GameEngine() : game(), window(appName, 1920, 1080){

    game.init();

}

void GameEngine::loop(){

    timespec waitingTime{0, 0};
    long waitingTimeNano = (long) (1.0 / 60 * 1'000'000'000.0);
    int i = 0;
    double start = glfwGetTime();

    while (!window.shouldClose()){

        glClearColor(std::cos(glfwGetTime()), 255, std::sin(glfwGetTime()), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        auto loopStart = std::chrono::high_resolution_clock::now();

        if (window.getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS){

            window.close();

        }

        game.input(window);
        game.update();
        game.render();

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