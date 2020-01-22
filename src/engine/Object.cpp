/**
 * \file Object.cpp
 * \brief Manage the objects
 * \author DUSSERVAIX V., OVEJERO D., TESSON L., VIOLLET R.
 * \date 22 January 2020
 *
 * In this class there are serval functions that can be used in order to managed Objects
 */
#include "Object.hpp"

/**
 * \fn Object
 * \brief Constructor of Object, instantiate a Object by default in 0,0,0, with a rotation of 0,0,0 and a scale of 1,1,1
 *
 */
Object::Object() : position(0, 0, 0), rotation(0, 0, 0), scale(1, 1, 1){}

glm::vec3 Object::getPosition() const {

    return position;

}

/**
 * \fn getRotation
 * \brief return the current rotation of the object
 *
 * @return glm::vec3 rotation
 */
glm::vec3 Object::getRotation() const {

    return rotation;

}

/**
 * \fn getScale
 * \brief return the current scale of the object
 *
 * @return glm::vec3 scale
 */
glm::vec3 Object::getScale() const {

    return scale;

}

/**
 * \fn setPosition
 * \brief Set the position of the object to the parameters value
 *
 * @param x
 * @param y
 * @param z
 */
void Object::setPosition(float x, float y, float z){

    position.x = x;
    position.y = y;
    position.z = z;

}

/**
 * \fn setRotation
 * \brief Set the rotation of the object to the parameters value
 *
 * @param rotX
 * @param rotY
 * @param rotZ
 */
void Object::setRotation(float rotX, float rotY, float rotZ){

    rotation.x = rotX;
    rotation.y = rotY;
    rotation.z = rotZ;

}

/**
 * \fn setScale
 * \brief Set the general scale of the object to the parameter value
 *
 * @param _scale
 */
void Object::setScale(float _scale){

    scale.x = scale.y = scale.z = _scale;

}

/**
 * \fn setScale
 * \brief Set the scale of the object on each axis to the parameters value
 *
 * @param scaleX
 * @param scaleY
 * @param scaleZ
 */
void Object::setScale(float scaleX, float scaleY, float scaleZ){

    scale.x = scaleX;
    scale.y = scaleY;
    scale.z = scaleZ;

}

/**
 * \fn addRotation
 * \brief Increase the current rotation from the parameters value
 *
 * @param rotX
 * @param rotY
 * @param rotZ
 */
void Object::addRotation(float rotX, float rotY, float rotZ){

    rotation.x += rotX;
    rotation.y += rotY;
    rotation.z += rotZ;

}
