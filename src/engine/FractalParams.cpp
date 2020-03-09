#include "FractalParams.hpp"

FractalParams *FractalParams::singleton = nullptr;

FractalParams::FractalParams(){

    reset();

}

FractalParams* FractalParams::getInstance(){

    if (!singleton)
        singleton = new FractalParams();
    return singleton;

}

float FractalParams::getAmbientIntensity() { return ambientIntensity; }
float FractalParams::getBailLimit() { return bailLimit; }
float FractalParams::getBaseColorStrength() { return baseColorStrength; }
glm::vec3 FractalParams::getBgColor() { return bgColor; }
int FractalParams::getBoxFoldFactor() { return boxFoldFactor; }
float FractalParams::getBoxFoldingLimit() { return boxFoldingLimit; }
glm::vec3 FractalParams::getColor0() { return color0; }
glm::vec3 FractalParams::getColor1() { return color1; }
glm::vec3 FractalParams::getColor2() { return color2; }
glm::vec3 FractalParams::getColor3() { return color3; }
glm::vec3 FractalParams::getColorBase() { return colorBase; }
int FractalParams::getDerivativeBias() { return derivativeBias; }
float FractalParams::getDiffuseIntensity() { return diffuseIntensity; }
glm::vec3 FractalParams::getEyePos() { return eyePos; }
int FractalParams::getFractalIters() { return fractalIters; }
float FractalParams::getFudgeFactor() { return fudgeFactor; }
int FractalParams::getGammaCorrection() { return gammaCorrection; }
glm::vec3 FractalParams::getGlowColor() { return glowColor; }
float FractalParams::getGlowFactor() { return glowFactor; }
int FractalParams::getJulia() { return julia; }
glm::vec3 FractalParams::getJuliaC() { return juliaC; }
glm::vec3 FractalParams::getLightPos() { return lightPos; }
int FractalParams::getLightSource() { return lightSource; }
int FractalParams::getMandelBoxOn() { return mandelBoxOn; }
float FractalParams::getMandelBoxScale() { return mandelBoxScale; }
int FractalParams::getMandelbulbOn() { return mandelbulbOn; }
float FractalParams::getMaxRaySteps() { return maxRaySteps; }
float FractalParams::getMinDistance() { return minDistance; }
float FractalParams::getNoiseFactor() { return noiseFactor; }
glm::vec4 FractalParams::getOrbitStrength() { return orbitStrength; }
float FractalParams::getOtCycleIntensity() { return otCycleIntensity; }
float FractalParams::getOtDist0to1() { return otDist0to1; }
float FractalParams::getOtDist1to2() { return otDist1to2; }
float FractalParams::getOtDist2to3() { return otDist2to3; }
float FractalParams::getOtDist3to0() { return otDist3to0; }
float FractalParams::getOtPaletteOffset() { return otPaletteOffset; }
float FractalParams::getPhongShadingMixFactor() { return phongShadingMixFactor; }
float FractalParams::getPower() { return power; }
glm::vec2 FractalParams::getScreenSize() { return screenSize; }
float FractalParams::getShadowBrightness() { return shadowBrightness; }
int FractalParams::getShadowRayMinStepsTaken() { return shadowRayMinStepsTaken; }
float FractalParams::getShininess() { return shininess; }
int FractalParams::getShowBgGradient() { return showBgGradient; }
float FractalParams::getSpecularIntensity() { return specularIntensity; }
float FractalParams::getSphereFixedRadius() { return sphereFixedRadius; }
int FractalParams::getSphereFoldFactor() { return sphereFoldFactor; }
float FractalParams::getSphereMinRadius() { return sphereMinRadius; }
int FractalParams::getSphereMinTimeVariance() { return sphereMinTimeVariance; }
int FractalParams::getTetraFactor() { return tetraFactor; }
float FractalParams::getTetraScale() { return tetraScale; }
float FractalParams::getTime() { return time; }
float FractalParams::getNearPlane() { return nearPlane; }
float FractalParams::getFarPlane() { return farPlane; }
glm::mat4 FractalParams::getInverseVP() { return inverseVP; }

