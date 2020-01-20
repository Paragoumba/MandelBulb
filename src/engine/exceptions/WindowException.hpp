#ifndef PTUT_WINDOWEXCEPTION_HPP
#define PTUT_WINDOWEXCEPTION_HPP

#include <exception>
#include <string>

class WindowException : std::exception {
private:
    std::string message;

public:
    explicit WindowException(std::string message);

    virtual const char* what();
};

#endif //PTUT_WINDOWEXCEPTION_HPP
