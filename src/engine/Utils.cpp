#include <iostream>

#include "Utils.hpp"

std::filesystem::path Utils::exePath;

void Utils::setExePath(const char* path){

   exePath = std::filesystem::path(path);

}

std::filesystem::path Utils::getExePath(){

    return exePath;

}

std::string Utils::getPath(const char* path){

    std::string filePath = std::string(exePath.parent_path().c_str())
            + std::filesystem::path::preferred_separator + path;

    return filePath;

}
