/**
 * \author R.VIOLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
 * \version 0.1
 * \date 22 january 2020
 *
 * Program
 *
 */
#include "Transformation.hpp"

glm::mat4 Transformation::projectionMatrix;

/**
 *  return the projectionMatrix
 *
 * @return Matrix
 */

glm::mat4 &Transformation::getProjectionMatrix(){

    return projectionMatrix;

}
/**
 *  define the projection matrix
 *
 * @param fov,
 * @param aspect
 * @param zNear
 * @param zFar
 */


void Transformation::setProjectionMatrix(float fov, float aspect, float zNear, float zFar){

    projectionMatrix = glm::perspective(fov, aspect, zNear, zFar);

}

/**
 *  define the projection matrix
 *
 * @param left
 * @param right
 * @param bottom
 * @param top
 * @param zNear
 * @param zFar
 */
void Transformation::setProjectionMatrix(float left, float right, float bottom, float top, float zNear, float zFar){

    projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);

}

/**
 * return the model of matrix
 *
 * @param object
 * @return
 */
glm::mat4 Transformation::getModelMatrix(Object* object){

    glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), object->getPosition());

    glm::vec3 rotation = object->getRotation();

    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));

    modelMatrix = glm::scale(modelMatrix, object->getScale());

    return modelMatrix;

}

/**
 *  return the matrix view
 *
 * @param camera
 * @return
 */
glm::mat4 Transformation::getViewMatrix(Camera& camera){

    glm::vec3 position = camera.getPosition();
    glm::vec3 rotation = camera.getRotation();

    glm::mat4 viewMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1, 0, 0));
    viewMatrix =           glm::rotate(viewMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    viewMatrix =           glm::rotate(viewMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));

    viewMatrix = glm::translate(viewMatrix, glm::vec3(-position.x, -position.y, -position.z));

    return viewMatrix;

}
