#ifndef PTUT_TEXTURE_HPP
#define PTUT_TEXTURE_HPP
/**
 * \author R.VIOLET, L.TESSON, D.OVEJERO, V.DUSSERVAIX
 * \version 0.1
 * \date 22 january 2020
 *
 * Program to manage the Textures of the program
 **/
#include <string>
/**
 * \class Texture
 * Manage the textures of the program
 */
class Texture {
private:
    unsigned int textureId{};/*!< Id of the texture */
    int width{};/*!< Width of the texture */
    int height{};/*!< Height of the texture */

public:
    /**
     *  load texture
     * @param path
     */
    explicit Texture(const char* path);
    /**
     *  return the id of texture
     * @return
     */
    [[nodiscard]] unsigned int getId() const;
    /**
     *  return the width of this texture
     * @return
     */
    [[nodiscard]] int getWidth() const;
    /**
     * return the height of this texture
     * @return
     */
    [[nodiscard]] int getHeight() const;
    /**
     *  Destructor of class Texture
       */
    ~Texture();
};

#endif //PTUT_TEXTURE_HPP
