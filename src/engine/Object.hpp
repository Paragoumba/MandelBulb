#ifndef PTUT_OBJECT_HPP
#define PTUT_OBJECT_HPP

#include <glm/vec3.hpp>

/**
 * \class Object
 *
 * In this class there are serval functions that can be used in order to managed Objects
 */
class Object {
private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

public:
    Object();

    void setPosition(float x, float y, float z);
};

#endif //PTUT_OBJECT_HPP
