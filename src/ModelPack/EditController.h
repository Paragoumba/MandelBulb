//
// Created by daniel on 10/01/2020.
//

#ifndef MANDELBULB_EDITCONTROLLER_H
#define MANDELBULB_EDITCONTROLLER_H


#include "Controller.h"

class EditController : public Controller{
private:
    //Menu Controlleur
public:
    EditController(Fractal _fractal);
    ~EditController();
    void compute(Fractal _fractal) override;
};


#endif //MANDELBULB_EDITCONTROLLER_H
