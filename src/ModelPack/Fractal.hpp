#ifndef PTUT_FRACTAL_HPP
#define PTUT_FRACTAL_HPP

#include <memory>

#include "DataManager.hpp"

class Fractal {
protected:
    std::string equation;
    std::map<std::string, std::string> equationParameter;
    DataManager *jsonManager = new DataManager("/hello");

public:
    Fractal();
    explicit Fractal(std::string& e);
    virtual ~Fractal();
    void setEquation(std::string& e);
    [[nodiscard]] std::string getEquation() const;
    virtual void compute();
    void print();
    void createEquation(nlohmann::json jsonObject);

};

typedef std::shared_ptr<Fractal> FractalPtr;

#endif //PTUT_FRACTAL_HPP
