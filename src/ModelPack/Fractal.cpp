#include "Fractal.hpp"

Fractal::Fractal() = default;

Fractal::~Fractal() = default;

Fractal::Fractal(string e) {

    equation = e;

}

void Fractal::setEquation(string e) {

    equation = e;

}

void Fractal::compute() {
    //inherit fonction
}

void Fractal::affiche() {

    std::cout << equation << endl;

}

string Fractal::getEquation() const {

    return equation;

}