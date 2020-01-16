#include "Game.hpp"

void Game::init(){

}

void Game::input(){

}

void Game::update(){

    scene.getCube()->addRotation(0, 0.3f, 0);

}

void Game::render(){

    renderer.renderScene(scene, camera);
    renderer.renderHUD(hud);

}
