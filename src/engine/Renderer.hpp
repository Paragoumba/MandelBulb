#ifndef PTUT_RENDERER_HPP
#define PTUT_RENDERER_HPP

#include "Scene.hpp"
#include "HUD.hpp"
#include "Transformation.hpp"

class Renderer {
private:
    Shader sceneShader;
    Shader hudShader;

public:
    Renderer();

    void renderScene(Scene& scene, Camera& camera);
    void renderHUD(HUD& hud);

};

#endif //PTUT_RENDERER_HPP
