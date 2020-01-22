/**
 * \file Renderer.cpp
 * \brief Manage the render
 * \author DUSSERVAIX V., OVEJERO D., TESSON L., VIOLLET R.
 * \date 22 January 2020
 *
 * In this class there are serval functions that can be used in order to managed the render
 */
#include "Renderer.hpp"

#include <memory>
#include "Transformation.hpp"
#include "Mesh.hpp"

/**
 * \fn Renderer
 * \brief Constructor of Renderer
 *
 */
Renderer::Renderer() :
sceneShader("../res/shaders/scene_shader.vs", "../res/shaders/scene_shader.fs"),
fractalShader("../res/shaders/mandel_raymarch.vs", "../res/shaders/mandel_raymarch.fs"){

    float vertices[] = {
            -1.0f, -1.0f, 0.0f,
             1.0f, -1.0f, 0.0f,
            -1.0f,  1.0f, 0.0f,
             1.0f,  1.0f, 0.0f
    };

    float texCoords[] = {
    };

    unsigned int indices[] = {
            0, 1, 2,
            1, 3, 2
    };

    fractal = std::make_shared<Mesh>(vertices, sizeof(vertices), texCoords, sizeof(texCoords), indices, sizeof(indices));

    fractal->setPosition(0, 0, -50);

}

/**
 * \fn renderFractal
 * \brief With this function we render a MandelBulb
 *
 * @param camera
 */
void Renderer::renderFractal(Window& window, Camera& camera, float lightAngle){

    fractalShader.use();

    fractalShader.setFloat("u_ambientIntensity", 1.00);
    fractalShader.setFloat("u_bailLimit", 5.00);
    fractalShader.setFloat("u_baseColorStrength", 0.50);

    Color color = window.getColor();

    //fractalShader.setVec3("u_bgColor", glm::vec3(0.80, 0.85, 1.00));
    fractalShader.setVec3("u_bgColor", glm::vec3(color.r, color.g, color.b));

    fractalShader.setInt("u_boxFoldFactor", 0);
    fractalShader.setFloat("u_boxFoldingLimit", 1.00);
    fractalShader.setVec3("u_color0", glm::vec3(0.30, 0.50, 0.20));
    fractalShader.setVec3("u_color1", glm::vec3(0.60, 0.20, 0.50));
    fractalShader.setVec3("u_color2", glm::vec3(0.25, 0.70, 0.90));
    fractalShader.setVec3("u_color3", glm::vec3(0.20, 0.45, 0.25));
    fractalShader.setVec3("u_colorBase", glm::vec3(0.30, 0.60, 0.30));
    fractalShader.setInt("u_derivativeBias", 1);
    fractalShader.setFloat("u_diffuseIntensity", 1.00);
    fractalShader.setVec3("u_eyePos", glm::vec3(0.00, 0.00, 3.00));
    fractalShader.setInt("u_fractalIters", 1);
    fractalShader.setFloat("u_fudgeFactor", 1.00);
    fractalShader.setInt("u_gammaCorrection", 0);
    fractalShader.setVec3("u_glowColor", glm::vec3(0.75, 0.90, 1.00));
    fractalShader.setFloat("u_glowFactor", 1.00);
    fractalShader.setInt("u_julia", 0);
    fractalShader.setVec3("u_juliaC", glm::vec3(0.86, 0.23, -0.50));

    //fractalShader.setVec3("u_lightPos", glm::vec3(3.00, 3.00, 10.00));
    fractalShader.setVec3("u_lightPos", glm::vec3(std::cos(lightAngle) * 10, 3.00, std::sin(lightAngle) * 10));

    fractalShader.setInt("u_lightSource", 1);
    fractalShader.setInt("u_mandelBoxOn", 0);
    fractalShader.setFloat("u_mandelBoxScale", 1.20);
    fractalShader.setInt("u_mandelbulbOn", 1);
    fractalShader.setFloat("u_maxRaySteps", 1000.00);
    fractalShader.setFloat("u_minDistance", 1.00000E-05);
    fractalShader.setFloat("u_noiseFactor", 0.50);
    fractalShader.setVec4("u_orbitStrength", glm::vec4(-1.00, -1.80, -1.40, 1.30));
    fractalShader.setFloat("u_otCycleIntensity", 5.00);
    fractalShader.setFloat("u_otDist0to1", 0.30);
    fractalShader.setFloat("u_otDist1to2", 1.00);
    fractalShader.setFloat("u_otDist2to3", 0.40);
    fractalShader.setFloat("u_otDist3to0", 0.20);
    fractalShader.setFloat("u_otPaletteOffset", 0.00);
    fractalShader.setFloat("u_phongShadingMixFactor", 1.00);
    fractalShader.setFloat("u_power", 4);
    fractalShader.setVec2("u_screenSize", glm::vec2(800.00, 640.00));
    fractalShader.setFloat("u_shadowBrightness", 0.20);
    fractalShader.setInt("u_shadowRayMinStepsTaken", 5);
    fractalShader.setFloat("u_shininess", 32.00);
    fractalShader.setInt("u_showBgGradient", 1);
    fractalShader.setFloat("u_specularIntensity", 1.00);
    fractalShader.setFloat("u_sphereFixedRadius", 2.00);
    fractalShader.setInt("u_sphereFoldFactor", 0);
    fractalShader.setFloat("u_sphereMinRadius", 0.01);
    fractalShader.setInt("u_sphereMinTimeVariance", 0);
    fractalShader.setInt("u_tetraFactor", 0);
    fractalShader.setFloat("u_tetraScale", 1.00);
    fractalShader.setFloat("u_time", 2.6703);

    fractalShader.setFloat("u_nearPlane", 0.1f);
    fractalShader.setFloat("u_farPlane", 100.0f);
    fractalShader.setMat4("u_inverseVP", glm::inverse(Transformation::getViewMatrix(camera)) * glm::inverse(Transformation::getProjectionMatrix()));

    fractal->render();

}

/**
 * \fn renderScene
 * \brief Call the Shader to use it and render it
 *
 * @param scene
 * @param camera
 */
void Renderer::renderScene(Scene& scene, Camera& camera){

    sceneShader.use();

    sceneShader.setMat4("view", Transformation::getViewMatrix(camera));
    sceneShader.setMat4("projection", Transformation::getProjectionMatrix());

    std::vector<MeshPtr> meshes = scene.getMeshes();

    for (auto& mesh : meshes){

        sceneShader.setMat4("model", Transformation::getModelMatrix(mesh.get()));

        mesh->render();

    }
}
