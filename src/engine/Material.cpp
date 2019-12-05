#include <glad/glad.h>

#include "Material.hpp"

void Material::addTexture(Texture* texture){

    if (textures.size() < 32){

        textures.push_back(texture);

    } else {

        throw "Maximum 32 textures are supported.";

    }
}

void Material::use(){

    for (int i = 0; i < (int) textures.size(); ++i){

        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, textures[i]->getId());

    }
}

Material::~Material(){

    for (auto texture : textures){

        delete texture;

    }
}
