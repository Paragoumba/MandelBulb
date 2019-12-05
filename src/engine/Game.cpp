#include "Game.hpp"

void Game::init(){

}

void Game::input(){

}

void Game::update(){

}

void Game::render(){

    renderer.renderScene(scene, camera);
    renderer.renderHUD(hud);

}
