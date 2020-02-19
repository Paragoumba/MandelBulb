#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdlib>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "engine/GameEngine.hpp"
#include "engine/Utils.hpp"

#include "engine/imguitest.hpp"

int main(int argc, char** argv){

    mainIMGUI(argc, argv);

    try {

        Utils::setExePath(argv[0]);

        GameEngine gameEngine;

        gameEngine.loop();

    } catch (const std::exception& e){

        std::cerr << e.what() << std::endl;
        std::cerr << "Exiting due to a fatal and unrecoverable error." << std::endl;
        return EXIT_FAILURE;

    } catch (...){

        std::cerr << "Exiting due to an unknown, fatal and unrecoverable error." << std::endl;
        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;

}