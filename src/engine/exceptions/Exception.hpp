#ifndef PTUT_EXCEPTION_HPP
#define PTUT_EXCEPTION_HPP


#include <exception>
#include <string>
/**
 * !\class Exception
 *
 * Class who allowed us to manage exception
 */
class Exception : public std::exception {
protected:
    std::string message;

public:
    explicit Exception(const char* _message);

    [[nodiscard]] const char* what() const noexcept override;
};

#endif //PTUT_EXCEPTION_HPP
