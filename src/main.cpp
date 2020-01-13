#include <cstdlib>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "ModelPack/Data.hpp"
#include "engine/GameEngine.hpp"
#include "ModelPack/Fractal2D.hpp"
#include "ModelPack/Fractal3D.hpp"
#include "ModelPack/Loader.hpp"


int main(){


    /*-------DATA -------*/
    Data data;
    Loader loader;
    loader.load(data,"/home/val-duss/Documents/ptut/val/mandelbulb/data/data.csv");
    data.printListOfFractal();
    /*GameEngine graphicsEngine;
   graphicsEngine.loop();*/


    return EXIT_SUCCESS;

}