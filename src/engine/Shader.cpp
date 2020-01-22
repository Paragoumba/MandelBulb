/**
 * \author R.VIOLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
 * \version 0.1
 * \date 22 january 2020
 *
 * Program to manage the shaders of the program
 **/

#include <glm/gtc/type_ptr.hpp>

#include "Shader.hpp"
#include "exceptions/ShaderException.hpp"

/**
 * \fn Shader(const char* vertexPath, const char* fragmentPath)
 *  Constructor of the class sherder
 *
 * @param vertexPath
 * @param fragmentPath
 */
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

/**
 * \fn void use(void)
 *
 *
 *
 */
void Shader::use(){

    glUseProgram(ID);

}
/**
 * \fn void setBool(const char* name, bool value)
 *  define the bool
 *
 * @param name
 * @param value
 */
void Shader::setBool(const char* name, bool value){

    glUniform1i(glGetUniformLocation(ID, name), (int) value);

}
/**
 * \fn setInt(const char* name, int vaue)
 *
 * @param name
 * @param value
 */
void Shader::setInt(const char* name, int value){

    glUniform1i(glGetUniformLocation(ID, name), value);

}
/**
 * \fn void setFloat(const char* name, float value)
 *
 * @param name
 * @param value
 */

void Shader::setFloat(const char* name, float value){

    glUniform1f(glGetUniformLocation(ID, name), value);

}

/**
 * \fn void setMat4(const char* name, glm::mat4 value)
 *  set the matrix 4
 *
 * @param name , name of the matrix
 * @param value , value of the matrix
 */
void Shader::setMat4(const char* name, glm::mat4 value){

    glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(value));

}
/**
 * \fn void setVect2(const char* name, glm::vect2 value)
 *  set the vector 2
 *
 * @param name , name of the vector
 * @param value , value of the vector
 */
void Shader::setVec2(const char* name, glm::vec2 value){

    glUniform2fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));

}

/**
 * \fn void setVect3(const char* name, glm::vect3 value)
 *  set the vector 3
 *
 * @param name , name of the vector
 * @param value , value of the vector
 */
void Shader::setVec3(const char* name, glm::vec3 value){

    glUniform3fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));

}
/**
 * \fn void setVect4(const char* name, glm::vect4 value)
 *  set the vector 4
 *
 * @param name , name of the vector
 * @param value , value of the vector
 */
void Shader::setVec4(const char* name, glm::vec4 value){

    glUniform4fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));

}
/**
 * \fn void checkCompileErrors(unsigned int shader, const char* path, const std::string& type)
 *  Check if have the error during the compilation *
 *
 * @param shader
 * @param path
 * @param type
 */
void Shader::checkCompileErrors(unsigned int shader, const char* path, const std::string& type){

    int success;
    char infoLog[1024];

    if (type != "PROGRAM"){

        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

        if (!success){

            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "Shader compilation error for " << path << " (" << type << "): " << infoLog << std::endl;

        }

    } else {

        glGetProgramiv(shader, GL_LINK_STATUS, &success);

        if (!success){

            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "Linking error (" << type << "): " << infoLog << std::endl;

        }
    }
}
