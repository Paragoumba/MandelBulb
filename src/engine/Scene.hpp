#ifndef PTUT_SCENE_HPP
#define PTUT_SCENE_HPP

#include <vector>

#include "Shader.hpp"
#include "Mesh.hpp"

class Scene {
private:
    std::vector<MeshPtr> meshes;
    MeshPtr cube;

public:
    Scene();

    void addMesh(MeshPtr& mesh);
    [[nodiscard]] std::vector<MeshPtr> getMeshes() const;
    [[nodiscard]] MeshPtr getCube() const;
};

#endif //PTUT_SCENE_HPP
