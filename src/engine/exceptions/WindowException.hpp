#ifndef PTUT_WINDOWEXCEPTION_HPP
#define PTUT_WINDOWEXCEPTION_HPP

#include "Exception.hpp"

class WindowException : public Exception {
public:
    explicit WindowException(const char* message) : Exception(message){};
};

#endif //PTUT_WINDOWEXCEPTION_HPP
