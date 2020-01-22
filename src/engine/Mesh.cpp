/**
 * \file Mesh.cpp
 * \brief Manage the vertices
 * \author DUSSERVAIX V., OVEJERO D., TESSON L., VIOLLET R.
 * \date 22 January 2020
 *
 * In this class there are serval functions that can be used in order to managed mesh
 */
#include <glad/glad.h>
#include <utility>

#include "Mesh.hpp"

/**
 * \fn Mesh
 * Constructor of Mesh
 *
 * @param vertices
 * @param verticesNumber
 * @param texCoords
 * @param texCoordsNumber
 * @param indices
 * @param indicesNumber
 */
Mesh::Mesh(const float* vertices, unsigned long verticesNumber, const float texCoords[], unsigned long texCoordsNumber,
        const unsigned int* indices, unsigned long indicesNumber) : Object(){

    this->verticesNumber = (int)(indicesNumber / sizeof(indices[0]));

    glGenVertexArrays(1, &vaoId);
    glBindVertexArray(vaoId);

    unsigned int vboId;

    glGenBuffers(1, &vboId);
    vboIds.push_back(vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, verticesNumber, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &vboId);
    vboIds.push_back(vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, texCoordsNumber, texCoords, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &vboId);
    vboIds.push_back(vboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesNumber, indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

/**
 * \fn render
 * we use the use function of the material to apply it in our mesh
 *
 */
void Mesh::render() const {

    if (material != nullptr){

        material->use();

    }

    glBindVertexArray(vaoId);
    glDrawElements(GL_TRIANGLES, verticesNumber, GL_UNSIGNED_INT, nullptr);

}

/**
 * \fn setMaterial
 * Select the material to use
 *
 * @param _material
 */
void Mesh::setMaterial(MaterialPtr _material){

    material = std::move(_material);

}

/**
 * \fn ~Mesh
 * Destructor of Mesh
 *
 */
Mesh::~Mesh(){

    // Delete the VBOs
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(vboIds.size(), &vboIds[0]);

    // Delete the VAO
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vaoId);

}
