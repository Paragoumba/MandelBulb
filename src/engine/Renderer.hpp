#ifndef PTUT_RENDERER_HPP
#define PTUT_RENDERER_HPP

#include "Shader.hpp"
#include "Scene.hpp"
#include "HUD.hpp"
#include "Camera.hpp"

class Renderer {
private:
    Shader sceneShader;
    Shader hudShader;

public:
    Renderer();

    void renderScene(Scene& scene, Camera& camera);
};

#endif //PTUT_RENDERER_HPP
