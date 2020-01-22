#ifndef PTUT_TRANSFORMATION_HPP
#define PTUT_TRANSFORMATION_HPP
/**
 * \author R.VIOLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
 * \version 0.1
 * \date 22 january 2020
 *
 * Program
 *
 */

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.hpp"
#include "Object.hpp"
/**
 * \class Transformation
 * ?
 */
class Transformation {
private:
    static glm::mat4 projectionMatrix;

public:
    static glm::mat4& getProjectionMatrix();
    /**
     *  define the projection matrix
     * @param fov
     * @param aspect
     * @param zNear
     * @param zFar
     */
    static void setProjectionMatrix(float fov, float aspect, float zNear, float zFar);
    /**
     * return the projectionMatrix
     *
     * @param left
     * @param right
     * @param bottom
     * @param top
     * @param zNear
     * @param zFar
     */
    static void setProjectionMatrix(float left, float right, float bottom, float top, float zNear, float zFar);
    /**
     * return the model of matrix
     * @param object
     * @return
     */
    static glm::mat4 getModelMatrix(Object* object);
    /**
     * return the matrix view
     * @param camera
     * @return
     */
    static glm::mat4 getViewMatrix(Camera& camera);
};

#endif //PTUT_TRANSFORMATION_HPP
