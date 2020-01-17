#ifndef PTUT_FRACTAL_HPP
#define PTUT_FRACTAL_HPP

#include <iostream>
#include <cstring>
#include <memory>

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

typedef std::shared_ptr<Fractal> FractalPtr;

#endif //PTUT_FRACTAL_HPP
