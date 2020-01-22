#ifndef PTUT_SCENE_HPP
#define PTUT_SCENE_HPP
/**
 * \author R.VIOLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
 * \version 0.1
 * \date 22 january 2020
 *
 * Program to manage the Scenes of the program
 **/


#include <vector>

#include "Shader.hpp"
#include "Mesh.hpp"


/**
 * \class Scene
 *
 * this class manage scene
 */
class Scene {
private:
    std::vector<MeshPtr> meshes; /*! < list of the meshes */
    MeshPtr cube; /*!< mesh */
    MeshPtr square; /*!< mesh */

public:
    /**
     * Constructor of the class scene
     */
    Scene();
    /**
    /**
     * Add mesh into the vector of meshes
     * @param mesh
     */
    void addMesh(MeshPtr& mesh);
    /**
     * get the vector of meshes
     * @return
     */
    [[nodiscard]] std::vector<MeshPtr> getMeshes() const;
    /**
    * get the mesh of cube
     * @return
     */
    [[nodiscard]] MeshPtr getCube() const;
    /**
    * get the mesh of square
     * @return
     */
    [[nodiscard]] MeshPtr getSquare() const;

};

#endif //PTUT_SCENE_HPP
