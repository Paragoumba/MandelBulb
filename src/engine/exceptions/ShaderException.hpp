#ifndef PTUT_SHADEREXCEPTION_HPP
#define PTUT_SHADEREXCEPTION_HPP

#include "Exception.hpp"


/**
 * !\class ShaderException
 *
 * Class who allowed us to manage shader exception
 */

class ShaderException : public Exception {
public:
    explicit ShaderException(const char* message) : Exception(message){}
};

#endif //PTUT_SHADEREXCEPTION_HPP
