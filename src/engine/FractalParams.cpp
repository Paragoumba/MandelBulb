#include "FractalParams.hpp"

FractalParams::FractalParams(Camera camera) {

    setCamera(camera);
    reset();

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
float FractalParams::getLightAngle() { return lightAngle; }
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

void FractalParams::setAmbientIntensity(float ambientIntensity = NULL) {
    this->ambientIntensity = (ambientIntensity == NULL)?1.0f:ambientIntensity;
}
void FractalParams::setBailLimit(float bailLimit = NULL) {
    this->bailLimit = (bailLimit == NULL)?5.0f:bailLimit;
}
void FractalParams::setBaseColorStrength(float baseColorStrength = NULL) {
    this->baseColorStrength = (baseColorStrength == NULL)?.5f:baseColorStrength;
}
void FractalParams::setBgColor(glm::vec3 bgColor = (glm::vec3)NULL) {
    this->bgColor = (bgColor == (glm::vec3)NULL)?glm::vec3(119, 41, 83):bgColor;
}
void FractalParams::setBoxFoldFactor(int boxFoldFactor = NULL) {
    this->boxFoldFactor = (boxFoldFactor == NULL)?0:boxFoldFactor;
}
void FractalParams::setBoxFoldingLimit(float boxFoldingLimit = NULL) {
    this->boxFoldingLimit = (boxFoldingLimit == NULL)?1.0f:boxFoldingLimit;
}
void FractalParams::setColor0(glm::vec3 color0 = (glm::vec3)NULL) {
    this->color0 = (color0 == (glm::vec3)NULL)?glm::vec3(0.30, 0.50, 0.20):color0;
}
void FractalParams::setColor1(glm::vec3 color1 = (glm::vec3)NULL) {
    this->color1 = (color1 == (glm::vec3)NULL)?glm::vec3(0.60, 0.20, 0.50):color1;
}
void FractalParams::setColor2(glm::vec3 color2 = (glm::vec3)NULL) {
    this->color2 = (color2 == (glm::vec3)NULL)?glm::vec3(0.25, 0.70, 0.90):color2;
}
void FractalParams::setColor3(glm::vec3 color3 = (glm::vec3)NULL) {
    this->color3 = (color3 == (glm::vec3)NULL)?glm::vec3(0.20, 0.45, 0.25):color3;
}
void FractalParams::setColorBase(glm::vec3 colorBase = (glm::vec3)NULL) {
    this->colorBase = (colorBase == (glm::vec3)NULL)?glm::vec3(0.30, 0.60, 0.30):colorBase;
}
void FractalParams::setDerivativeBias(int derivativeBias = NULL) {
    this->derivativeBias = (derivativeBias == NULL)?1:derivativeBias;
}
void FractalParams::setDiffuseIntensity(float diffuseIntensity = NULL) {
    this->diffuseIntensity = (diffuseIntensity == NULL)?1.0f:diffuseIntensity;
}
void FractalParams::setEyePos(glm::vec3 eyePos = (glm::vec3)NULL) {
    this->eyePos = (eyePos == (glm::vec3)NULL)?glm::vec3(0.00, 0.00, 3.00):eyePos;
}
void FractalParams::setFractalIters(int fractalIters = NULL) {
    this->fractalIters = (fractalIters == NULL)?1:fractalIters;
}
void FractalParams::setFudgeFactor(float fudgeFactor = NULL) {
    this->fudgeFactor = (fudgeFactor == NULL)?1.0f:fudgeFactor;
}
void FractalParams::setGammaCorrection(int gammaCorrection = NULL) {
    this->gammaCorrection = (gammaCorrection == NULL)?0:gammaCorrection;
}
void FractalParams::setGlowColor(glm::vec3 glowColor = (glm::vec3)NULL) {
    this->glowColor = (glowColor == (glm::vec3)NULL)?glm::vec3(0.75, 0.90, 1.00):glowColor;
}
void FractalParams::setGlowFactor(float glowFactor = NULL) {
    this->glowFactor = (glowFactor == NULL)?1.0f:glowFactor;
}
void FractalParams::setJulia(int julia = NULL) {
    this->julia = (julia == NULL)?0:julia;
}
void FractalParams::setJuliaC(glm::vec3 juliaC = (glm::vec3)NULL) {
    this->juliaC = (juliaC == (glm::vec3)NULL)?glm::vec3(0.86, 0.23, -0.50):juliaC;
}
void FractalParams::setLightAngle(float lightAngle = NULL) {
    this->lightAngle = (lightAngle == NULL)?0:lightAngle;
}
void FractalParams::setLightPos(glm::vec3 lightPos = (glm::vec3)NULL) {
    this->lightPos = (lightPos == (glm::vec3)NULL)?glm::vec3(std::cos(lightAngle) * 10, 3.00, std::sin(lightAngle) * 10):lightPos;
}
void FractalParams::setLightSource(int lightSource = NULL) {
    this->lightSource = (lightSource == NULL)?1:lightSource;
}
void FractalParams::setMandelBoxOn(int mandelBoxOn = NULL) {
    this->mandelBoxOn = (mandelBoxOn == NULL)?0:mandelBoxOn;
}
void FractalParams::setMandelBoxScale(float mandelBoxScale = NULL) {
    this->mandelBoxScale = (mandelBoxScale == NULL)?1.2f:mandelBoxScale;
}
void FractalParams::setMandelbulbOn(int mandelbulbOn = NULL) {
    this->mandelbulbOn = (mandelbulbOn == NULL)?1:mandelbulbOn;
}
void FractalParams::setMaxRaySteps(float maxRaySteps = NULL) {
    this->maxRaySteps = (maxRaySteps == NULL)?1000.0f:maxRaySteps;
}
void FractalParams::setMinDistance(float minDistance = NULL) {
    this->minDistance = (minDistance == NULL)?1.00000E-05:minDistance;
}
void FractalParams::setNoiseFactor(float noiseFactor = NULL) {
    this->noiseFactor = (noiseFactor == NULL)?0.5f:noiseFactor;
}
void FractalParams::setOrbitStrength(glm::vec4 orbitStrength = (glm::vec4)NULL) {
    this->orbitStrength = (orbitStrength == (glm::vec4)orbitStrength)?glm::vec4(-1.00, -1.80, -1.40, 1.30):orbitStrength;
}
void FractalParams::setOtCycleIntensity(float otCycleIntensity = NULL) {
    this->otCycleIntensity = (otCycleIntensity == NULL)?5.0f:otCycleIntensity;
}
void FractalParams::setOtDist0to1(float otDist0to1 = NULL) {
    this->otDist0to1 = (otDist0to1 == NULL)?0.3f:otDist0to1;
}
void FractalParams::setOtDist1to2(float otDist1to2 = NULL) {
    this->otDist1to2 = (otDist1to2 == NULL)?1.0f:otDist1to2;
}
void FractalParams::setOtDist2to3(float otDist2to3 = NULL) {
    this->otDist2to3 = (otDist2to3 == NULL)?0.4f:otDist2to3;
}
void FractalParams::setOtDist3to0(float otDist3to0 = NULL) {
    this->otDist3to0 = (otDist3to0 == NULL)?0.2f:otDist3to0;
}
void FractalParams::setOtPaletteOffset(float otPaletteOffset = NULL) {
    this->otPaletteOffset = (otPaletteOffset == NULL)?0.0f:otPaletteOffset;
}
void FractalParams::setPhongShadingMixFactor(float phongShadingMixFactor = NULL) {
    this->phongShadingMixFactor = (phongShadingMixFactor == NULL)?1.0f:phongShadingMixFactor;
}
void FractalParams::setPower(float power = NULL) {
    this->power = (power == NULL)?8.0f:power;
}
void FractalParams::setScreenSize(glm::vec2 screenSize = (glm::vec2)NULL) {
    this->screenSize = (screenSize == (glm::vec2)NULL)?glm::vec2(800.00, 640.00):screenSize;
}
void FractalParams::setShadowBrightness(float shadowBrightness = NULL) {
    this->shadowBrightness = (shadowBrightness == NULL)?0.2f:shadowBrightness;
}
void FractalParams::setShadowRayMinStepsTaken(int shadowRayMinStepsTaken = NULL) {
    this->shadowRayMinStepsTaken = (shadowRayMinStepsTaken == NULL)?5:shadowRayMinStepsTaken;
}
void FractalParams::setShininess(float shininess = NULL) {
    this->shininess = (shininess == NULL)?32.0f:shininess;
}
void FractalParams::setShowBgGradient(int showBgGradient = NULL) {
    this->showBgGradient = (showBgGradient == NULL)?1:showBgGradient;
}
void FractalParams::setSpecularIntensity(float specularIntensity = NULL) {
    this->specularIntensity = (specularIntensity == NULL)?1.0f:specularIntensity;
}
void FractalParams::setSphereFixedRadius(float sphereFixedRadius = NULL) {
    this->sphereFixedRadius = (sphereFixedRadius == NULL)?2.0f:sphereFixedRadius;
}
void FractalParams::setSphereFoldFactor(int sphereFoldFactor = NULL) {
    this->sphereFoldFactor = (sphereFoldFactor == NULL)?0:sphereFoldFactor;
}
void FractalParams::setSphereMinRadius(float sphereMinRadius = NULL) {
    this->sphereMinRadius = (sphereMinRadius == NULL)?0.01f:sphereMinRadius;
}
void FractalParams::setSphereMinTimeVariance(int sphereMinTimeVariance = NULL) {
    this->sphereMinTimeVariance = (sphereMinTimeVariance == NULL)?0:sphereMinTimeVariance;
}
void FractalParams::setTetraFactor(int tetraFactor = NULL) {
    this->tetraFactor = (tetraFactor == NULL)?0:tetraFactor;
}
void FractalParams::setTetraScale(float tetraScale = NULL) {
    this->tetraScale = (tetraScale == NULL)?1.0f:tetraScale;
}
void FractalParams::setTime(float time = NULL) {
    this->time = (time == NULL)?2.6703f:time;
}
void FractalParams::setNearPlane(float nearPlane = NULL) {
    this->nearPlane = (nearPlane == NULL)?0.1f:nearPlane;
}
void FractalParams::setFarPlane(float farPlane = NULL) {
    this->farPlane = (farPlane == NULL)?100.0f:farPlane;
}
void FractalParams::setCamera(Camera camera) {
    this->camera = camera;
}
void FractalParams::setInverseVP(glm::mat4 inverseVP = (glm::mat4)NULL) {
    this->inverseVP = (inverseVP == (glm::mat4)NULL)?glm::inverse(Transformation::getViewMatrix(camera)) * glm::inverse(Transformation::getProjectionMatrix()):inverseVP;
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
    setLightAngle();
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
    setInverseVP();

}