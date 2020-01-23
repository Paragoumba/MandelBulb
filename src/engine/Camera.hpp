#ifndef PTUT_CAMERA_HPP
#define PTUT_CAMERA_HPP

#include <glm/vec3.hpp>

/**
 * \class Camera
 *
 * In this class there are serval functions that can be used in order to managed the Camera
 */
class Camera {
private:
    glm::vec3 position;
    glm::vec3 rotation;

public:
    Camera();

    [[nodiscard]] glm::vec3 getPosition() const;
    [[nodiscard]] glm::vec3 getRotation() const;

    void setPosition(float x, float y, float z);
    void setRotation(float rotX, float rotY, float rotZ);

    void addPosition(float x, float y, float z);
    void addRotation( float rotX, float rotY, float rotZ);
};

#endif //PTUT_CAMERA_HPP
