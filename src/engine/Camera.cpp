#include <cmath>
#include <glm/glm.hpp>
#include "Camera.hpp"

Camera::Camera() : position(0.0f, 0.0f, 3.0f), rotation(0.0f){}

glm::vec3 Camera::getPosition() const {

    return position;

}

glm::vec3 Camera::getRotation() const {

    return rotation;

}

void Camera::setPosition(float x, float y, float z){

    position.x = x;
    position.y = y;
    position.z = z;

}

void Camera::setRotation(float rotX, float rotY, float rotZ){

    rotation.x = rotX;
    rotation.y = rotY;
    rotation.z = rotZ;

}

void Camera::addPosition(float x, float y, float z){

    if (z != 0){

        position.x += (float) std::sin(glm::radians(rotation.y)) * -z;
        position.z += (float) std::cos(glm::radians(rotation.y)) *  z;

    }

    if (x != 0){

        position.x += (float) std::sin(glm::radians(rotation.y - 90)) * -x;
        position.z += (float) std::cos(glm::radians(rotation.y - 90)) *  x;

    }

    position.y += y;

}

void Camera::addRotation(float rotX, float rotY, float rotZ){

    rotation.x += rotX;
    rotation.y += rotY;
    rotation.z += rotZ;

}
