#ifndef PTUT_FRACTAL_HPP
#define PTUT_FRACTAL_HPP
#include "DataManager.hpp"


#include <iostream>
#include <cstring>
#include <memory>

class Fractal {
protected:
    string equation; //type string
    std::map<std::string, std::string> equationParameter;
    DataManager jsonManager = new DataManager("/hello");

public:
    Fractal();
    explicit Fractal(string e);
    virtual ~Fractal();
    void setEquation(string e);
    string getEquation() const;
    virtual void compute();
    void affiche();
    void createEquation(nlohmann::json jsonObject);

};

typedef std::shared_ptr<Fractal> FractalPtr;

#endif //PTUT_FRACTAL_HPP
