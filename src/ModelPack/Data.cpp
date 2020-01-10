//
// Created by val-duss on 10/01/2020.
//

#include "Data.hpp"


Data::Data() {

}

Data::~Data() {}

void Data::AddFractal(FractalPtr f) {
    this->list_of_fractal.push_front(f);
}

void Data::setActiveFractal(FractalPtr f) {
    this->active_fractal = f;
}

void Data::addObserver() {

}
FractalPtr& Data::getActiveFractal() {
    return active_fractal;
}

list<FractalPtr> Data::getListOfFractal() {
    return this->list_of_fractal;
}

void Data::printListOfFractal() {
    for(auto it = this->list_of_fractal.begin(); it != this->list_of_fractal.end(); ++it)
        (*it)->affiche();


}