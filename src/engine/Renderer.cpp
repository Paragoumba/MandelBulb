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
#include "Utils.hpp"

/**
 * Constructor of Renderer
 *
 */
Renderer::Renderer() :
fractalShader(Utils::getPath("../res/shaders/mandel_raymarch.vs").c_str(),
        Utils::getPath("../res/shaders/mandel_raymarch.fs").c_str()){

    fractalParams = nullptr;

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
 * With this function we render a MandelBulb
 *
 * @param camera
 */
void Renderer::renderFractal(Window& window, Camera& camera, float lightAngle){

    if (fractalParams == nullptr)
        fractalParams = FractalParams::getInstance();

    fractalParams->setInverseVP(camera);
    fractalParams->setLightPos(glm::vec3(std::cos(lightAngle) * 10, 3.00, std::sin(lightAngle) * 10));

    fractalShader.use();

    fractalShader.setFloat("u_ambientIntensity", fractalParams->getAmbientIntensity());
    fractalShader.setFloat("u_bailLimit", fractalParams->getBailLimit());
    fractalShader.setFloat("u_baseColorStrength", fractalParams->getBaseColorStrength());

    //Color color = window.getColor();

    //fractalShader.setVec3("u_bgColor", glm::vec3(0.80, 0.85, 1.00));
    fractalShader.setVec3("u_bgColor", fractalParams->getBgColor());

    fractalShader.setInt("u_boxFoldFactor", fractalParams->getBoxFoldFactor());
    fractalShader.setFloat("u_boxFoldingLimit", fractalParams->getBoxFoldingLimit());
    fractalShader.setVec3("u_color0", fractalParams->getColor0());
    fractalShader.setVec3("u_color1", fractalParams->getColor1());
    fractalShader.setVec3("u_color2", fractalParams->getColor2());
    fractalShader.setVec3("u_color3", fractalParams->getColor3());
    fractalShader.setVec3("u_colorBase", fractalParams->getColorBase());
    fractalShader.setInt("u_derivativeBias", fractalParams->getDerivativeBias());
    fractalShader.setFloat("u_diffuseIntensity", fractalParams->getDiffuseIntensity());
    fractalShader.setVec3("u_eyePos", fractalParams->getEyePos());
    fractalShader.setInt("u_fractalIters", fractalParams->getFractalIters());
    fractalShader.setFloat("u_fudgeFactor", fractalParams->getFudgeFactor());
    fractalShader.setInt("u_gammaCorrection", fractalParams->getGammaCorrection());
    fractalShader.setVec3("u_glowColor", fractalParams->getGlowColor());
    fractalShader.setFloat("u_glowFactor", fractalParams->getGlowFactor());
    fractalShader.setInt("u_julia", fractalParams->getJulia());
    fractalShader.setVec3("u_juliaC", fractalParams->getJuliaC());

    fractalShader.setVec3("u_lightPos", fractalParams->getLightPos());

    fractalShader.setInt("u_lightSource", fractalParams->getLightSource());
    fractalShader.setInt("u_mandelBoxOn", fractalParams->getMandelBoxOn());
    fractalShader.setFloat("u_mandelBoxScale", fractalParams->getMandelBoxScale());
    fractalShader.setInt("u_mandelbulbOn", fractalParams->getMandelbulbOn());
    fractalShader.setFloat("u_maxRaySteps", fractalParams->getMaxRaySteps());
    fractalShader.setFloat("u_minDistance", fractalParams->getMinDistance());
    fractalShader.setFloat("u_noiseFactor", fractalParams->getNoiseFactor());
    fractalShader.setVec4("u_orbitStrength", fractalParams->getOrbitStrength());
    fractalShader.setFloat("u_otCycleIntensity", fractalParams->getOtCycleIntensity());
    fractalShader.setFloat("u_otDist0to1", fractalParams->getOtDist0to1());
    fractalShader.setFloat("u_otDist1to2", fractalParams->getOtDist1to2());
    fractalShader.setFloat("u_otDist2to3", fractalParams->getOtDist2to3());
    fractalShader.setFloat("u_otDist3to0", fractalParams->getOtDist3to0());
    fractalShader.setFloat("u_otPaletteOffset", fractalParams->getOtPaletteOffset());
    fractalShader.setFloat("u_phongShadingMixFactor", fractalParams->getPhongShadingMixFactor());
    fractalShader.setFloat("u_power", fractalParams->getPower());
    fractalShader.setVec2("u_screenSize", fractalParams->getScreenSize());
    fractalShader.setFloat("u_shadowBrightness", fractalParams->getShadowBrightness());
    fractalShader.setInt("u_shadowRayMinStepsTaken", fractalParams->getShadowRayMinStepsTaken());
    fractalShader.setFloat("u_shininess", fractalParams->getShininess());
    fractalShader.setInt("u_showBgGradient", fractalParams->getShowBgGradient());
    fractalShader.setFloat("u_specularIntensity", fractalParams->getSpecularIntensity());
    fractalShader.setFloat("u_sphereFixedRadius", fractalParams->getSphereFixedRadius());
    fractalShader.setInt("u_sphereFoldFactor", fractalParams->getSphereFoldFactor());
    fractalShader.setFloat("u_sphereMinRadius", fractalParams->getSphereMinRadius());
    fractalShader.setInt("u_sphereMinTimeVariance", fractalParams->getSphereMinTimeVariance());
    fractalShader.setInt("u_tetraFactor", fractalParams->getTetraFactor());
    fractalShader.setFloat("u_tetraScale", fractalParams->getTetraScale());
    fractalShader.setFloat("u_time", fractalParams->getTime());

    fractalShader.setFloat("u_nearPlane", fractalParams->getNearPlane());
    fractalShader.setFloat("u_farPlane", fractalParams->getFarPlane());
    fractalShader.setMat4("u_inverseVP", fractalParams->getInverseVP());

    fractal->render();

}