// TODO Fix warnings
void FractalParams::setAmbientIntensity(float ambientIntensity = (float)NULL) {
    this->ambientIntensity = (ambientIntensity == (float)NULL)?1.0f:ambientIntensity;
}
void FractalParams::setBailLimit(float bailLimit = (float)NULL) {
    this->bailLimit = (bailLimit == (float)NULL)?5.0f:bailLimit;
}
void FractalParams::setBaseColorStrength(float baseColorStrength = (float)NULL) {
    this->baseColorStrength = (baseColorStrength == (float)NULL)?.5f:baseColorStrength;
}
void FractalParams::setBgColor(glm::vec3 bgColor = (glm::vec3)(float)NULL) {
    this->bgColor = (bgColor == (glm::vec3)(float)NULL)?glm::vec3(119, 41, 83):bgColor;
}
void FractalParams::setBoxFoldFactor(int boxFoldFactor = (int)NULL) {
    this->boxFoldFactor = (boxFoldFactor == (int)NULL)?0:boxFoldFactor;
}
void FractalParams::setBoxFoldingLimit(float boxFoldingLimit = (float)NULL) {
    this->boxFoldingLimit = (boxFoldingLimit == (float)NULL)?1.0f:boxFoldingLimit;
}
void FractalParams::setColor0(glm::vec3 color0 = (glm::vec3)(float)NULL) {
    this->color0 = (color0 == (glm::vec3)(float)NULL)?glm::vec3(0.30, 0.50, 0.20):color0;
}
void FractalParams::setColor1(glm::vec3 color1 = (glm::vec3)(float)NULL) {
    this->color1 = (color1 == (glm::vec3)(float)NULL)?glm::vec3(0.60, 0.20, 0.50):color1;
}
void FractalParams::setColor2(glm::vec3 color2 = (glm::vec3)(float)NULL) {
    this->color2 = (color2 == (glm::vec3)(float)NULL)?glm::vec3(0.25, 0.70, 0.90):color2;
}
void FractalParams::setColor3(glm::vec3 color3 = (glm::vec3)(float)NULL) {
    this->color3 = (color3 == (glm::vec3)(float)NULL)?glm::vec3(0.20, 0.45, 0.25):color3;
}
void FractalParams::setColorBase(glm::vec3 colorBase = (glm::vec3)(float)NULL) {
    this->colorBase = (colorBase == (glm::vec3)(float)NULL)?glm::vec3(0.30, 0.60, 0.30):colorBase;
}
void FractalParams::setDerivativeBias(int derivativeBias = (int)NULL) {
    this->derivativeBias = (derivativeBias == (int)NULL)?1:derivativeBias;
}
void FractalParams::setDiffuseIntensity(float diffuseIntensity = (float)NULL) {
    this->diffuseIntensity = (diffuseIntensity == (float)NULL)?1.0f:diffuseIntensity;
}
void FractalParams::setEyePos(glm::vec3 eyePos = (glm::vec3)(float)NULL) {
    this->eyePos = (eyePos == (glm::vec3)(float)NULL)?glm::vec3(0.00, 0.00, 3.00):eyePos;
}
void FractalParams::setFractalIters(int fractalIters = (int)NULL) {
    this->fractalIters = (fractalIters == (int)NULL)?1:fractalIters;
}
void FractalParams::setFudgeFactor(float fudgeFactor = (float)NULL) {
    this->fudgeFactor = (fudgeFactor == (float)NULL)?1.0f:fudgeFactor;
}
void FractalParams::setGammaCorrection(int gammaCorrection = (int)NULL) {
    this->gammaCorrection = (gammaCorrection == (int)NULL)?0:gammaCorrection;
}
void FractalParams::setGlowColor(glm::vec3 glowColor = (glm::vec3)(float)NULL) {
    this->glowColor = (glowColor == (glm::vec3)(float)NULL)?glm::vec3(0.75, 0.90, 1.00):glowColor;
}
void FractalParams::setGlowFactor(float glowFactor = (float)NULL) {
    this->glowFactor = (glowFactor == (float)NULL)?1.0f:glowFactor;
}
void FractalParams::setJulia(int julia = (int)NULL) {
    this->julia = (julia == (int)NULL)?0:julia;
}
void FractalParams::setJuliaC(glm::vec3 juliaC = (glm::vec3)(float)NULL) {
    this->juliaC = (juliaC == (glm::vec3)(float)NULL)?glm::vec3(0.86, 0.23, -0.50):juliaC;
}
void FractalParams::setLightPos(glm::vec3 lightPos = (glm::vec3)(float)NULL) {
    this->lightPos = (lightPos == (glm::vec3)(float)NULL)?glm::vec3(1.00, 3.00, 1.00):lightPos;
}
void FractalParams::setLightSource(int lightSource = (int)NULL) {
    this->lightSource = (lightSource == (int)NULL)?1:lightSource;
}
void FractalParams::setMandelBoxOn(int mandelBoxOn = (bool)true) {
    this->mandelBoxOn = mandelBoxOn;
}
void FractalParams::setMandelBoxScale(float mandelBoxScale = (float)NULL) {
    this->mandelBoxScale = (mandelBoxScale == (float)NULL)?1.2f:mandelBoxScale;
}
void FractalParams::setMandelbulbOn(int mandelbulbOn = (int)true) {
    this->mandelbulbOn = mandelbulbOn;
}
void FractalParams::setMaxRaySteps(float maxRaySteps = (float)NULL) {
    this->maxRaySteps = (maxRaySteps == (float)NULL)?1000.0f:maxRaySteps;
}
void FractalParams::setMinDistance(float minDistance = (float)NULL) {
    this->minDistance = (minDistance == (float)NULL)?1.00000E-05:minDistance;
}
void FractalParams::setNoiseFactor(float noiseFactor = (float)NULL) {
    this->noiseFactor = (noiseFactor == (float)NULL)?0.5f:noiseFactor;
}
void FractalParams::setOrbitStrength(glm::vec4 orbitStrength = (glm::vec4)(float)NULL) {
    this->orbitStrength = (orbitStrength == (glm::vec4)(float)NULL)?glm::vec4(-1.00, -1.80, -1.40, 1.30):orbitStrength;
}
void FractalParams::setOtCycleIntensity(float otCycleIntensity = (float)NULL) {
    this->otCycleIntensity = (otCycleIntensity == (float)NULL)?5.0f:otCycleIntensity;
}
void FractalParams::setOtDist0to1(float otDist0to1 = (float)NULL) {
    this->otDist0to1 = (otDist0to1 == (float)NULL)?0.3f:otDist0to1;
}
void FractalParams::setOtDist1to2(float otDist1to2 = (float)NULL) {
    this->otDist1to2 = (otDist1to2 == (float)NULL)?1.0f:otDist1to2;
}
void FractalParams::setOtDist2to3(float otDist2to3 = (float)NULL) {
    this->otDist2to3 = (otDist2to3 == (float)NULL)?0.4f:otDist2to3;
}
void FractalParams::setOtDist3to0(float otDist3to0 = (float)NULL) {
    this->otDist3to0 = (otDist3to0 == (float)NULL)?0.2f:otDist3to0;
}
void FractalParams::setOtPaletteOffset(float otPaletteOffset = (float)NULL) {
    this->otPaletteOffset = (otPaletteOffset == (float)NULL)?0.0f:otPaletteOffset;
}
void FractalParams::setPhongShadingMixFactor(float phongShadingMixFactor = (float)NULL) {
    this->phongShadingMixFactor = (phongShadingMixFactor == (float)NULL)?1.0f:phongShadingMixFactor;
}
void FractalParams::setPower(float power = (float)NULL) {
    this->power = (power == (float)NULL)?8.0f:power;
}
void FractalParams::setScreenSize(glm::vec2 screenSize = (glm::vec2)(float)NULL) {
    this->screenSize = (screenSize == (glm::vec2)(float)NULL)?glm::vec2(800.00, 640.00):screenSize;
}
void FractalParams::setShadowBrightness(float shadowBrightness = (float)NULL) {
    this->shadowBrightness = (shadowBrightness == (float)NULL)?0.2f:shadowBrightness;
}
void FractalParams::setShadowRayMinStepsTaken(int shadowRayMinStepsTaken = (int)NULL) {
    this->shadowRayMinStepsTaken = (shadowRayMinStepsTaken == (int)NULL)?5:shadowRayMinStepsTaken;
}
void FractalParams::setShininess(float shininess = (float)NULL) {
    this->shininess = (shininess == (float)NULL)?32.0f:shininess;
}
void FractalParams::setShowBgGradient(int showBgGradient = (int)true) {
    this->showBgGradient = showBgGradient;
}
void FractalParams::setSpecularIntensity(float specularIntensity = (float)NULL) {
    this->specularIntensity = (specularIntensity == (float)NULL)?1.0f:specularIntensity;
}
void FractalParams::setSphereFixedRadius(float sphereFixedRadius = (float)NULL) {
    this->sphereFixedRadius = (sphereFixedRadius == (float)NULL)?2.0f:sphereFixedRadius;
}
void FractalParams::setSphereFoldFactor(int sphereFoldFactor = (int)NULL) {
    this->sphereFoldFactor = (sphereFoldFactor == (int)NULL)?0:sphereFoldFactor;
}
void FractalParams::setSphereMinRadius(float sphereMinRadius = (float)NULL) {
    this->sphereMinRadius = (sphereMinRadius == (float)NULL)?0.01f:sphereMinRadius;
}
void FractalParams::setSphereMinTimeVariance(int sphereMinTimeVariance = (int)NULL) {
    this->sphereMinTimeVariance = (sphereMinTimeVariance == (int)NULL)?0:sphereMinTimeVariance;
}
void FractalParams::setTetraFactor(int tetraFactor = (int)NULL) {
    this->tetraFactor = (tetraFactor == (int)NULL)?0:tetraFactor;
}
void FractalParams::setTetraScale(float tetraScale = (float)NULL) {
    this->tetraScale = (tetraScale == (float)NULL)?1.0f:tetraScale;
}
void FractalParams::setTime(float time = (float)NULL) {
    this->time = (time == (float)NULL)?2.6703f:time;
}
void FractalParams::setNearPlane(float nearPlane = (float)NULL) {
    this->nearPlane = (nearPlane == (float)NULL)?0.1f:nearPlane;
}
void FractalParams::setFarPlane(float farPlane = (float)NULL) {
    this->farPlane = (farPlane == (float)NULL)?100.0f:farPlane;
}
void FractalParams::setInverseVP(Camera& camera, glm::mat4 inverseVP) {
    this->inverseVP = (inverseVP == (glm::mat4)(const float)NULL)?glm::inverse(Transformation::getViewMatrix(camera)) * glm::inverse(Transformation::getProjectionMatrix()):inverseVP;
}

