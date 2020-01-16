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
    list<FractalPtr> listOfFractal;
    FractalPtr activeFractal;
public:
    Data();
    ~Data();
    void addObserver();
    void addFractalPtr(FractalPtr fractal);
    void setActiveFractalPtr(FractalPtr fractal);
    FractalPtr getActiveFractalPtr() const;
    list<FractalPtr> getListOfFractalPtr() const;
    void printListOfFractal();
};





#endif //PTUT_DATA_HPP
