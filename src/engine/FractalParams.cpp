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
void FractalParams::setAmbientIntensity(float _ambientIntensity = (float)NULL) { //Slider
    this->ambientIntensity = _ambientIntensity;
}
void FractalParams::setBailLimit(float _bailLimit = (float)NULL) { //Slider
    this->bailLimit = _bailLimit;
}
void FractalParams::setBaseColorStrength(float _baseColorStrength = (float)NULL) { //Slider
    this->baseColorStrength = _baseColorStrength;
}
void FractalParams::setBgColor(glm::vec3 _bgColor = (glm::vec3)(float)NULL) {
    this->bgColor = (_bgColor == (glm::vec3)(float)NULL)?glm::vec3(119, 41, 83):_bgColor;
}
void FractalParams::setBoxFoldFactor(int _boxFoldFactor = (int)NULL) { // Slider
    this->boxFoldFactor = _boxFoldFactor;
}
void FractalParams::setBoxFoldingLimit(float _boxFoldingLimit = (float)NULL) { //Slider
    this->boxFoldingLimit = _boxFoldingLimit;
}
void FractalParams::setColor0(glm::vec3 _color0 = (glm::vec3)(float)NULL) {
    this->color0 = (_color0 == (glm::vec3)(float)NULL)?glm::vec3(0.30, 0.50, 0.20):_color0;
}
void FractalParams::setColor1(glm::vec3 _color1 = (glm::vec3)(float)NULL) {
    this->color1 = (_color1 == (glm::vec3)(float)NULL)?glm::vec3(0.60, 0.20, 0.50):_color1;
}
void FractalParams::setColor2(glm::vec3 _color2 = (glm::vec3)(float)NULL) {
    this->color2 = (_color2 == (glm::vec3)(float)NULL)?glm::vec3(0.25, 0.70, 0.90):_color2;
}
void FractalParams::setColor3(glm::vec3 _color3 = (glm::vec3)(float)NULL) {
    this->color3 = (_color3 == (glm::vec3)(float)NULL)?glm::vec3(0.20, 0.45, 0.25):_color3;
}
void FractalParams::setColorBase(glm::vec3 _colorBase = (glm::vec3)(float)NULL) {
    this->colorBase = (_colorBase == (glm::vec3)(float)NULL)?glm::vec3(0.30, 0.60, 0.30):_colorBase;
}
void FractalParams::setDerivativeBias(int _derivativeBias = (int)NULL) { //Slider
    this->derivativeBias = _derivativeBias;
}
void FractalParams::setDiffuseIntensity(float _diffuseIntensity = (float)NULL) { //Slider
    this->diffuseIntensity = _diffuseIntensity;
}
void FractalParams::setEyePos(glm::vec3 _eyePos = (glm::vec3)(float)NULL) {
    this->eyePos = (_eyePos == (glm::vec3)(float)NULL)?glm::vec3(0.00, 0.00, 3.00):_eyePos;
}
void FractalParams::setFractalIters(int _fractalIters = (int)NULL) { //Slider
    this->fractalIters = _fractalIters;
}
void FractalParams::setFudgeFactor(float _fudgeFactor = (float)NULL) { //Slider
    this->fudgeFactor = _fudgeFactor;
}
void FractalParams::setGammaCorrection(int _gammaCorrection = (int)NULL) { //Slider
    this->gammaCorrection = _gammaCorrection;
}
void FractalParams::setGlowColor(glm::vec3 _glowColor = (glm::vec3)(float)NULL) {
    this->glowColor = (_glowColor == (glm::vec3)(float)NULL)?glm::vec3(0.75, 0.90, 1.00):_glowColor;
}
void FractalParams::setGlowFactor(float _glowFactor = (float)NULL) { //Slider
    this->glowFactor = _glowFactor;
}
void FractalParams::setJulia(int _julia = (int)NULL) {
    this->julia = (_julia == (int)NULL)?0:_julia;
}
void FractalParams::setJuliaC(glm::vec3 _juliaC = (glm::vec3)(float)NULL) {
    this->juliaC = (_juliaC == (glm::vec3)(float)NULL)?glm::vec3(0.86, 0.23, -0.50):_juliaC;
}
void FractalParams::setLightPos(glm::vec3 _lightPos = (glm::vec3)(float)NULL) {
    this->lightPos = (_lightPos == (glm::vec3)(float)NULL)?glm::vec3(1.00, 3.00, 1.00):_lightPos;
}
void FractalParams::setLightSource(int _lightSource = (int)NULL) { //Slider
    this->lightSource = _lightSource;
}
void FractalParams::setMandelBoxOn(int _mandelBoxOn = (bool)true) {
    this->mandelBoxOn = _mandelBoxOn;
}
void FractalParams::setMandelBoxScale(float _mandelBoxScale = (float)NULL) { // Slider
    this->mandelBoxScale = (_mandelBoxScale == (float)NULL)?0.1f:_mandelBoxScale;
}
void FractalParams::setMandelbulbOn(int _mandelbulbOn = (int)true) {
    this->mandelbulbOn = _mandelbulbOn;
}
void FractalParams::setMaxRaySteps(float _maxRaySteps = (float)NULL) { //Slider
    this->maxRaySteps = _maxRaySteps;
}
void FractalParams::setMinDistance(float _minDistance = (float)NULL) { //Slider
    this->minDistance = _minDistance;
}
void FractalParams::setNoiseFactor(float _noiseFactor = (float)NULL) { //Slider
    this->noiseFactor = _noiseFactor;
}
void FractalParams::setOrbitStrength(glm::vec4 _orbitStrength = (glm::vec4)(float)NULL) {
    this->orbitStrength = (_orbitStrength == (glm::vec4)(float)NULL)?glm::vec4(-1.00, -1.80, -1.40, 1.30):_orbitStrength;
}
void FractalParams::setOtCycleIntensity(float _otCycleIntensity = (float)NULL) { //Slider
    this->otCycleIntensity = _otCycleIntensity;
}
void FractalParams::setOtDist0to1(float _otDist0to1 = (float)NULL) { //Slider
    this->otDist0to1 = _otDist0to1;
}
void FractalParams::setOtDist1to2(float _otDist1to2 = (float)NULL) { //Slider
    this->otDist1to2 = _otDist1to2;
}
void FractalParams::setOtDist2to3(float _otDist2to3 = (float)NULL) { //Slider
    this->otDist2to3 = _otDist2to3;
}
void FractalParams::setOtDist3to0(float _otDist3to0 = (float)NULL) { //Slider
    this->otDist3to0 = _otDist3to0;
}
void FractalParams::setOtPaletteOffset(float _otPaletteOffset = (float)NULL) { // Slider
    this->otPaletteOffset = _otPaletteOffset;
}
void FractalParams::setPhongShadingMixFactor(float _phongShadingMixFactor = (float)NULL) { //Slider
    this->phongShadingMixFactor = _phongShadingMixFactor;
}
void FractalParams::setPower(float _power = (float)NULL) { //Slider
    this->power = _power;
}
void FractalParams::setScreenSize(glm::vec2 _screenSize = (glm::vec2)(float)NULL) {
    this->screenSize = (_screenSize == (glm::vec2)(float)NULL)?glm::vec2(800.00, 640.00):_screenSize;
}
void FractalParams::setShadowBrightness(float _shadowBrightness = (float)NULL) { //Slider
    this->shadowBrightness = _shadowBrightness;
}
void FractalParams::setShadowRayMinStepsTaken(int _shadowRayMinStepsTaken = (int)NULL) { //Slider
    this->shadowRayMinStepsTaken = _shadowRayMinStepsTaken;
}
void FractalParams::setShininess(float _shininess = (float)NULL) { //Slider
    this->shininess = _shininess;
}
void FractalParams::setShowBgGradient(int _showBgGradient = (int)true) {
    this->showBgGradient = _showBgGradient;
}
void FractalParams::setSpecularIntensity(float _specularIntensity = (float)NULL) { //Slider
    this->specularIntensity = _specularIntensity;
}
void FractalParams::setSphereFixedRadius(float _sphereFixedRadius = (float)NULL) { //Slider
    this->sphereFixedRadius = _sphereFixedRadius;
}
void FractalParams::setSphereFoldFactor(int _sphereFoldFactor = (int)NULL) { //Slider
    this->sphereFoldFactor = _sphereFoldFactor;
}
void FractalParams::setSphereMinRadius(float _sphereMinRadius = (float)NULL) { //Slider
    this->sphereMinRadius = _sphereMinRadius;
}
void FractalParams::setSphereMinTimeVariance(int _sphereMinTimeVariance = (int)NULL) {
    this->sphereMinTimeVariance = (_sphereMinTimeVariance == (int)NULL)?0:_sphereMinTimeVariance;
}
void FractalParams::setTetraFactor(int _tetraFactor = (int)NULL) { //Slider
    this->tetraFactor = _tetraFactor;
}
void FractalParams::setTetraScale(float _tetraScale = (float)NULL) { //Slider
    this->tetraScale = _tetraScale;
}
void FractalParams::setTime(float _time = (float)NULL) { //Slider
    this->time = _time;
}
void FractalParams::setNearPlane(float _nearPlane = (float)NULL) {
    this->nearPlane = (_nearPlane == (float)NULL)?0.1f:_nearPlane;
}
void FractalParams::setFarPlane(float _farPlane = (float)NULL) {
    this->farPlane = (_farPlane == (float)NULL)?100.0f:_farPlane;
}
void FractalParams::setInverseVP(Camera& camera, glm::mat4 _inverseVP) {
    this->inverseVP = (_inverseVP == (glm::mat4)(const float)NULL)?glm::inverse(Transformation::getViewMatrix(camera)) * glm::inverse(Transformation::getProjectionMatrix()):_inverseVP;
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