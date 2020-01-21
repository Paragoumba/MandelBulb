#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdlib>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "engine/GameEngine.hpp"

int main(){

    try {

        GameEngine gameEngine;

        gameEngine.loop();

    } catch (const std::exception& e){

        std::cerr << e.what() << std::endl;
        std::cerr << "Exiting due to a fatal unrecoverable error." << std::endl;
        return EXIT_FAILURE;

    } catch (...){

        std::cerr << "Exiting due to unknown fatal unrecoverable error." << std::endl;
        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

}