#ifndef MANDELBULB_EDITCONTROLLER_H
#define MANDELBULB_EDITCONTROLLER_H

#include "Controller.h"

class EditController : public Controller {
private:
    //Menu Controlleur

public:
    EditController(Data data);
    ~EditController();
    void compute() override;

};

#endif //MANDELBULB_EDITCONTROLLER_H
