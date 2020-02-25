#ifndef MANDELBULB_FRACTALPARAMS_HPP
#define MANDELBULB_FRACTALPARAMS_HPP

#include <glm/glm.hpp>

#include "Camera.hpp"
#include "Transformation.hpp"

class FractalParams{
private:

    static FractalParams* singleton;
    explicit FractalParams();

    float ambientIntensity;
    float bailLimit;
    float baseColorStrength;
    glm::vec3 bgColor;
    int boxFoldFactor;
    float boxFoldingLimit;
    glm::vec3 color0;
    glm::vec3 color1;
    glm::vec3 color2;
    glm::vec3 color3;
    glm::vec3 colorBase;
    int derivativeBias;
    float diffuseIntensity;
    glm::vec3 eyePos;
    int fractalIters;
    float fudgeFactor;
    int gammaCorrection;
    glm::vec3 glowColor;
    float glowFactor;
    int julia;
    glm::vec3 juliaC;
    float lightAngle;
    glm::vec3 lightPos;
    int lightSource;
    int mandelBoxOn;
    float mandelBoxScale;
    int mandelbulbOn;
    float maxRaySteps;
    float minDistance;
    float noiseFactor;
    glm::vec4 orbitStrength;
    float otCycleIntensity;
    float otDist0to1;
    float otDist1to2;
    float otDist2to3;
    float otDist3to0;
    float otPaletteOffset;
    float phongShadingMixFactor;
    float power;
    glm::vec2 screenSize;
    float shadowBrightness;
    int shadowRayMinStepsTaken;
    float shininess;
    int showBgGradient;
    float specularIntensity;
    float sphereFixedRadius;
    int sphereFoldFactor;
    float sphereMinRadius;
    int sphereMinTimeVariance;
    int tetraFactor;
    float tetraScale;
    float time;
    float nearPlane;
    float farPlane;
    glm::mat4 inverseVP;

public:

    FractalParams(const FractalParams&) = delete;
    FractalParams& operator=(const FractalParams&) = delete;
    static FractalParams* getInstance();

    float getAmbientIntensity();
    float getBailLimit();
    float getBaseColorStrength();
    glm::vec3 getBgColor();
    int getBoxFoldFactor();
    float getBoxFoldingLimit();
    glm::vec3 getColor0();
    glm::vec3 getColor1();
    glm::vec3 getColor2();
    glm::vec3 getColor3();
    glm::vec3 getColorBase();
    int getDerivativeBias();
    float getDiffuseIntensity();
    glm::vec3 getEyePos();
    int getFractalIters();
    float getFudgeFactor();
    int getGammaCorrection();
    glm::vec3 getGlowColor();
    float getGlowFactor();
    int getJulia();
    glm::vec3 getJuliaC();
    float getLightAngle();
    glm::vec3 getLightPos();
    int getLightSource();
    int getMandelBoxOn();
    float getMandelBoxScale();
    int getMandelbulbOn();
    float getMaxRaySteps();
    float getMinDistance();
    float getNoiseFactor();
    glm::vec4 getOrbitStrength();
    float getOtCycleIntensity();
    float getOtDist0to1();
    float getOtDist1to2();
    float getOtDist2to3();
    float getOtDist3to0();
    float getOtPaletteOffset();
    float getPhongShadingMixFactor();
    float getPower();
    glm::vec2 getScreenSize();
    float getShadowBrightness();
    int getShadowRayMinStepsTaken();
    float getShininess();
    int getShowBgGradient();
    float getSpecularIntensity();
    float getSphereFixedRadius();
    int getSphereFoldFactor();
    float getSphereMinRadius();
    int getSphereMinTimeVariance();
    int getTetraFactor();
    float getTetraScale();
    float getTime();
    float getNearPlane();
    float getFarPlane();
    glm::mat4 getInverseVP();

    void reset();

    void setAmbientIntensity(float);
    void setBailLimit(float);
    void setBaseColorStrength(float);
    void setBgColor(glm::vec3);
    void setBoxFoldFactor(int);
    void setBoxFoldingLimit(float);
    void setColor0(glm::vec3);
    void setColor1(glm::vec3);
    void setColor2(glm::vec3);
    void setColor3(glm::vec3);
    void setColorBase(glm::vec3);
    void setDerivativeBias(int);
    void setDiffuseIntensity(float);
    void setEyePos(glm::vec3);
    void setFractalIters(int);
    void setFudgeFactor(float);
    void setGammaCorrection(int);
    void setGlowColor(glm::vec3);
    void setGlowFactor(float);
    void setJulia(int);
    void setJuliaC(glm::vec3);
    void setLightAngle(float);
    void setLightPos(glm::vec3);
    void setLightSource(int);
    void setMandelBoxOn(int);
    void setMandelBoxScale(float);
    void setMandelbulbOn(int);
    void setMaxRaySteps(float);
    void setMinDistance(float);
    void setNoiseFactor(float);
    void setOrbitStrength(glm::vec4);
    void setOtCycleIntensity(float);
    void setOtDist0to1(float);
    void setOtDist1to2(float);
    void setOtDist2to3(float);
    void setOtDist3to0(float);
    void setOtPaletteOffset(float);
    void setPhongShadingMixFactor(float);
    void setPower(float);
    void setScreenSize(glm::vec2);
    void setShadowBrightness(float);
    void setShadowRayMinStepsTaken(int);
    void setShininess(float);
    void setShowBgGradient(int);
    void setSpecularIntensity(float);
    void setSphereFixedRadius(float);
    void setSphereFoldFactor(int);
    void setSphereMinRadius(float);
    void setSphereMinTimeVariance(int);
    void setTetraFactor(int);
    void setTetraScale(float);
    void setTime(float);
    void setNearPlane(float);
    void setFarPlane(float);
    void setInverseVP(Camera& camera, glm::mat4 = (glm::mat4)(const float)NULL);

    ~FractalParams() = default;

};

#endif //MANDELBULB_FRACTALPARAMS_HPP