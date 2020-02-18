/**
 * \file Game.cpp
 * \brief Manager of the Game
 * \author DUSSERVAIX V., OVEJERO D., TESSON L., VIOLLET R.
 * \date 22 January 2020
 *
 * In this class there are serval functions that can be used in order to managed the Game
 */
#include "Game.hpp"

/**
 * \fn init
 *
 *
 */
void Game::init(){

    camera.setPosition(0, 0, 3);

}

/**
 * input
 * Manage the event in the main window
 *
 * @param window
 */
void Game::input(Window& window){

    if (window.getKey(GLFW_KEY_W) == GLFW_PRESS){

        camera.addPosition(0, 0, -0.1);

    }

    if (window.getKey(GLFW_KEY_A) == GLFW_PRESS){

        camera.addPosition(-0.1, 0, 0);

    }

    if (window.getKey(GLFW_KEY_S) == GLFW_PRESS){

        camera.addPosition(0, 0, 0.1);

    }

    if (window.getKey(GLFW_KEY_D) == GLFW_PRESS){

        camera.addPosition(0.1, 0, 0);

    }

    if (window.getKey(GLFW_KEY_X) == GLFW_PRESS){

        camera.addPosition(0, -0.1, 0);

    }

    if (window.getKey(GLFW_KEY_C) == GLFW_PRESS){

        camera.addPosition(0, 0.1, 0);

    }

    if (window.getKey(GLFW_KEY_UP) == GLFW_PRESS){

        camera.addRotation(-1, 0, 0);

    }

    if (window.getKey(GLFW_KEY_LEFT) == GLFW_PRESS){

        camera.addRotation(0, -1, 0);

    }

    if (window.getKey(GLFW_KEY_DOWN) == GLFW_PRESS){

        camera.addRotation(1, 0, 0);

    }

    if (window.getKey(GLFW_KEY_RIGHT) == GLFW_PRESS){

        camera.addRotation(0, 1, 0);

    }

    if (window.getKey(GLFW_KEY_KP_ADD) == GLFW_PRESS){

        lightAngle += 0.1f;

    }

    if (window.getKey(GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS){

        lightAngle -= 0.1f;

    }
}

/**
 * Make rotate the different Object o the Y axis
 *
 */
void Game::update(){

}

/**
 * Instantiate the Camera
 *
 */
void Game::render(Window& window){

    renderer.renderFractal(window, camera, lightAngle);

}
