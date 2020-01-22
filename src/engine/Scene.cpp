/**
 * \author R.VIOLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
 * \version 0.1
 * \date 22 january 2020
 *
 * Program to manage the scenes of the program
 **/
#include "Scene.hpp"

/**
 * \fn Scene()
 * Constructor of the class scene
 */
Scene::Scene(){

    float cubeVertices[] = {
            // V0
            -0.5f, 0.5f, 0.5f,
            // V1
            -0.5f, -0.5f, 0.5f,
            // V2
            0.5f, -0.5f, 0.5f,
            // V3
            0.5f, 0.5f, 0.5f,
            // V4
            -0.5f, 0.5f, -0.5f,
            // V5
            0.5f, 0.5f, -0.5f,
            // V6
            -0.5f, -0.5f, -0.5f,
            // V7
            0.5f, -0.5f, -0.5f,
            // For text coords in top face
            // V8: V4 repeated
            -0.5f, 0.5f, -0.5f,
            // V9: V5 repeated
            0.5f, 0.5f, -0.5f,
            // V10: V0 repeated
            -0.5f, 0.5f, 0.5f,
            // V11: V3 repeated
            0.5f, 0.5f, 0.5f,
            // For text coords in right face
            // V12: V3 repeated
            0.5f, 0.5f, 0.5f,
            // V13: V2 repeated
            0.5f, -0.5f, 0.5f,
            // For text coords in left face
            // V14: V0 repeated
            -0.5f, 0.5f, 0.5f,
            // V15: V1 repeated
            -0.5f, -0.5f, 0.5f,
            // For text coords in bottom face
            // V16: V6 repeated
            -0.5f, -0.5f, -0.5f,
            // V17: V7 repeated
            0.5f, -0.5f, -0.5f,
            // V18: V1 repeated
            -0.5f, -0.5f, 0.5f,
            // V19: V2 repeated
            0.5f, -0.5f, 0.5f
    };

    float cubeTexCoords[] = {
            0.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f,
            // For text coords in top face
            0.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f,
            // For text coords in right face
            0.0f, 0.0f,
            0.0f, 1.0f,
            // For text coords in left face
            1.0f, 0.0f,
            1.0f, 1.0f,
            // For text coords in bottom face
            0.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f
    };

    unsigned int cubeIndices[] = {
            // Front face
            0, 1, 3, 3, 1, 2,
            // Top Face
            8, 10, 11, 9, 8, 11,
            // Right face
            12, 13, 7, 5, 12, 7,
            // Left face
            14, 15, 6, 4, 14, 6,
            // Bottom face
            16, 18, 19, 17, 16, 19,
            // Back face
            4, 6, 7, 5, 4, 7
    };

    cube = std::make_shared<Mesh>(cubeVertices, sizeof(cubeVertices), cubeTexCoords, sizeof(cubeTexCoords), cubeIndices, sizeof(cubeIndices));

    //meshes.push_back(cube);
    cube->setPosition(-2, 0, -5);
    cube->setRotation(35, 0, 45);
    cube->setScale(1.5);

    float squareVertices[] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f,
             0.5f,  0.5f, 0.0f
    };

    float squareTexCoords[] = {
            0.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f
    };

    unsigned int squareIndices[] = {
            0, 1, 2,
            1, 3, 2
    };

    square = std::make_shared<Mesh>(squareVertices, sizeof(squareVertices), squareTexCoords, sizeof(squareTexCoords), squareIndices, sizeof(squareIndices));

    //meshes.push_back(square);

    square->setPosition(2, 0, -4);

    MaterialPtr squareMaterial(new Material());

    squareMaterial->addTexture(new Texture("../res/imgs/mandelbrot.png"));

    square->setMaterial(squareMaterial);

}
/**
 * \fn void addMesh(MeshPtr& mesh)
 * Add mesh into the vector of meshes
 *
 * @param mesh
 */
void Scene::addMesh(MeshPtr& mesh){

    meshes.push_back(mesh);

}
/**
 * \fn std::vector<MeshPtr> getMeshes() const
 * get the vector of meshes
 *
 * @return meshes
 */
std::vector<MeshPtr> Scene::getMeshes() const {

    return meshes;

}

/**
 * \fn MeshPtr getCube()const
 * Get the mesh of cube
 * @return
 */
MeshPtr Scene::getCube() const {

    return cube;

}
/**
 * \fn MeshPtr getSquare() const
 * get the mesh of square
 *
 * @return
 */
MeshPtr Scene::getSquare() const {

    return square;

}