//
// Created by daniel on 10/01/2020.
//

#ifndef MANDELBULB_DEFAULTCONTROLLER_H
#define MANDELBULB_DEFAULTCONTROLLER_H


#include "Controller.h"

class DefaultController : public Controller{
private:
    //Menu Controlleur
public:
    DefaultController(Fractal _fractal);
    ~DefaultController();
    void compute() override;
};


#endif //MANDELBULB_DEFAULTCONTROLLER_H
