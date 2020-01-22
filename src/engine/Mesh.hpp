#ifndef PTUT_MESH_HPP
#define PTUT_MESH_HPP

#include <vector>
#include <memory>

#include "Material.hpp"
#include "Object.hpp"

/**
 * \class Mesh
 *
 * In this class there are serval functions that can be used in order to managed mesh
 */
class Mesh : public Object {
private:
    unsigned int vaoId{};
    std::vector<unsigned int> vboIds;
    int verticesNumber{};

    MaterialPtr material = nullptr;

public:
    Mesh(const float vertices[], unsigned long verticesNumber, const float texCoords[], unsigned long texCoordsNumber,
         const unsigned int indices[], unsigned long indicesNumber);

    void render() const;

    void setMaterial(MaterialPtr _material);

    ~Mesh();
};

typedef std::shared_ptr<Mesh> MeshPtr;

#endif //PTUT_MESH_HPP
