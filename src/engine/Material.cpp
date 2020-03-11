/**
 * \file Material.cpp
 * \brief Manage the material
 * \author DUSSERVAIX V., OVEJERO D., TESSON L., VIOLLET R.
 * \date 22 January 2020
 *
 * In this class there are serval functions that can be used in order to managed the Material
 */
#include <glad/glad.h>

#include "Material.hpp"
#include "exceptions/Exception.hpp"


/**
 * apply the texture to objects
 *
 */
void Material::use(){

    for (int i = 0; i < (int) textures.size(); ++i){

        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, textures[i]->getId());

    }
}

/**
 * Destructor of Material, destroy all the Texture object in the vector
 *
 */
Material::~Material(){

    for (auto texture : textures){

        delete texture;

    }
}
