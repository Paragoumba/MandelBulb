#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdlib>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "engine/GameEngine.hpp"
#include "ModelPack/Data.hpp"
#include "ModelPack/DataManager.hpp"

int main() {

    /*--------DATA-------*/
    Data data;
    //DataManager dataManager("../../data/data.csv");
    data.printListOfFractal();
    /*--------VIEW-------*/
    GameEngine graphicsEngine;
    graphicsEngine.loop();

    return EXIT_SUCCESS;

}