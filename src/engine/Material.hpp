#ifndef PTUT_MATERIAL_HPP
#define PTUT_MATERIAL_HPP

#include <vector>
#include <memory>

#include "Texture.hpp"

/**
 * \class Material
 *
 * In this class there are serval functions that can be used in order to managed the Material
 */
class Material {
private:
    std::vector<Texture*> textures;

public:
    void use();

    ~Material();
};

typedef std::shared_ptr<Material> MaterialPtr;

#endif //PTUT_MATERIAL_HPP
