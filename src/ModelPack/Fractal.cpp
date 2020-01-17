//
// Created by val-duss on 10/01/2020.
//

#include "Fractal.hpp"


Fractal::Fractal() {

    createEquation(jsonManager.load("MandelBulb"));

}

Fractal::~Fractal() {}

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

void Fractal::createEquation(nlohmann::json jsonObject){

    equationParameter["$a"] = jsonObject["equation"]["sum"]["pow"]["$a"];
    equationParameter["$c"] = jsonObject["equation"]["sum"]["$c"];
    equationParameter["a"] = jsonObject["variables"]["a"];
    equationParameter["c"] = jsonObject["variables"]["c"];
    equation = equationParameter.at("a") + "^" + equationParameter.at("$a") + " + " + equationParameter.at("c") + "^" + equationParameter.at("$c");

}