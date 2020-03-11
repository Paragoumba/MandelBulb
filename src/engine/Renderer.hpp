#ifndef PTUT_RENDERER_HPP
#define PTUT_RENDERER_HPP

#include "Shader.hpp"
#include "Camera.hpp"
#include "Window.hpp"
#include "FractalParams.hpp"
#include "Mesh.hpp"

/**
 * \class Renderer
 *
 * In this class there are serval functions that can be used in order to managed the render
 */
class Renderer {
private:
    Shader fractalShader;
    MeshPtr fractal;

    FractalParams *fractalParams;

public:
    Renderer();

    static int takeScreenshot(const char*);

    void renderFractal(Window& window, Camera& camera, float lightAngle);

    ~Renderer();
};

#endif //PTUT_RENDERER_HPP
