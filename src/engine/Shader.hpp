#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/mat4x4.hpp>
#include <glad/glad.h>

class Shader {
public:
    unsigned int ID;

    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

    void use();

    void setBool(const char* name, bool value) const;
    void setInt(const char* name, int value) const;
    void setFloat(const char* name, float value) const;
    void setMat4f(const char* name, glm::mat4 value) const;

private:
    static void checkCompileErrors(unsigned int shader, const std::string& type);
};
#endif
