/**
 * \file Camera.cpp
 * Manager of the Camera
 * \author DUSSERVAIX V., OVEJERO D., TESSON L., VIOLLET R.
 * \date 22 January 2020
 *
 * In this class there are serval functions that can be used in order to managed the Camera
 */
#include <cmath>
#include <glm/glm.hpp>
#include "Camera.hpp"

/**
 * The default constructor of the Camera
 *
 */
Camera::Camera() : position(0.0f), rotation(0.0f){}


/**
 * Return the current position of the Camera
 *
 * @return glm::vec3 position
 */
glm::vec3 Camera::getPosition() const {

    return position;

}

/**
 * Return the current rotation of the Camera
 *
 * @return glm::vec3 rotation
 */
glm::vec3 Camera::getRotation() const {

    return rotation;

}

/**
 * Define the position of the Camera
 *
 * @param x
 * @param y
 * @param z
 */
void Camera::setPosition(float x, float y, float z){

    position.x = x;
    position.y = y;
    position.z = z;

}


/**
 * add to the current position those parameter
 *
 * @param x
 * @param y
 * @param z
 */
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

/**
 * add to the current rotation those parameter
 *
 * @param x
 * @param y
 * @param z
 */
void Camera::addRotation(float rotX, float rotY, float rotZ){

    rotation.x += rotX;
    rotation.y += rotY;
    rotation.z += rotZ;

}
