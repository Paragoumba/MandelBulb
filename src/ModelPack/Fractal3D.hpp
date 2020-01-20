#ifndef PTUT_FRACTAL3D_HPP
#define PTUT_FRACTAL3D_HPP

#include "Fractal.hpp"

class Fractal3D : public Fractal {
public:
    Fractal3D();
    ~Fractal3D() override;
    explicit Fractal3D(std::string& e);
    void compute() override;

};

#endif //PTUT_FRACTAL3D_HPP
