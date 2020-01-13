//
// Created by val-duss on 13/01/2020.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Data.hpp"

#ifndef PTUT_LOADER_HPP
#define PTUT_LOADER_HPP

class Loader {
public:
    void load(Data &data, string file);
    void write(Data data);
    void edit(Data data);

};


#endif //PTUT_LOADER_HPP