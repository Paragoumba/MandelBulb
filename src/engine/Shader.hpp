#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>

//#include <glad/glad.h>

#include "exceptions/ShaderException.hpp"

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);

    void use();

    void setBool(const char* name, bool value) const;
    void setInt(const char* name, int value) const;
    void setFloat(const char* name, float value) const;
    void setMat4f(const char* name, glm::mat4 value) const;
    void setVec2f(const char* name, glm::vec2 value) const;

private:
    static void checkCompileErrors(unsigned int shader, const char*, const std::string& type);

};
#endif