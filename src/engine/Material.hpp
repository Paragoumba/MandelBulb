#ifndef PTUT_MATERIAL_HPP
#define PTUT_MATERIAL_HPP

#include <vector>
#include <memory>
//#include <glad/glad.h>

#include "Texture.hpp"
#include "exceptions/MaterialException.hpp"

class Material {
private:
    std::vector<Texture*> textures;

public:
    void addTexture(Texture* texture);
    void use();

    ~Material();

};

typedef std::shared_ptr<Material> MaterialPtr;

#endif //PTUT_MATERIAL_HPP
