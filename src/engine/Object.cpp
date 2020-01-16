#include "Object.hpp"

Object::Object() : position(0, 0, 0), rotation(0, 0, 0), scale(1, 1, 1){}

glm::vec3 Object::getPosition() const {

    return position;

}

glm::vec3 Object::getRotation() const {

    return rotation;

}

glm::vec3 Object::getScale() const {

    return scale;

}

void Object::setPosition(float x, float y, float z){

    position.x = x;
    position.y = y;
    position.z = z;

}

void Object::setRotation(float rotX, float rotY, float rotZ){

    rotation.x = rotX;
    rotation.y = rotY;
    rotation.z = rotZ;

}

void Object::setScale(float _scale){

    scale.x = scale.y = scale.z = _scale;

}

void Object::setScale(float scaleX, float scaleY, float scaleZ){

    scale.x = scaleX;
    scale.y = scaleY;
    scale.z = scaleZ;

}

void Object::addRotation(float rotX, float rotY, float rotZ){

    rotation.x += rotX;
    rotation.y += rotY;
    rotation.z += rotZ;

}
