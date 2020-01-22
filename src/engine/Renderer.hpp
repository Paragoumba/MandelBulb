#ifndef PTUT_RENDERER_HPP
#define PTUT_RENDERER_HPP

#include "Shader.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Window.hpp"

class Renderer {
private:
    Shader sceneShader;
    Shader fractalShader;

    MeshPtr fractal;

public:
    Renderer();

    void renderFractal(Window& window, Camera& camera, float lightAngle);
    void renderScene(Scene& scene, Camera& camera);
};

#endif //PTUT_RENDERER_HPP
