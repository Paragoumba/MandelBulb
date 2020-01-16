//
// Created by val-duss on 10/01/2020.
//

#include "Fractal.hpp"


 Fractal::Fractal() = default;

Fractal::~Fractal() = default;

Fractal::Fractal(string e) {
    this->equation = e;
}

void Fractal::setEquation(string e) {
    this->equation = e;
}

void Fractal::compute() {
    //inherit fonction
}

void Fractal::affiche() {
    std:cout << this->equation << endl;
}

string Fractal::getEquation() const {
    return this->equation;
}
