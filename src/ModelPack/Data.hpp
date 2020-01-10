//
// Created by val-duss on 10/01/2020.
//
#include <list>
#include <iostream>
#include <cstring>
#include "Fractal.hpp"


#ifndef PTUT_DATA_HPP
#define PTUT_DATA_HPP


class Data {

private:
    list<FractalPtr> list_of_fractal;
    FractalPtr active_fractal;
public:
    Data();
    ~Data();
    void addObserver();
    void AddFractal(FractalPtr fractal);
    void setActiveFractal(FractalPtr fractal);
    FractalPtr& getActiveFractal();
    list<FractalPtr> getListOfFractal();
    void printListOfFractal();
};





#endif //PTUT_DATA_HPP
