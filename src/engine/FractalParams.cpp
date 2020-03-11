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
void FractalParams::setAmbientIntensity(float ambientIntensity = (float)NULL) { //Slider
    this->ambientIntensity = ambientIntensity;
}
void FractalParams::setBailLimit(float bailLimit = (float)NULL) { //Slider
    this->bailLimit = bailLimit;
}
void FractalParams::setBaseColorStrength(float baseColorStrength = (float)NULL) { //Slider
    this->baseColorStrength = baseColorStrength;
}
void FractalParams::setBgColor(glm::vec3 bgColor = (glm::vec3)(float)NULL) {
    this->bgColor = (bgColor == (glm::vec3)(float)NULL)?glm::vec3(119, 41, 83):bgColor;
}
void FractalParams::setBoxFoldFactor(int boxFoldFactor = (int)NULL) { // Slider
    this->boxFoldFactor = boxFoldFactor;
}
void FractalParams::setBoxFoldingLimit(float boxFoldingLimit = (float)NULL) { //Slider
    this->boxFoldingLimit = boxFoldingLimit;
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
void FractalParams::setDerivativeBias(int derivativeBias = (int)NULL) { //Slider
    this->derivativeBias = derivativeBias;
}
void FractalParams::setDiffuseIntensity(float diffuseIntensity = (float)NULL) { //Slider
    this->diffuseIntensity = diffuseIntensity;
}
void FractalParams::setEyePos(glm::vec3 eyePos = (glm::vec3)(float)NULL) {
    this->eyePos = (eyePos == (glm::vec3)(float)NULL)?glm::vec3(0.00, 0.00, 3.00):eyePos;
}
void FractalParams::setFractalIters(int fractalIters = (int)NULL) { //Slider
    this->fractalIters = fractalIters;
}
void FractalParams::setFudgeFactor(float fudgeFactor = (float)NULL) { //Slider
    this->fudgeFactor = fudgeFactor;
}
void FractalParams::setGammaCorrection(int gammaCorrection = (int)NULL) { //Slider
    this->gammaCorrection = gammaCorrection;
}
void FractalParams::setGlowColor(glm::vec3 glowColor = (glm::vec3)(float)NULL) {
    this->glowColor = (glowColor == (glm::vec3)(float)NULL)?glm::vec3(0.75, 0.90, 1.00):glowColor;
}
void FractalParams::setGlowFactor(float glowFactor = (float)NULL) { //Slider
    this->glowFactor = glowFactor;
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
void FractalParams::setLightSource(int lightSource = (int)NULL) { //Slider
    this->lightSource = lightSource;
}
void FractalParams::setMandelBoxOn(int mandelBoxOn = (bool)true) {
    this->mandelBoxOn = mandelBoxOn;
}
void FractalParams::setMandelBoxScale(float mandelBoxScale = (float)NULL) { // Slider
    this->mandelBoxScale = (mandelBoxScale == (float)NULL)?0.1f:mandelBoxScale;
}
void FractalParams::setMandelbulbOn(int mandelbulbOn = (int)true) {
    this->mandelbulbOn = mandelbulbOn;
}
void FractalParams::setMaxRaySteps(float maxRaySteps = (float)NULL) { //Slider
    this->maxRaySteps = maxRaySteps;
}
void FractalParams::setMinDistance(float minDistance = (float)NULL) { //Slider
    this->minDistance = minDistance;
}
void FractalParams::setNoiseFactor(float noiseFactor = (float)NULL) { //Slider
    this->noiseFactor = noiseFactor;
}
void FractalParams::setOrbitStrength(glm::vec4 orbitStrength = (glm::vec4)(float)NULL) {
    this->orbitStrength = (orbitStrength == (glm::vec4)(float)NULL)?glm::vec4(-1.00, -1.80, -1.40, 1.30):orbitStrength;
}
void FractalParams::setOtCycleIntensity(float otCycleIntensity = (float)NULL) { //Slider
    this->otCycleIntensity = otCycleIntensity;
}
void FractalParams::setOtDist0to1(float otDist0to1 = (float)NULL) { //Slider
    this->otDist0to1 = otDist0to1;
}
void FractalParams::setOtDist1to2(float otDist1to2 = (float)NULL) { //Slider
    this->otDist1to2 = otDist1to2;
}
void FractalParams::setOtDist2to3(float otDist2to3 = (float)NULL) { //Slider
    this->otDist2to3 = otDist2to3;
}
void FractalParams::setOtDist3to0(float otDist3to0 = (float)NULL) { //Slider
    this->otDist3to0 = otDist3to0;
}
void FractalParams::setOtPaletteOffset(float otPaletteOffset = (float)NULL) { // Slider
    this->otPaletteOffset = otPaletteOffset;
}
void FractalParams::setPhongShadingMixFactor(float phongShadingMixFactor = (float)NULL) { //Slider
    this->phongShadingMixFactor = phongShadingMixFactor;
}
void FractalParams::setPower(float power = (float)NULL) { //Slider
    this->power = power;
}
void FractalParams::setScreenSize(glm::vec2 screenSize = (glm::vec2)(float)NULL) {
    this->screenSize = (screenSize == (glm::vec2)(float)NULL)?glm::vec2(800.00, 640.00):screenSize;
}
void FractalParams::setShadowBrightness(float shadowBrightness = (float)NULL) { //Slider
    this->shadowBrightness = shadowBrightness;
}
void FractalParams::setShadowRayMinStepsTaken(int shadowRayMinStepsTaken = (int)NULL) { //Slider
    this->shadowRayMinStepsTaken = shadowRayMinStepsTaken;
}
void FractalParams::setShininess(float shininess = (float)NULL) { //Slider
    this->shininess = shininess;
}
void FractalParams::setShowBgGradient(int showBgGradient = (int)true) {
    this->showBgGradient = showBgGradient;
}
void FractalParams::setSpecularIntensity(float specularIntensity = (float)NULL) { //Slider
    this->specularIntensity = specularIntensity;
}
void FractalParams::setSphereFixedRadius(float sphereFixedRadius = (float)NULL) { //Slider
    this->sphereFixedRadius = sphereFixedRadius;
}
void FractalParams::setSphereFoldFactor(int sphereFoldFactor = (int)NULL) { //Slider
    this->sphereFoldFactor = sphereFoldFactor;
}
void FractalParams::setSphereMinRadius(float sphereMinRadius = (float)NULL) { //Slider
    this->sphereMinRadius = sphereMinRadius;
}
void FractalParams::setSphereMinTimeVariance(int sphereMinTimeVariance = (int)NULL) {
    this->sphereMinTimeVariance = (sphereMinTimeVariance == (int)NULL)?0:sphereMinTimeVariance;
}
void FractalParams::setTetraFactor(int tetraFactor = (int)NULL) { //Slider
    this->tetraFactor = tetraFactor;
}
void FractalParams::setTetraScale(float tetraScale = (float)NULL) { //Slider
    this->tetraScale = tetraScale;
}
void FractalParams::setTime(float time = (float)NULL) { //Slider
    this->time = time;
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

    setAmbientIntensity(1.0f);
    setBailLimit(5.0f);
    setBaseColorStrength(.5f);
    setBgColor();
    setBoxFoldFactor(0);
    setBoxFoldingLimit(1.0f);
    setColor0();
    setColor1();
    setColor2();
    setColor3();
    setColorBase();
    setDerivativeBias(1);
    setDiffuseIntensity(1.0f);
    setEyePos();
    setFractalIters(1);
    setFudgeFactor(1.0f);
    setGammaCorrection(0);
    setGlowColor();
    setGlowFactor(1.0f);
    setJulia(0);
    setJuliaC();
    setLightPos();
    setLightSource(1);
    setMandelBoxOn();
    setMandelBoxScale(1.2f);
    setMandelbulbOn();
    setMaxRaySteps(1000.0f);
    setMinDistance(1.00000E-05);
    setNoiseFactor(0.5f);
    setOrbitStrength();
    setOtCycleIntensity(5.0f);
    setOtDist0to1(0.3f);
    setOtDist1to2(1.0f);
    setOtDist2to3(0.4f);
    setOtDist3to0(0.2f);
    setOtPaletteOffset(0.0f);
    setPhongShadingMixFactor(1.0f);
    setPower(8.0f);
    setScreenSize();
    setShadowBrightness(0.2f);
    setShadowRayMinStepsTaken(5);
    setShininess(32.0f);
    setShowBgGradient();
    setSpecularIntensity(1.0f);
    setSphereFixedRadius(2.0f);
    setSphereFoldFactor(0);
    setSphereMinRadius(0.01f);
    setSphereMinTimeVariance(0);
    setTetraFactor(0);
    setTetraScale(1.0f);
    setTime(2.6703f);
    setNearPlane(0.1f);
    setFarPlane(100.0f);

}

FractalParams::~FractalParams() {

    delete singleton;

}