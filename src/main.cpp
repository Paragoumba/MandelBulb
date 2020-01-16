#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdlib>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "engine/GameEngine.hpp"

int main(){

    GameEngine gameEngine;

    gameEngine.loop();

    return EXIT_SUCCESS;

}