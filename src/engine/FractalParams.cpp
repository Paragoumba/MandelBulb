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

void FractalParams::setAmbientIntensity(float _ambientIntensity = 1.0f) {
    this->ambientIntensity = _ambientIntensity;
}
void FractalParams::setBailLimit(float _bailLimit = 5.0f) {
    this->bailLimit = _bailLimit;
}
void FractalParams::setBaseColorStrength(float _baseColorStrength = .5f) {
    this->baseColorStrength = _baseColorStrength;
}
void FractalParams::setBgColor(glm::vec3 _bgColor = (glm::vec3)(float)NULL) {
    this->bgColor = (_bgColor == (glm::vec3)(float)NULL)?glm::vec3(119, 41, 83):_bgColor;
}
void FractalParams::setBoxFoldFactor(int _boxFoldFactor = 0) {
    this->boxFoldFactor = _boxFoldFactor;
}
void FractalParams::setBoxFoldingLimit(float _boxFoldingLimit = 1.0f) {
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
void FractalParams::setDerivativeBias(int _derivativeBias = 1) {
    this->derivativeBias = _derivativeBias;
}
void FractalParams::setDiffuseIntensity(float _diffuseIntensity = 1.0f) {
    this->diffuseIntensity = _diffuseIntensity;
}
void FractalParams::setEyePos(glm::vec3 _eyePos = (glm::vec3)(float)NULL) {
    this->eyePos = (_eyePos == (glm::vec3)(float)NULL)?glm::vec3(0.00, 0.00, 3.00):_eyePos;
}
void FractalParams::setFractalIters(int _fractalIters = 1) {
    this->fractalIters = _fractalIters;
}
void FractalParams::setFudgeFactor(float _fudgeFactor = 1.0f) {
    this->fudgeFactor = _fudgeFactor;
}
void FractalParams::setGammaCorrection(int _gammaCorrection = 0) {
    this->gammaCorrection = _gammaCorrection;
}
void FractalParams::setGlowColor(glm::vec3 _glowColor = (glm::vec3)(float)NULL) {
    this->glowColor = (_glowColor == (glm::vec3)(float)NULL)?glm::vec3(0.75, 0.90, 1.00):_glowColor;
}
void FractalParams::setGlowFactor(float _glowFactor = 1.0f) {
    this->glowFactor = _glowFactor;
}
void FractalParams::setJulia(int _julia = 0) {
    this->julia = _julia;
}
void FractalParams::setJuliaC(glm::vec3 _juliaC = (glm::vec3)(float)NULL) {
    this->juliaC = (_juliaC == (glm::vec3)(float)NULL)?glm::vec3(0.86, 0.23, -0.50):_juliaC;
}
void FractalParams::setLightPos(glm::vec3 _lightPos = (glm::vec3)(float)NULL) {
    this->lightPos = (_lightPos == (glm::vec3)(float)NULL)?glm::vec3(1.00, 3.00, 1.00):_lightPos;
}
void FractalParams::setLightSource(int _lightSource = 1) {
    this->lightSource = _lightSource;
}
void FractalParams::setMandelBoxOn(int _mandelBoxOn = (bool)false) {
    this->mandelBoxOn = _mandelBoxOn;
}
void FractalParams::setMandelBoxScale(float _mandelBoxScale = 1.2f) {
    this->mandelBoxScale = _mandelBoxScale; //0.1f before
}
void FractalParams::setMandelbulbOn(int _mandelbulbOn = (int)true) {
    this->mandelbulbOn = _mandelbulbOn;
}
void FractalParams::setMaxRaySteps(float _maxRaySteps = 1000.0f) {
    this->maxRaySteps = _maxRaySteps;
}
void FractalParams::setMinDistance(float _minDistance = 1.00000E-05) {
    this->minDistance = _minDistance;
}
void FractalParams::setNoiseFactor(float _noiseFactor = 0.5f) {
    this->noiseFactor = _noiseFactor;
}
void FractalParams::setOrbitStrength(glm::vec4 _orbitStrength = (glm::vec4)(float)NULL) {
    this->orbitStrength = (_orbitStrength == (glm::vec4)(float)NULL)?glm::vec4(-1.00, -1.80, -1.40, 1.30):_orbitStrength;
}
void FractalParams::setOtCycleIntensity(float _otCycleIntensity = 5.0f) {
    this->otCycleIntensity = _otCycleIntensity;
}
void FractalParams::setOtDist0to1(float _otDist0to1 = 0.3f) {
    this->otDist0to1 = _otDist0to1;
}
void FractalParams::setOtDist1to2(float _otDist1to2 = 1.0f) {
    this->otDist1to2 = _otDist1to2;
}
void FractalParams::setOtDist2to3(float _otDist2to3 = 0.4f) {
    this->otDist2to3 = _otDist2to3;
}
void FractalParams::setOtDist3to0(float _otDist3to0 = 0.2f) {
    this->otDist3to0 = _otDist3to0;
}
void FractalParams::setOtPaletteOffset(float _otPaletteOffset = 0.0f) {
    this->otPaletteOffset = _otPaletteOffset;
}
void FractalParams::setPhongShadingMixFactor(float _phongShadingMixFactor = 1.0f) {
    this->phongShadingMixFactor = _phongShadingMixFactor;
}
void FractalParams::setPower(float _power = 8.0f) {
    this->power = _power;
}
void FractalParams::setScreenSize(glm::vec2 _screenSize = (glm::vec2)(float)NULL) {
    this->screenSize = (_screenSize == (glm::vec2)(float)NULL)?glm::vec2(800.00, 640.00):_screenSize;
}
void FractalParams::setShadowBrightness(float _shadowBrightness = 0.2f) {
    this->shadowBrightness = _shadowBrightness;
}
void FractalParams::setShadowRayMinStepsTaken(int _shadowRayMinStepsTaken = 5) {
    this->shadowRayMinStepsTaken = _shadowRayMinStepsTaken;
}
void FractalParams::setShininess(float _shininess = 32.0f) {
    this->shininess = _shininess;
}
void FractalParams::setShowBgGradient(int _showBgGradient = (int)true) {
    this->showBgGradient = _showBgGradient;
}
void FractalParams::setSpecularIntensity(float _specularIntensity = 1.0f) {
    this->specularIntensity = _specularIntensity;
}
void FractalParams::setSphereFixedRadius(float _sphereFixedRadius = 2.0f) {
    this->sphereFixedRadius = _sphereFixedRadius;
}
void FractalParams::setSphereFoldFactor(int _sphereFoldFactor = 0) {
    this->sphereFoldFactor = _sphereFoldFactor;
}
void FractalParams::setSphereMinRadius(float _sphereMinRadius = 0.01f) {
    this->sphereMinRadius = _sphereMinRadius;
}
void FractalParams::setSphereMinTimeVariance(int _sphereMinTimeVariance = 0) {
    this->sphereMinTimeVariance = _sphereMinTimeVariance;
}
void FractalParams::setTetraFactor(int _tetraFactor = 0) {
    this->tetraFactor = _tetraFactor;
}
void FractalParams::setTetraScale(float _tetraScale = 1.0f) {
    this->tetraScale = _tetraScale;
}
void FractalParams::setTime(float _time = 2.6703f) {
    this->time = _time;
}
void FractalParams::setNearPlane(float _nearPlane = 0.1f) {
    this->nearPlane = _nearPlane;
}
void FractalParams::setFarPlane(float _farPlane = 100.0f) {
    this->farPlane = _farPlane;
}
void FractalParams::setInverseVP(Camera& camera, glm::mat4 _inverseVP) {
    this->inverseVP = (_inverseVP == (glm::mat4)(const float)NULL)?glm::inverse(Transformation::getViewMatrix(camera)) * glm::inverse(Transformation::getProjectionMatrix()):_inverseVP;
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