//
// Created by val-duss on 10/01/2020.
//
#include "Fractal.hpp"
#ifndef PTUT_FRACTAL2D_HPP
#define PTUT_FRACTAL2D_HPP


class Fractal2D : public Fractal {
private:
public:
    Fractal2D();
    ~Fractal2D() override;
    explicit Fractal2D(string e);
    void compute() override;
};


#endif //PTUT_FRACTAL2D_HPP
