//
// Created by val-duss on 10/01/2020.
//

#include "Fractal.hpp"


 Fractal::Fractal() {


}

Fractal::~Fractal() {

}

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

    cout<<this->equation<<endl;
}