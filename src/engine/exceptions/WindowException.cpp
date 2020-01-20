#include "WindowException.hpp"

#include <utility>

WindowException::WindowException(std::string message) : message(std::move(message)){}

const char* WindowException::what(){

    return message.c_str();

}
