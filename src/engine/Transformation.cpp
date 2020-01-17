#include "Transformation.hpp"

glm::mat4 Transformation::projectionMatrix;

glm::mat4 &Transformation::getProjectionMatrix() {

    return projectionMatrix;

}

void Transformation::setProjectionMatrix(float fov, float aspect, float zNear, float zFar){

    projectionMatrix = glm::perspective(fov, aspect, zNear, zFar);

}

void Transformation::setProjectionMatrix(float left, float right, float bottom, float top, float zNear, float zFar){

    projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);

}

glm::mat4 Transformation::getModelMatrix(Object* object) {

    glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), object->getPosition());

    glm::vec3 rotation = object->getRotation();

    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));

    modelMatrix = glm::scale(modelMatrix, object->getScale());

    return modelMatrix;

}

glm::mat4 Transformation::getViewMatrix(Camera& camera){

    glm::vec3 position = camera.getPosition();
    glm::vec3 rotation = camera.getRotation();

    glm::mat4 viewMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1, 0, 0));
    viewMatrix =           glm::rotate(viewMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    viewMatrix =           glm::rotate(viewMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));

    viewMatrix = glm::translate(viewMatrix, glm::vec3(-position.x, -position.y, -position.z));

    return viewMatrix;

}
