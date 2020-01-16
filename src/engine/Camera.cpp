#include "Camera.hpp"

Camera::Camera() : position(0.0f), rotation(0.0f){}

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
