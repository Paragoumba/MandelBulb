#ifndef MANDELBULB_DEFAULTCONTROLLER_H
#define MANDELBULB_DEFAULTCONTROLLER_H

#include "Controller.h"

class DefaultController : public Controller {
private:
    //Menu Controlleur

public:
    DefaultController(Data data);
    ~DefaultController();
    void compute() override;

};

#endif //MANDELBULB_DEFAULTCONTROLLER_H
