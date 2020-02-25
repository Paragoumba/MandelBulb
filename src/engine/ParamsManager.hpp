#ifndef PTUT_PARAMSMANAGER_HPP
#define PTUT_PARAMSMANAGER_HPP

#include "FractalParams.hpp"
#include "../../lib/imgui/imgui.h"

class ParamsManager {
private:
    FractalParams *fractalParams;

    /*****MAIN MENU*****/
    bool renderFractal;
    bool hideMenu;
    bool showExportMenu;
    char reA[8];
    char imA[8];
    char reC[8];
    char imC[8];
    ImVec4 backgroundColor;

public:
    ParamsManager(Camera);

    //GUI------------------------------------------------------------------
    bool& getRenderFractal();
    bool& getHideMenu();
    bool& getShowExportMenu();
    char* getReA();
    char* getImA();
    char* getReC();
    char* getImC();
    ImVec4& getBackgroundColor();
    //---------------------------------------------------------------------

    //GRAPHIC------------------------------------------------------------
    //----GLOW-----------------------------------------------------------
    float getGlowFactor() const;
    glm::vec3 getGlowColor() const;
    //----SHADOW---------------------------------------------------------
    float getLightAngle() const;
    int getLightSource() const;
    float getShadowBrightness() const;
    int getShadowRayMinStepsTaken() const;
    //----AMBIENT--------------------------------------------------------
    float getPhongShadingMixFactor() const;
    float getAmbientIntensity() const;
    float getDiffuseIntensity() const;
    float getSpecularIntensity() const;
    //----IMAGERENDER---------------------------------------------------
    int getGammaCorrection() const;
    glm::vec3 getLightPos() const;
    float getMinDistance() const;
    float getNoiseFactor() const;
    //----BRIGHTNESS-----------------------------------------------------
    float getShininess() const;
    //-------------------------------------------------------------------

    //FRACTAL------------------------------------------------------------
    int getMandelbulbOn() const;
    int getJulia() const;
    glm::vec3 getJuliaC() const;
    //-------------------------------------------------------------------

    //MATH---------------------------------------------------------------
    int getFractalIters() const;
    float getPower() const;
    //----PRECISION------------------------------------------------------
    float getMaxRaySteps() const;
    int getShowBgGradient() const;
    float getSphereFixedRadius() const;
    float getSphereMinRadius() const;
    int getSphereMinTimeVariance() const;
    int getTetraFactor() const;
    float getTetraScale() const;
    float getTime() const;
    //----FRACTAL--------------------------------------------------------
    int getMandelbulbOn() const;
    int getJulia() const;
    glm::vec3 getJuliaC() const;
    //----OTHER----------------------------------------------------------
    float getSphereFoldFactor() const;
    //-------------------------------------------------------------------

    //COLOR---------------------------------------------------------------
    glm::vec3 getBgColor() const;
    glm::vec3 getColor0() const;
    glm::vec3 getColor1() const;
    glm::vec3 getColor2() const;
    glm::vec3 getColor3() const;
    glm::vec3 getColorBase() const;
    //----STRENGTH---------------------------------------------------------
    float getBaseColorStrength() const;
    //---------------------------------------------------------------------

    //OTHER----------------------------------------------------------------
    float getBailLimit() const;
    //---------------------------------------------------------------------


    int getDerivativeBias() const;
    glm::vec3 getEyePos() const;
    float getFudgeFactor() const;

    //IMAGE RENDERER ------------------------------------------------------
    int getGammaCorrection() const;
    glm::vec3 getLightPos() const;
    float getMinDistance() const;
    float getNoiseFactor() const;

    //JSP
    glm::vec4 getOrbitStrength() const;
    float getOtCycleIntensity() const;
    float getOtDist0to1() const;
    float getOtDist1to2() const;
    float getOtDist2to3() const;
    float getOtDist3to0() const;


    float getOtPaletteOffset() const;
    glm::vec2 getScreenSize() const;

    //SHADOW ---------------------------------------------------------------
    float getShadowBrightness() const;
    int getShadowRayMinStepsTaken() const;

    //SPHERE MANAGER--------------------------------------------------------
    int getShowBgGradient() const;
    float getSphereFixedRadius() const;
    float getSphereMinRadius() const;
    int getSphereMinTimeVariance() const;
    int getTetraFactor() const;
    float getTetraScale() const;
    float getTime() const;


    float getNearPlane() const;
    float getFarPlane() const;
    glm::mat4 getInverseVP() const;
    int getDerivativeBias() const;
    glm::vec3 getEyePos() const;
    float getFudgeFactor() const;
    //----BOX--------------------------------------------------------------
    int getBoxFoldFactor() const;
    float getBoxFoldingLimit() const;
    int getMandelBoxOn() const;
    float getMandelBoxScale() const;
    //---------------------------------------------------------------------

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
    void setCamera(Camera);
    void setInverseVP(glm::mat4);
    void setRenderFractal(bool);
    void setHideMenu(bool);
    void setShowExportMenu(bool);
    void setReA(const char*);
    void setImA(const char*);
    void setReC(const char*);
    void setImC(const char*);
    void setBackgroundColor(ImVec4);

    ~ParamsManager() = default;

};

#endif //PTUT_PARAMSMANAGER_HPP