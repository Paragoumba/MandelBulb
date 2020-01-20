#include "Fractal.hpp"

Fractal::Fractal() {

    createEquation(jsonManager->load((std::string &) "MandelBulb"));

}

Fractal::~Fractal() = default;

Fractal::Fractal(std::string& e) {

    equation = e;

}

void Fractal::setEquation(std::string& e) {

    equation = e;

}

void Fractal::compute() {
    //inherit fonction
}

void Fractal::print() {

    std::cout << equation << std::endl;

}

void Fractal::createEquation(nlohmann::json jsonObject){

    equationParameter["$a"] = jsonObject["equation"]["sum"]["pow"]["$a"];
    equationParameter["$c"] = jsonObject["equation"]["sum"]["$c"];
    equationParameter["a"] = jsonObject["variables"]["a"];
    equationParameter["c"] = jsonObject["variables"]["c"];
    equation = equationParameter.at("a") + "^" + equationParameter.at("$a") + " + " + equationParameter.at("c") + "^" + equationParameter.at("$c");

}

std::string Fractal::getEquation() const {

    return equation;

}