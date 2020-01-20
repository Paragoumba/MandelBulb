#ifndef PTUT_DATA_HPP
#define PTUT_DATA_HPP

#include <list>
#include <iostream>
#include <cstring>

#include "Fractal.hpp"

class Data {

private:
    std::list<FractalPtr> listOfFractal;
    FractalPtr activeFractal;

public:
    Data();
    ~Data();
    void addObserver();
    void addFractalPtr(FractalPtr fractal);
    void setActiveFractalPtr(FractalPtr fractal);
    FractalPtr getActiveFractalPtr() const;
    std::list<FractalPtr> getListOfFractalPtr() const;
    void printListOfFractal();

};

#endif //PTUT_DATA_HPP
