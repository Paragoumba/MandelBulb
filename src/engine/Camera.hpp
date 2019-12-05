#ifndef PTUT_CAMERA_HPP
#define PTUT_CAMERA_HPP

#include <glm/vec3.hpp>

class Camera {
private:
    glm::vec3 position;
    glm::vec3 rotation;

public:
    [[nodiscard]] glm::vec3 getPosition() const;
    [[nodiscard]] glm::vec3 getRotation() const;

    void setPosition(float x, float y, float z);
    void setRotation(float rotX, float rotY, float rotZ);
};

#endif //PTUT_CAMERA_HPP