void FractalParams::reset() {

    setAmbientIntensity();
    setBailLimit();
    setBaseColorStrength();
    setBgColor();
    setBoxFoldFactor();
    setBoxFoldingLimit();
    setColor0();
    setColor1();
    setColor2();
    setColor3();
    setColorBase();
    setDerivativeBias();
    setDiffuseIntensity();
    setEyePos();
    setFractalIters();
    setFudgeFactor();
    setGammaCorrection();
    setGlowColor();
    setGlowFactor();
    setJulia();
    setJuliaC();
    setLightPos();
    setLightSource();
    setMandelBoxOn();
    setMandelBoxScale();
    setMandelbulbOn();
    setMaxRaySteps();
    setMinDistance();
    setNoiseFactor();
    setOrbitStrength();
    setOtCycleIntensity();
    setOtDist0to1();
    setOtDist1to2();
    setOtDist2to3();
    setOtDist3to0();
    setOtPaletteOffset();
    setPhongShadingMixFactor();
    setPower();
    setScreenSize();
    setShadowBrightness();
    setShadowRayMinStepsTaken();
    setShininess();
    setShowBgGradient();
    setSpecularIntensity();
    setSphereFixedRadius();
    setSphereFoldFactor();
    setSphereMinRadius();
    setSphereMinTimeVariance();
    setTetraFactor();
    setTetraScale();
    setTime();
    setNearPlane();
    setFarPlane();

}

FractalParams::~FractalParams() {

    delete singleton;

}