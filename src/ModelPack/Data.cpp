#include "Data.hpp"


Data::Data() {}

Data::~Data() {}

void Data::addFractalPtr(FractalPtr fractal) {

    this->listOfFractal.push_front(fractal);

}

void Data::setActiveFractalPtr(FractalPtr fractal) {

    this->activeFractal = fractal;

}

void Data::addObserver() {

}

FractalPtr Data::getActiveFractalPtr() const {

    return activeFractal;

}

std::list<FractalPtr> Data::getListOfFractalPtr() const  {

    return this->listOfFractal;

}

void Data::printListOfFractal() {

    for (auto it = this->listOfFractal.begin(); it != this->listOfFractal.end(); ++it) {

        (*it)->affiche();

    }

}