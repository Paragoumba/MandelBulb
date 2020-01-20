#ifndef PTUT_LOADER_HPP
#define PTUT_LOADER_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<json/json.hpp>
#include "Data.hpp"


class DataManager {
private:
    nlohmann::json json;
    const char* path;

public:
    DataManager(const char* _path);
    nlohmann::json load(std::string nomEquation);

};


#endif //PTUT_LOADER_HPP
