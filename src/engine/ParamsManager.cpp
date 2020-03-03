#include <iostream>
#include <fstream>
#include "ParamsManager.hpp"

ParamsManager::ParamsManager(){

    fractalParams = FractalParams::getInstance();
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
float ParamsManager::getSphereMinRadius() const { return fractalParams->getSphereMinRadius(); }
int ParamsManager::getSphereMinTimeVariance() const { return fractalParams->getSphereMinTimeVariance(); }
int ParamsManager::getTetraFactor() const { return fractalParams->getTetraFactor(); }
float ParamsManager::getTetraScale() const { return fractalParams->getTetraScale(); }
float ParamsManager::getTime() const { return fractalParams->getTime(); }
float ParamsManager::getNearPlane() const { return fractalParams->getNearPlane(); }
float ParamsManager::getFarPlane() const { return fractalParams->getFarPlane(); }
glm::mat4 ParamsManager::getInverseVP() const { return fractalParams->getInverseVP(); }
bool& ParamsManager::getRenderFractal() { return renderFractal; }
bool& ParamsManager::getHideMenu() { return hideMenu; }
bool& ParamsManager::getShowScreenshotMenu() { return showScreenshotMenu; }
bool& ParamsManager::getShowExportMenu() { return showExportMenu; }
bool& ParamsManager::getShowImportMenu() { return showImportMenu; }
char* ParamsManager::getReA() { return reA; }
char* ParamsManager::getImA() { return imA; }
char* ParamsManager::getReC() { return reC; }
char* ParamsManager::getImC() { return imC; }
ImVec4& ParamsManager::getBackgroundColor() { return backgroundColor; }
int ParamsManager::getSphereFoldFactor() const { return fractalParams->getSphereFoldFactor(); }

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
void ParamsManager::setInverseVP(Camera& camera, glm::mat4 inverseVP = (glm::mat4)(const float)NULL) { fractalParams->setInverseVP(camera, inverseVP); }
void ParamsManager::setRenderFractal(bool renderFractal = false) {
    this->renderFractal = renderFractal;
}
void ParamsManager::setHideMenu(bool hideMenu = true) {
    this->hideMenu = hideMenu;
}
void ParamsManager::setShowScreenshotMenu(bool showScreenshotMenu = false) {
    this->showScreenshotMenu = showScreenshotMenu;
}
void ParamsManager::setShowExportMenu(bool showExportMenu = false) {
    this->showExportMenu = showExportMenu;
}
void ParamsManager::setShowImportMenu(bool showImportMenu = false) {
    this->showImportMenu = showImportMenu;
}
void ParamsManager::setReA(const char* reA = (const char*)nullptr) {
    if (reA == (const char*)nullptr) strcpy(this->reA, "1");
    else strcpy(this->reA, reA);
}
void ParamsManager::setImA(const char* imA = (const char*)nullptr) {
    if (imA == (const char*)nullptr) strcpy(this->imA, "0");
    else strcpy(this->imA, imA);
}
void ParamsManager::setReC(const char* reC = (const char*)nullptr) {
    if (reC == (const char*)nullptr) strcpy(this->reC, "0");
    else strcpy(this->reC, reC);
}
void ParamsManager::setImC(const char* imC = (const char*)nullptr) {
    if (imC == (const char*)nullptr) strcpy(this->imC, "0");
    else strcpy(this->imC, imC);
}
void ParamsManager::setBackgroundColor(ImVec4 backgroundColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f)) {
    this->backgroundColor = backgroundColor;
}

void ParamsManager::reset() {

    setRenderFractal();
    setHideMenu();
    setShowScreenshotMenu();
    setShowExportMenu();
    setShowImportMenu();
    setReA();
    setImA();
    setReC();
    setImC();
    setBackgroundColor();

}

