#include <iostream>

#include "Utils.hpp"

std::filesystem::path Utils::exePath;

void Utils::setExePath(const char* path){

   exePath = std::filesystem::path(path);

}


std::string Utils::getPath(const char* path){

    std::string filePath = exePath.parent_path() / path;

    return filePath;

}
