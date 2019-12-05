#ifndef PTUT_OBJECT_HPP
#define PTUT_OBJECT_HPP

#include <glm/vec3.hpp>

class Object {
private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

public:
    [[nodiscard]] glm::vec3 getPosition() const;
    [[nodiscard]] glm::vec3 getRotation() const;
    [[nodiscard]] glm::vec3 getScale() const;

    void setPosition(float x, float y, float z);
    void setRotation(float rotX, float rotY, float rotZ);
    void setScale(float _scale);
    void setScale(float scaleX, float scaleY, float scaleZ);
};

#endif //PTUT_OBJECT_HPP
