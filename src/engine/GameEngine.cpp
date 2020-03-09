/**
 * \file GameEngine.cpp
 * \brief The main loop of the program is located here
 * \author DUSSERVAIX V., OVEJERO D., TESSON L., VIOLLET R.
 * \date 22 January 2020
 *
 * In this class we instantiate everything, and we control the main loop
 */
#include <chrono>

#include "GameEngine.hpp"
#include "ParamsManager.hpp"
#include "../../lib/imgui/imgui.h"
#include "../../lib/imgui/imgui_impl_glfw.h"
#include "../../lib/imgui/imgui_impl_opengl3.h"

#define FPS 60

/**
 * Constructor of GameEngine, Instantiate game, window
 *
 */
GameEngine::GameEngine() : game(), window(appName, 1920, 1080){

    game.init();

}

/**
 * Manage the main loop
 *
 */
void GameEngine::loop() {

    // Decide GL+GLSL versions
    #if __APPLE__
        // GL 3.2 + GLSL 150
        const char* glsl_version = "#version 150";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
    #else
        // GL 3.0 + GLSL 130
        const char* glsl_version = "#version 130";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
    #endif

    timespec waitingTime{0, 0};
    long waitingTimeNano = (long) (1.0 / FPS * 1'000'000'000.0);
    int i = 0;
    double start = glfwGetTime();

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window.getHandle(), true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Our state
    auto *paramsManager = new ParamsManager();
    float glowFactor, lightPos[3], shadowBrightness, phongShadingMixFactor,
        ambientIntensity, diffuseIntensity, specularIntensity, minDistance,
        noiseFactor, shininess, power, maxRaySteps, sphereFixedRadius,
        sphereMinRadius, tetraScale, time, sphereFoldFactor, juliaC[3],
        baseColorStrength, bailLimit,orbitStrength[4], otCycleIntensity,
        otDist0to1, otDist1to2, otDist2to3, otDist3to0, otPaletteOffset,
        screenSize[2], nearPlane, farPlane, eyePos[3], fudgeFactor,
        boxFoldingLimit, mandelBoxScale;
    int lightSource, shadowRayMinStepsTaken, gammaCorrection, fractalIters,
        sphereMinTimeVariance, tetraFactor, derivativeBias, boxFoldFactor;
    bool showBgGradient, mandelbulbOn, julia, mandelBoxOn;
    ImVec4 glowColor, bgColor, color0, color1, color2, color3, colorBase;

    while (!window.shouldClose()){

        ImVec4 backgroundColor = paramsManager->getBackgroundColor();
        window.setColor(backgroundColor.x, backgroundColor.y, backgroundColor.z, backgroundColor.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        auto loopStart = std::chrono::high_resolution_clock::now();

        if (window.getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS){

            window.close();

        }
        if (window.getKey(GLFW_KEY_F3) == GLFW_PRESS) {

            paramsManager->setHideMenu(false);

        }
        if (window.getKey(GLFW_KEY_G) == GLFW_PRESS) {

            paramsManager->setRenderFractal(true);

        }
        if (window.getKey(GLFW_KEY_H) == GLFW_PRESS) {

            paramsManager->setRenderFractal(false);

        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if (!paramsManager->getHideMenu()) {

            ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_MenuBar);

            if (ImGui::BeginMenuBar()) {
                if (ImGui::BeginMenu("File")) {
                    ImGui::MenuItem("Export", nullptr, &paramsManager->getShowExportMenu());
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

            if (ImGui::BeginTabBar("Settings")) {
                if (ImGui::BeginTabItem("GUI")) {

                    ImGui::Text("Equation: z_(n+1)=a*(z_n)^2+c");
                    char *reA = paramsManager->getReA(),
                            *imA = paramsManager->getImA(),
                            *reC = paramsManager->getReC(),
                            *imC = paramsManager->getImC();

                    // TODO Fix IM_ARRAYSIZE usage
                    ImGui::InputText("Re(a)", reA, IM_ARRAYSIZE(reA));
                    ImGui::InputText("Im(a)", imA, IM_ARRAYSIZE(imA));
                    ImGui::InputText("Re(c)", reC, IM_ARRAYSIZE(reC));
                    ImGui::InputText("Im(c)", imC, IM_ARRAYSIZE(imC));

                    ImGui::Checkbox("Render fractal", &paramsManager->getRenderFractal());

                    ImGui::ColorEdit3("Background color", (float*)&paramsManager->getBackgroundColor());

                    if (ImGui::Button("Hide menu"))
                        paramsManager->setHideMenu(true);

                    ImGui::EndTabItem();
                }
                //GRAPHICS---------------------------------------------------------------
                if (ImGui::BeginTabItem("Graphics")) {

                    //----GLOW-----------------------------------------------------------
                    if (ImGui::TreeNode("Glow")) {

                        glowFactor = paramsManager->getGlowFactor();
                        ImGui::SliderFloat("Glow factor", &glowFactor, 0.0f, 6.0f);
                        paramsManager->setGlowFactor(glowFactor);

                        glm::vec3 c = paramsManager->getGlowColor();
                        glowColor.x = c.x;
                        glowColor.y = c.y;
                        glowColor.z = c.z;
                        ImGui::ColorEdit3("Glow color", (float*)&glowColor);
                        paramsManager->setGlowColor(glm::vec3(glowColor.x, glowColor.y, glowColor.z));

                        ImGui::Separator();

                        ImGui::TreePop();
                    }
                    //----SHADOW---------------------------------------------------------
                    if (ImGui::TreeNode("Shadow")) {

                        lightSource = paramsManager->getLightSource();
                        //TODO: find bounds
                        ImGui::SliderInt("Light source", &lightSource, 0, 10);
                        paramsManager->setLightSource(lightSource);

                        shadowBrightness = paramsManager->getShadowBrightness();
                        ImGui::SliderFloat("Shadow brightness", &shadowBrightness, 0.0f, 3.0f);
                        paramsManager->setShadowBrightness(shadowBrightness);

                        shadowRayMinStepsTaken = paramsManager->getShadowRayMinStepsTaken();
                        //TODO: find bounds seems good like that
                        ImGui::SliderInt("Shadow ray min steps taken", &shadowRayMinStepsTaken, 0, 10);
                        paramsManager->setShadowRayMinStepsTaken(shadowRayMinStepsTaken);

                        ImGui::Separator();

                        ImGui::TreePop();
                    }
                    //----AMBIENT--------------------------------------------------------
                    if (ImGui::TreeNode("Ambient")) {

                        phongShadingMixFactor = paramsManager->getPhongShadingMixFactor();
                        ImGui::SliderFloat("Phong Shading Mix Factor", &phongShadingMixFactor, 0.0f, 18.0f);
                        paramsManager->setPhongShadingMixFactor(phongShadingMixFactor);

                        ambientIntensity = paramsManager->getAmbientIntensity();
                        ImGui::SliderFloat("Ambient intensity", &ambientIntensity, 0.0f, 20.0f);
                        paramsManager->setAmbientIntensity(ambientIntensity);

                        diffuseIntensity = paramsManager->getDiffuseIntensity();
                        ImGui::SliderFloat("Diffuse intensity", &diffuseIntensity, 0.0f, 7.0f);
                        paramsManager->setDiffuseIntensity(diffuseIntensity);

                        specularIntensity = paramsManager->getSpecularIntensity();
                        ImGui::SliderFloat("Specular intensity", &specularIntensity, 0.0f, 7.0f);
                        paramsManager->setSpecularIntensity(specularIntensity);

                        ImGui::Separator();

                        ImGui::TreePop();
                    }
                    //----IMAGERENDER----------------------------------------------------
                    if (ImGui::TreeNode("Image Render")) {

                        gammaCorrection = paramsManager->getGammaCorrection();
                        //TODO: find bounds
                        ImGui::SliderInt("Gamma correction", &gammaCorrection, 0, 10);
                        paramsManager->setGammaCorrection(gammaCorrection);

                        //TODO: find why values change when rendering
                        glm::vec3 l = paramsManager->getLightPos();
                        lightPos[0] = l.x; lightPos[1] = l.y; lightPos[2] = l.z;
                        ImGui::InputFloat("LightPos[x]", &lightPos[0]);
                        ImGui::InputFloat("LightPos[y]", &lightPos[1]);
                        ImGui::InputFloat("LightPos[z]", &lightPos[2]);
                        paramsManager->setLightPos(glm::vec3(lightPos[0], lightPos[1], lightPos[2]));

                        minDistance = paramsManager->getMinDistance();
                        ImGui::SliderFloat("Min distance", &minDistance, 0.0f, 0.3f);
                        paramsManager->setMinDistance(minDistance);

                        noiseFactor = paramsManager->getNoiseFactor();
                        ImGui::SliderFloat("Noise factor", &noiseFactor, 0.0f, 30.0f);
                        paramsManager->setNoiseFactor(noiseFactor);

                        ImGui::Separator();

                        ImGui::TreePop();
                    }
                    //----BRIGHTNESS-----------------------------------------------------
                    if (ImGui::TreeNode("Brightness")) {

                        shininess = paramsManager->getShininess();
                        //TODO: find bounds strange [0;10]
                        ImGui::SliderFloat("Shininess", &shininess, 0.0f, 100.0f);
                        paramsManager->setShininess(shininess);

                        ImGui::TreePop();
                    }

                    ImGui::EndTabItem();
                }
                //-----------------------------------------------------------------------

                //MATH-------------------------------------------------------------------
                if (ImGui::BeginTabItem("Math")) {

                    //----MATH-----------------------------------------------------------
                    if (ImGui::TreeNode("Math")) {

                        fractalIters = paramsManager->getFractalIters();
                        //TODO: find bounds
                        ImGui::SliderInt("Fractal Iters", &fractalIters, 0, 10);
                        paramsManager->setFractalIters(fractalIters);

                        power = paramsManager->getPower();
                        //TODO: find bounds
                        ImGui::SliderFloat("Power", &power, -16.0f, 16.0f);
                        paramsManager->setPower(power);

                        ImGui::Separator();

                        ImGui::TreePop();

                    }
                    //----PRECISION------------------------------------------------------
                    if (ImGui::TreeNode("Precision")) {

                        maxRaySteps = paramsManager->getMaxRaySteps();
                        ImGui::SliderFloat("Max ray steps", &maxRaySteps, 0.0f, 2000.0f);
                        paramsManager->setMaxRaySteps(maxRaySteps);

                        showBgGradient = (bool)paramsManager->getShowBgGradient();
                        ImGui::Checkbox("Show background gradient", &showBgGradient);
                        paramsManager->setShowBgGradient((int)showBgGradient);

                        sphereFixedRadius = paramsManager->getSphereFixedRadius();
                        ImGui::SliderFloat("Sphere fixed radius", &sphereFixedRadius, 0.0f, 500.0f);
                        paramsManager->setSphereFixedRadius(sphereFixedRadius);

                        sphereMinRadius = paramsManager->getSphereMinRadius();
                        ImGui::SliderFloat("Sphere min radius", &sphereMinRadius, 0.0f, 20.0f);
                        paramsManager->setSphereMinRadius(sphereMinRadius);

                        //TODO: find why it is not working => sphereMinTimeVariance must be a bool with a checkBox
                        sphereMinTimeVariance = paramsManager->getSphereMinTimeVariance();
                        ImGui::InputInt("Sphere min time variance", &sphereMinTimeVariance);
                        paramsManager->setSphereMinTimeVariance(sphereMinTimeVariance);

                        tetraFactor = paramsManager->getTetraFactor();
                        ImGui::SliderInt("Tetra factor", &tetraFactor, 0, 10);
                        paramsManager->setTetraFactor(tetraFactor);

                        tetraScale  = paramsManager->getTetraScale();
                        ImGui::SliderFloat("Tetra scale", &tetraScale, 0.0f, 10.0f);
                        paramsManager->setTetraScale(tetraScale);

                        time = paramsManager->getTime();
                        ImGui::SliderFloat("Time", &time, 0.0f, 10.0f);
                        paramsManager->setTime(time);

                        ImGui::Separator();

                        ImGui::TreePop();

                    }
                    //----FRACTAL--------------------------------------------------------
                    if (ImGui::TreeNode("Fractal")) {

                        mandelbulbOn = paramsManager->getMandelbulbOn();
                        ImGui::Checkbox("Mandelbulb ON", &mandelbulbOn);
                        paramsManager->setMandelbulbOn(mandelbulbOn);

                        julia = paramsManager->getJulia();
                        ImGui::Checkbox("Julia", &julia);
                        paramsManager->setJulia(julia);

                        glm::vec3 j = paramsManager->getJuliaC();
                        juliaC[0] = j.x; juliaC[1] = j.y; juliaC[2] = j.z;
                        ImGui::InputFloat("Julia C[0]", &juliaC[0]);
                        ImGui::InputFloat("Julia C[1]", &juliaC[1]);
                        ImGui::InputFloat("Julia C[2]", &juliaC[2]);
                        paramsManager->setJuliaC(glm::vec3(juliaC[0], juliaC[1], juliaC[2]));

                        ImGui::Separator();

                        ImGui::TreePop();

                    }
                    //----OTHERS---------------------------------------------------------
                    if (ImGui::TreeNode("Others")) {
                        sphereFoldFactor = paramsManager->getSphereFoldFactor();
                        std::cout << sphereFoldFactor;
                        ImGui::SliderFloat("Sphere fold factor", &sphereFoldFactor, 0.0f, 45.0f);
                        // TODO Fix conversion
                        paramsManager->setSphereFoldFactor(sphereFoldFactor);

                        ImGui::Separator();

                        ImGui::TreePop();

                    }

                    ImGui::EndTabItem();
                }
                //-----------------------------------------------------------------------

                //COLORS-----------------------------------------------------------------
                if (ImGui::BeginTabItem("Colors")) {

                    //----COLORS---------------------------------------------------------
                    if(ImGui::TreeNode("Colors")) {

                        glm::vec3 c0 = paramsManager->getColor0();
                        color0.x = c0.x;
                        color0.y = c0.y;
                        color0.z = c0.z;
                        ImGui::ColorEdit3("Color0", (float*)&color0);
                        paramsManager->setColor0(glm::vec3(color0.x, color0.y, color0.z));

                        glm::vec3 c1 = paramsManager->getColor1();
                        color1.x = c1.x;
                        color1.y = c1.y;
                        color1.z = c1.z;
                        ImGui::ColorEdit3("Color1", (float*)&color1);
                        paramsManager->setColor1(glm::vec3(color1.x, color1.y, color1.z));

                        glm::vec3 c2 = paramsManager->getColor2();
                        color2.x = c2.x;
                        color2.y = c2.y;
                        color2.z = c2.z;
                        ImGui::ColorEdit3("Color2", (float*)&color2);
                        paramsManager->setColor2(glm::vec3(color2.x, color2.y, color2.z));

                        glm::vec3 c3 = paramsManager->getColor3();
                        color3.x = c3.x;
                        color3.y = c3.y;
                        color3.z = c3.z;
                        ImGui::ColorEdit3("Color3", (float*)&color3);
                        paramsManager->setColor3(glm::vec3(color3.x, color3.y, color3.z));

                        glm::vec3 c = paramsManager->getColorBase();
                        colorBase.x = c.x;
                        colorBase.y = c.y;
                        colorBase.z = c.z;
                        ImGui::ColorEdit3("Color base", (float*)&colorBase);
                        paramsManager->setColorBase(glm::vec3(colorBase.x, colorBase.y, colorBase.z));

                        ImGui::Separator();

                        ImGui::TreePop();

                    }
                    //----STRENGTH-------------------------------------------------------
                    if (ImGui::TreeNode("Strength")) {

                        baseColorStrength = paramsManager->getBaseColorStrength();
                        ImGui::SliderFloat("Base color strength", &baseColorStrength, 0.0f, 1.0f);
                        paramsManager->setBaseColorStrength(baseColorStrength);

                        ImGui::Separator();

                        ImGui::TreePop();

                    }

                    ImGui::EndTabItem();
                }
                //-----------------------------------------------------------------------

                //OTHERS-----------------------------------------------------------------
                if (ImGui::BeginTabItem("Others")) {

                    //----OTHERS---------------------------------------------------------
                    if (ImGui::TreeNode("Others")) {

                        bailLimit = paramsManager->getBailLimit();
                        ImGui::SliderFloat("Bail limit", &bailLimit, 1.0f, 2.0f);
                        paramsManager->setBailLimit(bailLimit);

                        glm::vec4 o = paramsManager->getOrbitStrength();
                        orbitStrength[0] = o.x;
                        orbitStrength[1] = o.y;
                        orbitStrength[2] = o.z;
                        orbitStrength[3] = o.w;
                        ImGui::SliderFloat("Orbit Strength[x]", &orbitStrength[0], 0.0f, 5.0f);
                        ImGui::SliderFloat("Orbit Strength[y]", &orbitStrength[1], 0.0f, 5.0f);
                        ImGui::SliderFloat("Orbit Strength[z]", &orbitStrength[2], 0.0f, 5.0f);
                        ImGui::SliderFloat("Orbit Strength[w]", &orbitStrength[3], 0.0f, 5.0f);
                        paramsManager->setOrbitStrength(glm::vec4(orbitStrength[0], orbitStrength[1], orbitStrength[2], orbitStrength[3]));

                        otCycleIntensity = paramsManager->getOtCycleIntensity();
                        ImGui::SliderFloat("OT Cycle Intensity", &otCycleIntensity, 0.0f, 20.0f);
                        paramsManager->setOtCycleIntensity(otCycleIntensity);

                        otDist0to1 = paramsManager->getOtDist0to1();
                        ImGui::SliderFloat("OT Dist 0 to 1", &otDist0to1, 0.0f, 20.0f);
                        paramsManager->setOtDist0to1(otDist0to1);

                        otDist1to2 = paramsManager->getOtDist1to2();
                        ImGui::SliderFloat("OT Dist 1 to 2", &otDist1to2, 0.0f, 20.0f);
                        paramsManager->setOtDist1to2(otDist1to2);

                        otDist2to3 = paramsManager->getOtDist2to3();
                        ImGui::SliderFloat("OT Dist 2 to 3", &otDist2to3, 0.0f, 20.0f);
                        paramsManager->setOtDist2to3(otDist2to3);

                        otDist3to0 = paramsManager->getOtDist3to0();
                        ImGui::SliderFloat("OT Dist 3 to 0", &otDist3to0, 0.0f, 20.0f);
                        paramsManager->setOtDist3to0(otDist3to0);

                        otPaletteOffset = paramsManager->getOtPaletteOffset();
                        ImGui::SliderFloat("OT Palette Offset", &otPaletteOffset, 0.0f, 100.0f);
                        paramsManager->setOtPaletteOffset(otPaletteOffset);

                        glm::vec2 s = paramsManager->getScreenSize();
                        screenSize[0] = s.x;
                        screenSize[1] = s.y;
                        ImGui::SliderFloat("Screen size[0]", &screenSize[0], 0.0f, 2000.0f);
                        ImGui::SliderFloat("Screen size[1]", &screenSize[1], 0.0f, 2000.0f);
                        paramsManager->setScreenSize(glm::vec2(screenSize[0], screenSize[1]));

                        nearPlane = paramsManager->getNearPlane();
                        ImGui::SliderFloat("Near plane", &nearPlane, 0.0f, 1.0f);
                        paramsManager->setNearPlane(nearPlane);

                        farPlane = paramsManager->getFarPlane();
                        ImGui::SliderFloat("Far plane", &farPlane, 1.0f, 100.0f);
                        paramsManager->setFarPlane(farPlane);

                        //TODO: find usage of inverseVP

                        derivativeBias = paramsManager->getDerivativeBias();
                        ImGui::SliderInt("Derivative bias", &derivativeBias, 0, 200);
                        paramsManager->setDerivativeBias(derivativeBias);

                        glm::vec3 e = paramsManager->getEyePos();
                        eyePos[0] = e.x;
                        eyePos[1] = e.y;
                        eyePos[2] = e.z;
                        //TODO: find bounds
                        ImGui::SliderFloat("Eye pos[0]", &eyePos[0], 0.0f, 3.0f);
                        ImGui::SliderFloat("Eye pos[1]", &eyePos[1], 0.0f, 3.0f);
                        ImGui::SliderFloat("Eye pos[2]", &eyePos[2], 0.0f, 3.0f);
                        paramsManager->setEyePos(glm::vec3(eyePos[0], eyePos[1], eyePos[2]));

                        fudgeFactor = paramsManager->getFudgeFactor();
                        ImGui::SliderFloat("Fudge factor", &fudgeFactor, 0.0f, 50.0f);
                        paramsManager->setFudgeFactor(fudgeFactor);

                        ImGui::Separator();

                        ImGui::TreePop();

                    }
                    //----BOX------------------------------------------------------------
                    if (ImGui::TreeNode("Box")) {

                        boxFoldFactor = paramsManager->getBoxFoldFactor();
                        ImGui::SliderInt("Box fold factor", &boxFoldFactor, 0, 50);
                        paramsManager->setBoxFoldFactor(boxFoldFactor);

                        boxFoldingLimit = paramsManager->getBoxFoldingLimit();
                        ImGui::SliderFloat("Box folding limit", &boxFoldingLimit, 0.0f, 10.0f);
                        paramsManager->setBoxFoldingLimit(boxFoldingLimit);

                        mandelBoxOn = (bool)paramsManager->getMandelBoxOn();
                        ImGui::Checkbox("MandelBox ON", &mandelBoxOn);
                        paramsManager->setMandelBoxOn((int)mandelBoxOn);

                        mandelBoxScale = paramsManager->getMandelBoxScale();
                        ImGui::SliderFloat("MandelBox scale", &mandelBoxScale, 0.0f, 5.0f);
                        paramsManager->setMandelBoxScale(mandelBoxScale);

                        ImGui::Separator();

                        ImGui::TreePop();

                    }

                    ImGui::EndTabItem();
                }

                ImGui::EndTabBar();
            }

            ImGui::End();

        }

        game.input(window);

        if (paramsManager->getRenderFractal()) {

            paramsManager->setBgColor(glm::vec3(backgroundColor.x, backgroundColor.y, backgroundColor.z));
            game.update();
            game.render(window);

        }

        waitingTime.tv_nsec = waitingTimeNano -
                std::chrono::duration_cast<std::chrono::nanoseconds>(
                        std::chrono::high_resolution_clock::now() - loopStart
                        ).count();
        nanosleep(&waitingTime, nullptr);

        if (glfwGetTime() - start >= 1){

            window.setTitle((std::string(appName) + separator + std::to_string(i) + "FPS").c_str());
            start = glfwGetTime();
            i = 0;

        }

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        window.swapBuffers();
        glfwPollEvents();

        ++i;

    }

}