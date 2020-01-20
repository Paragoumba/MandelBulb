#ifndef PTUT_DATA_HPP
#define PTUT_DATA_HPP

#include <list>

#include "Fractal.hpp"

class Data {

private:
    std::list<FractalPtr> listOfFractal;
    FractalPtr activeFractal;

public:
    Data();
    ~Data();
    static void addObserver();
    void addFractalPtr(FractalPtr& fractal);
    void setActiveFractalPtr(FractalPtr& fractal);
    [[nodiscard]] FractalPtr getActiveFractalPtr() const;
    [[nodiscard]] std::list<FractalPtr> getListOfFractalPtr() const;
    void printListOfFractal();

};

#endif //PTUT_DATA_HPP
