#include "Shader.hpp"
#include <glad/glad.h>

Shader::Shader(const char* vertexPath, const char* fragmentPath){

    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try {

        vShaderFile.open(vertexPath);

        std::stringstream vShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        vShaderFile.close();

        vertexCode   = vShaderStream.str();

    } catch (const std::ifstream::failure& e){

        throw ShaderException((std::string("Cannot load shader file ") + vertexPath + ".").c_str());

    }

    try {

        fShaderFile.open(fragmentPath);

        std::stringstream fShaderStream;

        fShaderStream << fShaderFile.rdbuf();
        fShaderFile.close();

        fragmentCode = fShaderStream.str();

    } catch (const std::ifstream::failure& e){

        throw ShaderException((std::string("Cannot load shader file ") + fragmentPath + ".").c_str());

    }

    const char* vShaderCode = vertexCode.c_str();
    const char * fShaderCode = fragmentCode.c_str();
    unsigned int vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    checkCompileErrors(vertex, vertexPath, "VERTEX");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    checkCompileErrors(fragment, fragmentPath, "FRAGMENT");

    ID = glCreateProgram();

    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, "", "PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);

}

void Shader::use(){

    glUseProgram(ID);

}

void Shader::setBool(const char* name, bool value) const {

    glUniform1i(glGetUniformLocation(ID, name), (int) value);

}

void Shader::setInt(const char* name, int value) const {

    glUniform1i(glGetUniformLocation(ID, name), value);

}

void Shader::setFloat(const char* name, float value) const {

    glUniform1f(glGetUniformLocation(ID, name), value);

}

void Shader::setMat4f(const char* name, glm::mat4 value) const {

    glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(value));

}

void Shader::setVec2f(const char* name, glm::vec2 value) const {

    glUniform2fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));

}

void Shader::checkCompileErrors(unsigned int shader, const char* path, const std::string& type){

    int success;
    char infoLog[1024];

    if (type != "PROGRAM"){

        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

        if (!success){

            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "Shader compilation error for " << path << " (" << type << "): " << infoLog << std::endl;

        }

    } else {

        glGetProgramiv(shader, GL_LINK_STATUS, &success);

        if (!success){

            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "Linking error (" << type << "): " << infoLog << std::endl;

        }

    }

}
