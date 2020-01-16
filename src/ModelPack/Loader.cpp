//
// Created by val-duss on 13/01/2020.
//
#include "Loader.hpp"
#include "Fractal2D.hpp"
#include "Fractal3D.hpp"


void Loader::load(Data &data, const string& file_) {
    ifstream file (file_);
    string ligne;
    string equation;
    string dimension;
    if (file.good())
    {
        while (getline(file,ligne))
        {
            equation = ligne.substr(0, ligne.find(";"));
            dimension = ligne.substr(equation.length()+1,2);
            if(dimension.compare( "2D")==0 ){
                data.addFractalPtr(FractalPtr(new Fractal2D("z-i² = z")));
                //data.addFractalPtr(FractalPtr(new Fractal2D(equation)));
            }else if(dimension.compare("3D") == 0){
                data.addFractalPtr(FractalPtr(new Fractal3D("test")));
            }

        }
    }
    else
        cout<<"erreur d'ouverture du fichier"<<endl;

}

void Loader::edit(Data data) {}

void Loader::write(Data data) {}