#ifndef PTUT_PARAMSMANAGER_HPP
#define PTUT_PARAMSMANAGER_HPP

#include "FractalParams.hpp"
#include <nlohmann/json.hpp>
#include "../../lib/imgui/imgui.h"

class ParamsManager {
private:
    FractalParams *fractalParams;

    /*****MAIN MENU*****/
    bool renderFractal{};
    bool hideMenu{};
    bool showScreenshotMenu{};
    bool showExportMenu{};
    bool showImportMenu{};
    char reA[8]{};
    char imA[8]{};
    char reC[8]{};
    char imC[8]{};
    ImVec4 backgroundColor;

public:
    ParamsManager();

    //GUI----------------------------------------------------------------
    bool& getRenderFractal();
    bool& getHideMenu();
    bool& getShowScreenshotMenu();
    bool& getShowExportMenu();
    bool& getShowImportMenu();
    char* getReA();
    char* getImA();
    char* getReC();
    char* getImC();
    ImVec4& getBackgroundColor();
    //-------------------------------------------------------------------

    // TODO Fix warnings
    //----GLOW-----------------------------------------------------------
    [[nodiscard]] float getGlowFactor() const;
    [[nodiscard]] glm::vec3 getGlowColor() const;
    //----SHADOW---------------------------------------------------------
    [[nodiscard]] int getLightSource() const;
    [[nodiscard]] float getShadowBrightness() const;
    [[nodiscard]] int getShadowRayMinStepsTaken() const;
    //----AMBIENT--------------------------------------------------------
    [[nodiscard]] float getPhongShadingMixFactor() const;
    [[nodiscard]] float getAmbientIntensity() const;
    [[nodiscard]] float getDiffuseIntensity() const;
    [[nodiscard]] float getSpecularIntensity() const;
    //----IMAGERENDER----------------------------------------------------
    [[nodiscard]] int getGammaCorrection() const;
    [[nodiscard]] glm::vec3 getLightPos() const;
    [[nodiscard]] float getMinDistance() const;
    [[nodiscard]] float getNoiseFactor() const;
    //----BRIGHTNESS-----------------------------------------------------
    [[nodiscard]] float getShininess() const;
    //-------------------------------------------------------------------

    //MATH---------------------------------------------------------------
    //----MATH-----------------------------------------------------------
    [[nodiscard]] int getFractalIters() const;
    [[nodiscard]] float getPower() const;
    //----PRECISION------------------------------------------------------
    [[nodiscard]] float getMaxRaySteps() const;
    [[nodiscard]] int getShowBgGradient() const;
    [[nodiscard]] float getSphereFixedRadius() const;
    [[nodiscard]] float getSphereMinRadius() const;
    [[nodiscard]] int getSphereMinTimeVariance() const;
    [[nodiscard]] int getTetraFactor() const;
    [[nodiscard]] float getTetraScale() const;
    [[nodiscard]] float getTime() const;
    //----FRACTAL--------------------------------------------------------
    [[nodiscard]] int getMandelbulbOn() const;
    [[nodiscard]] int getJulia() const;
    [[nodiscard]] glm::vec3 getJuliaC() const;
    //----OTHERS---------------------------------------------------------
    [[nodiscard]] int getSphereFoldFactor() const;
    //-------------------------------------------------------------------

    //COLORS-------------------------------------------------------------
    //----COLORS---------------------------------------------------------
    [[nodiscard]] glm::vec3 getBgColor() const;
    [[nodiscard]] glm::vec3 getColor0() const;
    [[nodiscard]] glm::vec3 getColor1() const;
    [[nodiscard]] glm::vec3 getColor2() const;
    [[nodiscard]] glm::vec3 getColor3() const;
    [[nodiscard]] glm::vec3 getColorBase() const;
    //----STRENGTH-------------------------------------------------------
    [[nodiscard]] float getBaseColorStrength() const;
    //-------------------------------------------------------------------

    //OTHERS-------------------------------------------------------------
    //----OTHERS---------------------------------------------------------
    [[nodiscard]] float getBailLimit() const;
    [[nodiscard]] glm::vec4 getOrbitStrength() const;
    [[nodiscard]] float getOtCycleIntensity() const;
    [[nodiscard]] float getOtDist0to1() const;
    [[nodiscard]] float getOtDist1to2() const;
    [[nodiscard]] float getOtDist2to3() const;
    [[nodiscard]] float getOtDist3to0() const;
    [[nodiscard]] float getOtPaletteOffset() const;
    [[nodiscard]] glm::vec2 getScreenSize() const;
    [[nodiscard]] float getNearPlane() const;
    [[nodiscard]] float getFarPlane() const;
    [[nodiscard]] int getDerivativeBias() const;
    [[nodiscard]] glm::vec3 getEyePos() const;
    [[nodiscard]] float getFudgeFactor() const;
    //----BOX------------------------------------------------------------
    [[nodiscard]] int getBoxFoldFactor() const;
    [[nodiscard]] float getBoxFoldingLimit() const;
    [[nodiscard]] int getMandelBoxOn() const;
    [[nodiscard]] float getMandelBoxScale() const;
    //-------------------------------------------------------------------

    void reset();
    void importSettings(const std::string&) noexcept(false);
    void exportSettings(std::string) noexcept(false);

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
    void setRenderFractal(bool);
    void setHideMenu(bool);
    void setShowScreenshotMenu(bool);
    void setShowExportMenu(bool);
    void setShowImportMenu(bool);
    void setReA(const char*);
    void setImA(const char*);
    void setReC(const char*);
    void setImC(const char*);
    void setBackgroundColor(ImVec4);

    ~ParamsManager();

};

#endif //PTUT_PARAMSMANAGER_HPP