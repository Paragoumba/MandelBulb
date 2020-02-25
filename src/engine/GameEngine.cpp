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
        noiseFactor, shininess;
    int lightSource, shadowRayMinStepsTaken, gammaCorrection;
    ImVec4 glowColor;

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
                    ImGui::MenuItem("Export", NULL, &paramsManager->getShowExportMenu());
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
                        //TODO: find bounds
                        ImGui::SliderFloat("Glow factor", &glowFactor, 0.0f, 10.0f);
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
                        //TODO: find bounds
                        ImGui::SliderFloat("Shadow brightness", &shadowBrightness, 0.0f, 1.0f);
                        paramsManager->setShadowBrightness(shadowBrightness);

                        shadowRayMinStepsTaken = paramsManager->getShadowRayMinStepsTaken();
                        //TODO: find bounds
                        ImGui::SliderInt("Shadow ray min steps taken", &shadowRayMinStepsTaken, 0, 10);
                        paramsManager->setShadowRayMinStepsTaken(shadowRayMinStepsTaken);

                        ImGui::Separator();

                        ImGui::TreePop();
                    }
                    //----AMBIENT--------------------------------------------------------
                    if (ImGui::TreeNode("Ambient")) {

                        phongShadingMixFactor = paramsManager->getPhongShadingMixFactor();
                        //TODO: find bounds
                        ImGui::SliderFloat("Phong Shading Mix Factor", &phongShadingMixFactor, 0.0f, 10.0f);
                        paramsManager->setPhongShadingMixFactor(phongShadingMixFactor);

                        ambientIntensity = paramsManager->getAmbientIntensity();
                        //TODO: find bounds
                        ImGui::SliderFloat("Ambient intensity", &ambientIntensity, 0.0f, 10.0f);
                        paramsManager->setAmbientIntensity(ambientIntensity);

                        diffuseIntensity = paramsManager->getDiffuseIntensity();
                        //TODO: find bounds
                        ImGui::SliderFloat("Diffuse intensity", &diffuseIntensity, 0.0f, 10.0f);
                        paramsManager->setDiffuseIntensity(diffuseIntensity);

                        specularIntensity = paramsManager->getSpecularIntensity();
                        //TODO: find bounds
                        ImGui::SliderFloat("Specular intensity", &specularIntensity, 0.0f, 10.0f);
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
                        //TODO: find bounds
                        ImGui::SliderFloat("Min distance", &minDistance, 0.0f, 1.0f);
                        paramsManager->setMinDistance(minDistance);

                        noiseFactor = paramsManager->getNoiseFactor();
                        //TODO: find bounds
                        ImGui::SliderFloat("Noise factor", &noiseFactor, 0.0f, 10.0f);
                        paramsManager->setNoiseFactor(noiseFactor);

                        ImGui::Separator();

                        ImGui::TreePop();
                    }
                    //----BRIGHTNESS-----------------------------------------------------
                    if (ImGui::TreeNode("Brightness")) {

                        shininess = paramsManager->getShininess();
                        //TODO: find bounds
                        ImGui::SliderFloat("Shininess", &shininess, 0.0f, 100.0f);
                        paramsManager->setShininess(shininess);

                        ImGui::TreePop();
                    }

                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("Math")) {

                    ImGui::Text("Precision");
                    ImGui::Separator();

                    ImGui::Text("Fractal");
                    ImGui::Separator();

                    ImGui::Text("Others");

                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("Colors")) {

                    ImGui::Text("Colors");
                    ImGui::Separator();

                    ImGui::Text("Strength");

                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("Others")) {

                    ImGui::Text("Others");
                    ImGui::Separator();

                    ImGui::Text("Box");

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