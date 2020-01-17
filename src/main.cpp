#include <cstdlib>


#include "engine/GameEngine.hpp"
#include "ModelPack/Data.hpp"
#include "ModelPack/DataManager.hpp"


int main(){


    /*--------DATA-------*/
    Data data;
    Loader loader;
    loader.load(data,"../../data/data.csv");
    data.printListOfFractal();
    /*--------VIEW-------*/

    /*GameEngine graphicsEngine;
    graphicsEngine.loop();*/


    return EXIT_SUCCESS;

}