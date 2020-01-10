#include <cstdlib>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "ModelPack/Data.hpp"
#include "ModelPack/Fractal2D.hpp"


int main(){

    //GameEngine graphicsEngine;

    //graphicsEngine.loop();
    Data data;
    data.AddFractal(FractalPtr(new Fractal2D("jqjsh")));
    data.printListOfFractal();

    return EXIT_SUCCESS;

}