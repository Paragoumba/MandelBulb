#include "Data.hpp"


Data::Data() {}

Data::~Data() {}

void Data::addFractalPtr(FractalPtr fractal) {

    listOfFractal.push_front(fractal);

}

void Data::setActiveFractalPtr(FractalPtr fractal) {

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

    for (auto it = listOfFractal.begin(); it != listOfFractal.end(); ++it) {

        (*it)->affiche();

    }

}