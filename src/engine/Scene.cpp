/**
 * \file Scene.cpp
 * \brief Program to manage scene.
 * \author R.VIOLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
 * \version 0.1
 * \date 22 january 2020
 *
 * Program to manage the scene of the program
 **/


#include "Scene.hpp"
/**
 * \fn Scene()
 * \brief Constructor of the class Scene
 *
 */
Scene::Scene(){


}

/**
 * \fn void addMesh(MeshPtr& mesh)
 * \brief add mesh into the vector "meshes"
 *
 * @param mesh, the mesh to add
 */
void Scene::addMesh(MeshPtr& mesh){

    meshes.push_back(mesh);

}
/**
 * \fn std::vector<MeshPtr> getMeshes() const
 * \brief get the vector of all meshes in this scene
 *
 * @return meshes, vector of meshes
 */

std::vector<MeshPtr> Scene::getMeshes() const {

    return meshes;

}

/**
 * \fn MeshPtr getCube()const
 * \brief get the mesh cube
 *
 * @return Mesh
 */

MeshPtr Scene::getCube() const {

    return cube;

}
/**
 * \fn MeshPtr getSquare()const
 * \brief get the mesh square
 *
 * @return Mesh
 */
MeshPtr Scene::getSquare() const {

    return square;

}