void ParamsManager::importSettings(std::string path) noexcept(false) {

    try {

        std::ifstream i(path);
        nlohmann::json j;
        i >> j;
        i.close();

        setBailLimit((float) j["bailLimit"]);
        setBaseColorStrength((float) j["baseColorStrength"]);
        setBgColor(glm::vec3(j["bgColor"]["x"], j["bgColor"]["y"], j["bgColor"]["z"]));
        setBoxFoldFactor((int) j["boxFoldFactor"]);
        setBoxFoldingLimit((float) j["boxFoldingLimit"]);
        setColor0(glm::vec3(j["color0"]["x"], j["color0"]["y"], j["color0"]["z"]));
        setColor1(glm::vec3(j["color1"]["x"], j["color1"]["y"], j["color1"]["z"]));
        setColor2(glm::vec3(j["color2"]["x"], j["color2"]["y"], j["color2"]["z"]));
        setColor3(glm::vec3(j["color3"]["x"], j["color3"]["y"], j["color3"]["z"]));
        setColorBase(glm::vec3(j["colorBase"]["x"], j["colorBase"]["y"], j["colorBase"]["z"]));
        setDerivativeBias((int) j["derivativeBias"]);
        setDiffuseIntensity((float) j["diffuseIntensity"]);
        setEyePos(glm::vec3(j["eyePos"]["x"], j["eyePos"]["y"], j["eyePos"]["z"]));
        setFractalIters((int) j["fractalIters"]);
        setFudgeFactor((float) j["fudgeFactor"]);
        setGammaCorrection((int) j["gammaCorrection"]);
        setGlowColor(glm::vec3(j["glowColor"]["x"], j["glowColor"]["y"], j["glowColor"]["z"]));
        setGlowFactor((float) j["glowFactor"]);
        setJulia((int) j["julia"]);
        setJuliaC(glm::vec3(j["juliaC"]["x"], j["juliaC"]["y"], j["juliaC"]["z"]));
        setLightPos(glm::vec3(j["lightPos"]["x"], j["lightPos"]["y"], j["lightPos"]["z"]));
        setLightSource((int) j["lightSource"]);
        setMandelBoxOn((int) j["mandelBoxOn"]);
        setMandelBoxScale((float) j["mandelBoxScale"]);
        setMandelbulbOn((int) j["mandelbulbOn"]);
        setMaxRaySteps((float) j["maxRaySteps"]);
        setMinDistance((float) j["minDistance"]);
        setNoiseFactor((float) j["noiseFactor"]);
        setOrbitStrength(glm::vec4(j["orbitStrength"]["x"], j["orbitStrength"]["y"], j["orbitStrength"]["z"], j["orbitStrength"]["w"]));
        setOtCycleIntensity((float) j["otCycleIntensity"]);
        setOtDist0to1((float) j["otDist0To1"]);
        setOtDist1to2((float) j["otDist1To2"]);
        setOtDist2to3((float) j["otDist2To3"]);
        setOtDist3to0((float) j["otDist3To0"]);
        setOtPaletteOffset((float) j["otPaletteOffset"]);
        setPhongShadingMixFactor((float) j["phongShadingMixFactor"]);
        setPower((float) j["power"]);
        setScreenSize(glm::vec2(j["screenSize"]["x"], j["screenSize"]["y"]));
        setShadowBrightness((float) j["shadowBrightness"]);
        setShadowRayMinStepsTaken((int) j["shadowRayMinStepsTaken"]);
        setShininess((float) j["shininess"]);
        setShowBgGradient((int) j["showBgGradient"]);
        setSpecularIntensity((float) j["specularIntensity"]);
        setSphereFixedRadius((float) j["sphereFixedRadius"]);
        setSphereFoldFactor((int) j["sphereFoldFactor"]);
        setSphereMinRadius((float) j["sphereMinRadius"]);
        setSphereMinTimeVariance((int) j["sphereMinTimeVariance"]);
        setTetraFactor((int) j["tetraFactor"]);
        setTetraScale((float) j["tetraScale"]);
        setTime((float) j["time"]);
        setNearPlane((float) j["nearPlane"]);
        setFarPlane((float) j["farPlane"]);
        setRenderFractal((bool) j["renderFractal"]);
        std::string t(j["reA"]);
        setReA(t.c_str());
        t = std::string(j["imA"]);
        setImA(t.c_str());
        t = std::string(j["reC"]);
        setReC(t.c_str());
        t = std::string(j["imC"]);
        setImC(t.c_str());
        setBackgroundColor(ImVec4(j["backgroundColor"]["x"], j["backgroundColor"]["y"], j["backgroundColor"]["z"], j["backgroundColor"]["w"]));

    } catch(...) {
        throw "An error occured while importing settings";
    }

}

