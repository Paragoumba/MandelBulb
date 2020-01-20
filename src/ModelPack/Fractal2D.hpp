#ifndef PTUT_FRACTAL2D_HPP
#define PTUT_FRACTAL2D_HPP

#include "Fractal.hpp"

class Fractal2D : public Fractal {
private:

public:
    Fractal2D();
    ~Fractal2D() override;
    explicit Fractal2D(std::string& e);
    void compute() override;

};


#endif //PTUT_FRACTAL2D_HPP
