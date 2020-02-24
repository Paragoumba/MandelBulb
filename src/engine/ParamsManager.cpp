#include "ParamsManager.hpp"

ParamsManager::ParamsManager(Camera camera) {

    fractalParams = FractalParams::getInstance(camera);
    reset();

}

float ParamsManager::getAmbientIntensity() const { return fractalParams->getAmbientIntensity(); }
float ParamsManager::getBailLimit() const { return fractalParams->getBailLimit(); }
float ParamsManager::getBaseColorStrength() const { return fractalParams->getBaseColorStrength(); }
glm::vec3 ParamsManager::getBgColor() const { return fractalParams->getBgColor(); }
int ParamsManager::getBoxFoldFactor() const { return fractalParams->getBoxFoldFactor(); }
float ParamsManager::getBoxFoldingLimit() const { return fractalParams->getBoxFoldingLimit(); }
glm::vec3 ParamsManager::getColor0() const { return fractalParams->getColor0(); }
glm::vec3 ParamsManager::getColor1() const { return fractalParams->getColor1(); }
glm::vec3 ParamsManager::getColor2() const { return fractalParams->getColor2(); }
glm::vec3 ParamsManager::getColor3() const { return fractalParams->getColor3(); }
glm::vec3 ParamsManager::getColorBase() const { return fractalParams->getColorBase(); }
int ParamsManager::getDerivativeBias() const { return fractalParams->getDerivativeBias(); }
float ParamsManager::getDiffuseIntensity() const { return fractalParams->getDiffuseIntensity(); }
glm::vec3 ParamsManager::getEyePos() const { return fractalParams->getEyePos(); }
int ParamsManager::getFractalIters() const { return fractalParams->getFractalIters(); }
float ParamsManager::getFudgeFactor() const { return fractalParams->getFudgeFactor(); }
int ParamsManager::getGammaCorrection() const { return fractalParams->getGammaCorrection(); }
glm::vec3 ParamsManager::getGlowColor() const { return fractalParams->getGlowColor(); }
float ParamsManager::getGlowFactor() const { return fractalParams->getGlowFactor(); }
int ParamsManager::getJulia() const { return fractalParams->getJulia(); }
glm::vec3 ParamsManager::getJuliaC() const { return fractalParams->getJuliaC(); }
float ParamsManager::getLightAngle() const { return fractalParams->getLightAngle(); }
glm::vec3 ParamsManager::getLightPos() const { return fractalParams->getLightPos(); }
int ParamsManager::getLightSource() const { return fractalParams->getLightSource(); }
int ParamsManager::getMandelBoxOn() const { return fractalParams->getMandelBoxOn(); }
float ParamsManager::getMandelBoxScale() const { return fractalParams->getMandelBoxScale(); }
int ParamsManager::getMandelbulbOn() const { return fractalParams->getMandelbulbOn(); }
float ParamsManager::getMaxRaySteps() const { return fractalParams->getMaxRaySteps(); }
float ParamsManager::getMinDistance() const { return fractalParams->getMinDistance(); }
float ParamsManager::getNoiseFactor() const { return fractalParams->getNoiseFactor(); }
glm::vec4 ParamsManager::getOrbitStrength() const { return fractalParams->getOrbitStrength(); }
float ParamsManager::getOtCycleIntensity() const { return fractalParams->getOtCycleIntensity(); }
float ParamsManager::getOtDist0to1() const { return fractalParams->getOtDist0to1(); }
float ParamsManager::getOtDist1to2() const { return fractalParams->getOtDist1to2(); }
float ParamsManager::getOtDist2to3() const { return fractalParams->getOtDist2to3(); }
float ParamsManager::getOtDist3to0() const { return fractalParams->getOtDist3to0(); }
float ParamsManager::getOtPaletteOffset() const { return fractalParams->getOtPaletteOffset(); }
float ParamsManager::getPhongShadingMixFactor() const { return fractalParams->getPhongShadingMixFactor(); }
float ParamsManager::getPower() const { return fractalParams->getPower(); }
glm::vec2 ParamsManager::getScreenSize() const { return fractalParams->getScreenSize(); }
float ParamsManager::getShadowBrightness() const { return fractalParams->getShadowBrightness(); }
int ParamsManager::getShadowRayMinStepsTaken() const { return fractalParams->getShadowRayMinStepsTaken(); }
float ParamsManager::getShininess() const { return fractalParams->getShininess(); }
int ParamsManager::getShowBgGradient() const { return fractalParams->getShowBgGradient(); }
float ParamsManager::getSpecularIntensity() const { return fractalParams->getSpecularIntensity(); }
float ParamsManager::getSphereFixedRadius() const { return fractalParams->getSphereFixedRadius(); }
int ParamsManager::getSphereFoldFactor() const { return fractalParams->getSphereFoldFactor(); }
float ParamsManager::getSphereMinRadius() const { return fractalParams->getSphereMinRadius(); }
int ParamsManager::getSphereMinTimeVariance() const { return fractalParams->getSphereMinRadius(); }
int ParamsManager::getTetraFactor() const { return fractalParams->getTetraFactor(); }
float ParamsManager::getTetraScale() const { return fractalParams->getTetraScale(); }
float ParamsManager::getTime() const { return fractalParams->getTime(); }
float ParamsManager::getNearPlane() const { return fractalParams->getNearPlane(); }
float ParamsManager::getFarPlane() const { return fractalParams->getFarPlane(); }
glm::mat4 ParamsManager::getInverseVP() const { return fractalParams->getInverseVP(); }
bool& ParamsManager::getRenderFractal() { return renderFractal; }
bool& ParamsManager::getHideMenu() { return hideMenu; }
bool& ParamsManager::getShowExportMenu() { return showExportMenu; }
char* ParamsManager::getReA() { return reA; }
char* ParamsManager::getImA() { return imA; }
char* ParamsManager::getReC() { return reC; }
char* ParamsManager::getImC() { return imC; }
ImVec4& ParamsManager::getBackgroundColor() { return backgroundColor; }

