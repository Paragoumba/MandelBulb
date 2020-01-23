#ifndef PTUT_MATERIALEXCEPTION_HPP
#define PTUT_MATERIALEXCEPTION_HPP

#include "Exception.hpp"

class MaterialException : public Exception {
public:
    explicit MaterialException(const char* message) : Exception(message){}
};

#endif //PTUT_MATERIALEXCEPTION_HPP