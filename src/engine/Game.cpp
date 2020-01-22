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
 * \brief
 *
 */
void Game::init(){

}

/**
 * \fn input
 * \brief Manage the event in the main window
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
}

/**
 * \fn update
 * \brief Make rotate the different Object o the Y axis
 *
 */
void Game::update(){

    scene.getCube()->addRotation(0, 0.3f, 0);
    scene.getSquare()->addRotation(0,0.3f,0);

}

/**
 * \fn render
 * \brief Instantiate the Camera
 *
 */
void Game::render(){

    renderer.renderFractal(camera);
    renderer.renderScene(scene, camera);

}
