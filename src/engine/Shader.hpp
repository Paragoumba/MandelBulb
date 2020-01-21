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

    void setBool(const char* name, bool value);
    void setInt(const char* name, int value);
    void setFloat(const char* name, float value);
    void setMat4(const char* name, glm::mat4 value);
    void setVec2(const char* name, glm::vec2 value);
    void setVec3(const char* name, glm::vec3 value);
    void setVec4(const char* name, glm::vec4 value);

private:
    static void checkCompileErrors(unsigned int shader, const char*, const std::string& type);
};
#endif
