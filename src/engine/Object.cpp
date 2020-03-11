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
 * Constructor of Object, instantiate a Object by default in 0,0,0, with a rotation of 0,0,0 and a scale of 1,1,1
 *
 */
Object::Object() : position(0, 0, 0), rotation(0, 0, 0), scale(1, 1, 1){}






/**
 * Set the position of the object to the parameters value
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