void ParamsManager::exportSettings(std::string path) noexcept(false) {

    try {

        nlohmann::json j;

        j["bailLimit"] = getBailLimit();
        j["baseColorStrength"] = getBaseColorStrength();
        glm::vec3 t3 = getBgColor();
        j["bgColor"]["x"] = t3.x;
        j["bgColor"]["y"] = t3.y;
        j["bgColor"]["z"] = t3.z;
        j["boxFoldFactor"] = getBoxFoldFactor();
        j["boxFoldingLimit"] = getBoxFoldingLimit();
        t3 = getColor0();
        j["color0"]["x"] = t3.x;
        j["color0"]["y"] = t3.y;
        j["color0"]["z"] = t3.z;
        t3 = getColor1();
        j["color1"]["x"] = t3.x;
        j["color1"]["y"] = t3.y;
        j["color1"]["z"] = t3.z;
        t3 = getColor2();
        j["color2"]["x"] = t3.x;
        j["color2"]["y"] = t3.y;
        j["color2"]["z"] = t3.z;
        t3 = getColor3();
        j["color3"]["x"] = t3.x;
        j["color3"]["y"] = t3.y;
        j["color3"]["z"] = t3.z;
        t3 = getColorBase();
        j["colorBase"]["x"] = t3.x;
        j["colorBase"]["y"] = t3.y;
        j["colorBase"]["z"] = t3.z;
        j["derivativeBias"] = getDerivativeBias();
        j["diffuseIntensity"] = getDiffuseIntensity();
        t3 = getEyePos();
        j["eyePos"]["x"] = t3.x;
        j["eyePos"]["y"] = t3.y;
        j["eyePos"]["z"] = t3.z;
        j["fractalIters"] = getFractalIters();
        j["fudgeFactor"] = getFudgeFactor();
        j["gammaCorrection"] = getGammaCorrection();
        t3 = getGlowColor();
        j["glowColor"]["x"] = t3.x;
        j["glowColor"]["y"] = t3.y;
        j["glowColor"]["z"] = t3.z;
        j["glowFactor"] = getGlowFactor();
        j["julia"] = getJulia();
        t3 = getJuliaC();
        j["juliaC"]["x"] = t3.x;
        j["juliaC"]["y"] = t3.y;
        j["juliaC"]["z"] = t3.z;
        t3 = getLightPos();
        j["lightPos"]["x"] = t3.x;
        j["lightPos"]["y"] = t3.y;
        j["lightPos"]["z"] = t3.z;
        j["lightSource"] = getLightSource();
        j["mandelBoxOn"] = getMandelBoxOn();
        j["mandelBoxScale"] = getMandelBoxScale();
        j["mandelbulbOn"] = getMandelbulbOn();
        j["maxRaySteps"] = getMaxRaySteps();
        j["minDistance"] = getMinDistance();
        j["noiseFactor"] = getNoiseFactor();
        glm::vec4 t4 = getOrbitStrength();
        j["orbitStrength"]["x"] = t4.x;
        j["orbitStrength"]["y"] = t4.y;
        j["orbitStrength"]["z"] = t4.z;
        j["orbitStrength"]["w"] = t4.w;
        j["otCycleIntensity"] = getOtCycleIntensity();
        j["otDist0To1"] = getOtDist0to1();
        j["otDist1To2"] = getOtDist1to2();
        j["otDist2To3"] = getOtDist2to3();
        j["otDist3To0"] = getOtDist3to0();
        j["otPaletteOffset"] = getOtPaletteOffset();
        j["phongShadingMixFactor"] = getPhongShadingMixFactor();
        j["power"] = getPower();
        glm::vec2 t2 = getScreenSize();
        j["screenSize"]["x"] = t2.x;
        j["screenSize"]["y"] = t2.y;
        j["shadowBrightness"] = getShadowBrightness();
        j["shadowRayMinStepsTaken"] = getShadowRayMinStepsTaken();
        j["shininess"] = getShininess();
        j["showBgGradient"] = getShowBgGradient();
        j["specularIntensity"] = getSpecularIntensity();
        j["sphereFixedRadius"] = getSphereFixedRadius();
        j["sphereFoldFactor"] = getSphereFoldFactor();
        j["sphereMinRadius"] = getSphereMinRadius();
        j["sphereMinTimeVariance"] = getSphereMinTimeVariance();
        j["tetraFactor"] = getTetraFactor();
        j["tetraScale"] = getTetraScale();
        j["time"] = getTime();
        j["nearPlane"] = getNearPlane();
        j["farPlane"] = getFarPlane();
        j["renderFractal"] = getRenderFractal();
        j["reA"] = getReA();
        j["imA"] = getImA();
        j["reC"] = getReC();
        j["imC"] = getImC();
        ImVec4 v4 = getBackgroundColor();
        j["backgroundColor"]["x"] = v4.x;
        j["backgroundColor"]["y"] = v4.y;
        j["backgroundColor"]["z"] = v4.z;
        j["backgroundColor"]["w"] = v4.w;

        std::ofstream o(path);
        o << j << std::endl;
        o.close();

    }  catch(...)  {
        throw "An error occured while exporting settings";
    }

}