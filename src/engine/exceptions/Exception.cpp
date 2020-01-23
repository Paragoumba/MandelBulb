/*!
 * \file Exception.hpp
 * \brief Class who allowed us to manage exception
 * \author DUSSERVAIX V., OVEJERO D., TESSON L., VIOLLET R.
 *
 */
#include "Exception.hpp"

/**
 * Return the exception message
 *
 * @param _message
 */
Exception::Exception(const char* _message) : message(_message){}

const char* Exception::what() const noexcept {

    return message.c_str();

}
