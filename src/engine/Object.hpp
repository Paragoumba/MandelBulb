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

    [[nodiscard]] glm::vec3 getPosition() const;
    [[nodiscard]] glm::vec3 getRotation() const;
    [[nodiscard]] glm::vec3 getScale() const;

    void setPosition(float x, float y, float z);
    void setRotation(float rotX, float rotY, float rotZ);
    void setScale(float _scale);
    void setScale(float scaleX, float scaleY, float scaleZ);

    void addRotation(float rotX, float rotY, float rotZ);
};

#endif //PTUT_OBJECT_HPP
