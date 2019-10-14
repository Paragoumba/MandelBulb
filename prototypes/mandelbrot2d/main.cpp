//
// Created by Paragoumba on 4/19/19.
//

#include <cstdlib>
#include <SDL2/SDL.h>

#include "MandelBrot.hpp"

int main(){

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;

    int nbthread = 4;

    MandelBrot mandelBrot;

    mandelBrot.setupControls();

    for (int i = 1; i <= nbthread; i++){

        mandelBrot.setupThread();

    }

    mandelBrot.display();

    return EXIT_SUCCESS;

}