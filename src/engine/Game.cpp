#include "Game.hpp"

void Game::init(){

}

void Game::input(WindowOpenGL& window){

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

void Game::update(){

    scene.getCube()->addRotation(0, 0.3f, 0);
    scene.getSquare()->addRotation(0,0.3f,0);

}

void Game::render(){

    renderer.renderScene(scene, camera);

}
