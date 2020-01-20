#ifndef MANDELBULB_CONTROLLER_H
#define MANDELBULB_CONTROLLER_H

#include "../ModelPack/Data.hpp"

class Controller {
protected:
    Data data;

public:
    explicit Controller(Data& data);
    ~Controller();
    Data getData();
    virtual void compute() = 0;

};

#endif //MANDELBULB_CONTROLLER_H
