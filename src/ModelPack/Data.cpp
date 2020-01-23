#include "Data.hpp"

Data::Data() = default;
Data::~Data() = default;

void Data::addFractalPtr(FractalPtr &fractal) {

    listOfFractal.push_front(fractal);

}

void Data::setActiveFractalPtr(FractalPtr& fractal) {

    activeFractal = fractal;

}

void Data::addObserver() {

}

FractalPtr Data::getActiveFractalPtr() const {

    return activeFractal;

}

std::list<FractalPtr> Data::getListOfFractalPtr() const  {

    return listOfFractal;

}

void Data::printListOfFractal() {

    auto end = listOfFractal.end();
    for (auto it = listOfFractal.begin(); it != end; ++it) {

        (*it)->print();

    }

    delete it;

}