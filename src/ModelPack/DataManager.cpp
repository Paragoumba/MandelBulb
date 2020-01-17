#include<fstream>
#include "DataManager.hpp"
#include "Fractal2D.hpp"
#include "Fractal3D.hpp"

DataManager::DataManager(const char* _path) : path(_path){
    ifstream f (path);
    if(f){
        f >> json;
    }

    else{
        std::cerr << " Le fichier "<<  _path <<" n'exite pas. Utilisation des valeurs par défaut."<< std::endl;
        json ={
                "formulas", {
                    "mandelbrot", {
                        "equation", {
                            "sum", {
                                "pow", {
                                    "$a", 2
                                },
                                "$c", 1
                            }
                        },
                        "variables", {
                            "a", 1,
                            "c", 2
                        }
                    }
                }
        };
    }
}

nlohmann::json DataManager::load(std::string nomEquation) {
    nlohmann::json equationJson;
    equationJson = json["formulas"][nomEquation];
    return equationJson;
}

void DataManager::write(Fractal& fractal) {

}