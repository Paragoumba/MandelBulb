//
// Created by daniel on 10/01/2020.
//

#include "Controller.h"

Controller::Controller(Fractale _fractal){
    fractal = _fractal;
}

Controller::~Controller() {}

void Controller::setFractal(Fractal _fractal) {
    fractal = _fractal;
}

Fractal getFractal(){
    return fractal;
}