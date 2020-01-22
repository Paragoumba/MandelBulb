/**
 * \author R.VIOLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
 * \version 0.1
 * \date 22 january 2020
 *
 * Program to manage the textures of the program
 **/
#include <glad/glad.h>
#include <stb/stb_image.h>
#include <iostream>

#include "Texture.hpp"

/**
 * \fn Texture(const char* path)
 *  load texture
 * @param path, the file
 */
Texture::Texture(const char* path){

    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int nrChannels;

    // load image, create texture and generate mipmaps
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

    if (data){

        glTexImage2D(GL_TEXTURE_2D, 0, nrChannels == 4 ? GL_RGBA : GL_RGB, width, height, 0,
                nrChannels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

    } else {

        std::cerr << "Failed to load texture." << std::endl;

    }

    stbi_image_free(data);

}

/**
 * \fn unsigned int getId(void)
 *  return the id of texture
 *
 * @return int, id of the texture
 */
unsigned int Texture::getId() const {

    return textureId;

}

/**
 * \fn int getWidth() const
 *  return the width of this texture
 *
 * @return int
 */
int Texture::getWidth() const {

    return width;

}

/**
 * \fn int getHeight() const
 *  return the height of this texture
 *
 * @return int
 */
int Texture::getHeight() const {

    return height;

}
/**
 * \fn ~Texture()
 *  Destructor of class Texture
 */
Texture::~Texture(){

    glDeleteTextures(1, &textureId);

}
