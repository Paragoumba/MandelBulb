#ifndef SHADER_H
#define SHADER_H
/**
 * \author R.VIOLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
 * \version 0.1
 * \date 22 january 2020
 *
 * Program to manage the Shaders of the program
 **/
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/mat4x4.hpp>
#include <glad/glad.h>
/**
 * \class Shader
 * Manage and define the shaders of the program
 */
class Shader {
public:
    unsigned int ID;
    /**
     * Constructor of the class Shader
     * @param vertexPath
     * @param fragmentPath
     */
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    /**
     * Use
     */
    void use();
    /**
     * Set the integer
     * @param name
     * @param value
     */
    void setInt(const char* name, int value);
    /**
     * Set the float
     * @param name
     * @param value
     */
    void setFloat(const char* name, float value);
    /**
     * Set the Matrix 4
     * @param name
     * @param value
     */
    void setMat4(const char* name, glm::mat4 value);
    /**
     * Set the vector 2
     * @param name
     * @param value
     */
    void setVec2(const char* name, glm::vec2 value);
    /**
     * Set the vector 3
     * @param name
     * @param value
     */
    void setVec3(const char* name, glm::vec3 value);
    /**
     * Set the vector 4
     * @param name
     * @param value
     */
    void setVec4(const char* name, glm::vec4 value);

private:
    /**
     * Check the error in the compilation
     * @param shader
     * @param type
     */
    static void checkCompileErrors(unsigned int shader, const char*, const std::string& type);
};
#endif
