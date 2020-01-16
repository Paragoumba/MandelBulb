//
// Created by val-duss on 10/01/2020.
//
#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

#ifndef PTUT_FRACTAL_HPP
#define PTUT_FRACTAL_HPP


class Fractal {
protected:
    string equation; //type string
public:
    Fractal();
    explicit Fractal(string e);
    virtual ~Fractal();
    void setEquation(string e);
    string getEquation() const;
    virtual void compute();
    void affiche();
};

typedef shared_ptr<Fractal> FractalPtr;
#endif //PTUT_FRACTAL_HPP