void ParamsManager::setAmbientIntensity(float ambientIntensity) { fractalParams->setAmbientIntensity(ambientIntensity); }
void ParamsManager::setBailLimit(float bailLimit) { fractalParams->setBailLimit(bailLimit); }
void ParamsManager::setBaseColorStrength(float baseColorStrength) { fractalParams->setBaseColorStrength(baseColorStrength); }
void ParamsManager::setBgColor(glm::vec3 bgColor) { fractalParams->setBgColor(bgColor); }
void ParamsManager::setBoxFoldFactor(int boxFoldFactor) { fractalParams->setBoxFoldFactor(boxFoldFactor); }
void ParamsManager::setBoxFoldingLimit(float boxFoldingLimit) { fractalParams->setBoxFoldingLimit(boxFoldingLimit); }
void ParamsManager::setColor0(glm::vec3 color0) { fractalParams->setColor0(color0); }
void ParamsManager::setColor1(glm::vec3 color1) { fractalParams->setColor1(color1); }
void ParamsManager::setColor2(glm::vec3 color2) { fractalParams->setColor2(color2); }
void ParamsManager::setColor3(glm::vec3 color3) { fractalParams->setColor3(color3); }
void ParamsManager::setColorBase(glm::vec3 colorBase) { fractalParams->setColorBase(colorBase); }
void ParamsManager::setDerivativeBias(int derivativeBias) { fractalParams->setDerivativeBias(derivativeBias); }
void ParamsManager::setDiffuseIntensity(float diffuseIntensity) { fractalParams->setDiffuseIntensity(diffuseIntensity); }
void ParamsManager::setEyePos(glm::vec3 eyePos) { fractalParams->setEyePos(eyePos); }
void ParamsManager::setFractalIters(int fractalIters) { fractalParams->setFractalIters(fractalIters); }
void ParamsManager::setFudgeFactor(float fudgeFactor) { fractalParams->setFudgeFactor(fudgeFactor); }
void ParamsManager::setGammaCorrection(int gammaCorrection) { fractalParams->setGammaCorrection(gammaCorrection); }
void ParamsManager::setGlowColor(glm::vec3 glowColor) { fractalParams->setGlowColor(glowColor); }
void ParamsManager::setGlowFactor(float glowFactor) { fractalParams->setGlowFactor(glowFactor); }
void ParamsManager::setJulia(int julia) { fractalParams->setJulia(julia); }
void ParamsManager::setJuliaC(glm::vec3 juliaC) { fractalParams->setJuliaC(juliaC); }
void ParamsManager::setLightAngle(float lightAngle) { fractalParams->setLightAngle(lightAngle); }
void ParamsManager::setLightPos(glm::vec3 lightPos) { fractalParams->setLightPos(lightPos); }
void ParamsManager::setLightSource(int lightSource) { fractalParams->setLightSource(lightSource); }
void ParamsManager::setMandelBoxOn(int mandelBoxOn) { fractalParams->setMandelBoxOn(mandelBoxOn); }
void ParamsManager::setMandelBoxScale(float mandelBoxScale) { fractalParams->setMandelBoxScale(mandelBoxScale); }
void ParamsManager::setMandelbulbOn(int mandelbulbOn) { fractalParams->setMandelbulbOn(mandelbulbOn); }
void ParamsManager::setMaxRaySteps(float maxRaySteps) { fractalParams->setMaxRaySteps(maxRaySteps); }
void ParamsManager::setMinDistance(float minDistance) { fractalParams->setMinDistance(minDistance); }
void ParamsManager::setNoiseFactor(float noiseFactor) { fractalParams->setNoiseFactor(noiseFactor); }
void ParamsManager::setOrbitStrength(glm::vec4 orbitStrength) { fractalParams->setOrbitStrength(orbitStrength); }
void ParamsManager::setOtCycleIntensity(float otCycleIntensity) { fractalParams->setOtCycleIntensity(otCycleIntensity); }
void ParamsManager::setOtDist0to1(float otDist0to1) { fractalParams->setOtDist0to1(otDist0to1); }
void ParamsManager::setOtDist1to2(float otDist1to2) { fractalParams->setOtDist1to2(otDist1to2); }
void ParamsManager::setOtDist2to3(float otDist2to3) { fractalParams->setOtDist2to3(otDist2to3); }
void ParamsManager::setOtDist3to0(float otDist3to0) { fractalParams->setOtDist3to0(otDist3to0); }
void ParamsManager::setOtPaletteOffset(float otPaletteOffset) { fractalParams->setOtPaletteOffset(otPaletteOffset); }
void ParamsManager::setPhongShadingMixFactor(float phongShadingMixFactor) { fractalParams->setPhongShadingMixFactor(phongShadingMixFactor); }
void ParamsManager::setPower(float power) { fractalParams->setPower(power); }
void ParamsManager::setScreenSize(glm::vec2 screenSize) { fractalParams->setScreenSize(screenSize); }
void ParamsManager::setShadowBrightness(float shadowBrightness) { fractalParams->setShadowBrightness(shadowBrightness); }
void ParamsManager::setShadowRayMinStepsTaken(int shadowRayMinStepsTaken) { fractalParams->setShadowRayMinStepsTaken(shadowRayMinStepsTaken); }
void ParamsManager::setShininess(float shininess) { fractalParams->setShininess(shininess); }
void ParamsManager::setShowBgGradient(int showBgGradient) { fractalParams->setShowBgGradient(showBgGradient); }
void ParamsManager::setSpecularIntensity(float specularIntensity) { fractalParams->setSpecularIntensity(specularIntensity); }
void ParamsManager::setSphereFixedRadius(float sphereFixedRadius) { fractalParams->setSphereFixedRadius(sphereFixedRadius); }
void ParamsManager::setSphereFoldFactor(int sphereFoldFactor) { fractalParams->setSphereFoldFactor(sphereFoldFactor); }
void ParamsManager::setSphereMinRadius(float sphereMinRadius) { fractalParams->setSphereMinRadius(sphereMinRadius); }
void ParamsManager::setSphereMinTimeVariance(int sphereMinTimeVariance) { fractalParams->setSphereMinTimeVariance(sphereMinTimeVariance); }
void ParamsManager::setTetraFactor(int tetraFactor) { fractalParams->setTetraFactor(tetraFactor); }
void ParamsManager::setTetraScale(float tetraScale) { fractalParams->setTetraScale(tetraScale); }
void ParamsManager::setTime(float time) { fractalParams->setTime(time); }
void ParamsManager::setNearPlane(float nearPlane) { fractalParams->setNearPlane(nearPlane); }
void ParamsManager::setFarPlane(float farPlane) { fractalParams->setFarPlane(farPlane); }
void ParamsManager::setCamera(Camera camera) { fractalParams->setCamera(camera); }
void ParamsManager::setInverseVP(glm::mat4 inverseVP) { fractalParams->setInverseVP(inverseVP); }
void ParamsManager::setRenderFractal(bool renderFractal = false) {
    this->renderFractal = renderFractal;
}
void ParamsManager::setHideMenu(bool hideMenu = true) {
    this->hideMenu = hideMenu;
}
void ParamsManager::setShowExportMenu(bool showExportMenu = false) {
    this->showExportMenu = showExportMenu;
}
void ParamsManager::setReA(const char* reA = (const char*)NULL) {
    if (reA == (const char*)NULL) strcpy(this->reA, "1");
    else strcpy(this->reA, reA);
}
void ParamsManager::setImA(const char* imA = (const char*)NULL) {
    if (imA == (const char*)NULL) strcpy(this->imA, "0");
    else strcpy(this->imA, imA);
}
void ParamsManager::setReC(const char* reC = (const char*)NULL) {
    if (reC == (const char*)NULL) strcpy(this->reC, "0");
    else strcpy(this->reC, reC);
}
void ParamsManager::setImC(const char* imC = (const char*)NULL) {
    if (imC == (const char*)NULL) strcpy(this->imC, "0");
    else strcpy(this->imC, imC);
}
void ParamsManager::setBackgroundColor(ImVec4 backgroundColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f)) {
    this->backgroundColor = backgroundColor;
}

void ParamsManager::reset() {

    setRenderFractal();
    setHideMenu();
    setShowExportMenu();
    setReA();
    setImA();
    setReC();
    setImC();
    setBackgroundColor();

}