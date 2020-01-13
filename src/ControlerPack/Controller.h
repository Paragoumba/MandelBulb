//
// Created by daniel on 10/01/2020.
//

#include "../ModelPack/Data.hpp"

#ifndef MANDELBULB_CONTROLLER_H
#define MANDELBULB_CONTROLLER_H


class Controller {
protected:
    Data data;

public:
    Controller(Data data);
    ~Controller();
    Data getData();
    virtual void compute() = 0;
};


#endif //MANDELBULB_CONTROLLER_H
