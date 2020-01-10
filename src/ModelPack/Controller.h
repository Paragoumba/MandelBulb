//
// Created by daniel on 10/01/2020.
//

#ifndef MANDELBULB_CONTROLLER_H
#define MANDELBULB_CONTROLLER_H


class Controller {
protected:
    Fractal fractal;

public:
    Controller(Fractal _fractal);
    ~Controller();
    void setFractal(Fractal _fractal);
    Fractal getFractal();
    virtual void compute(Fractal fractal) = 0;
};


#endif //MANDELBULB_CONTROLLER_H
