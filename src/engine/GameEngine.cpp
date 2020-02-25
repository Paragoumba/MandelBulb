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
    ParamsManager *paramsManager = new ParamsManager(game.getCamera());

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

            if(ImGui::Button("test")){
                paramsManager->setNearPlane(paramsManager->getNearPlane() + 0.1);
            }

            if (ImGui::Button("Hide menu"))
                paramsManager->setHideMenu(true);

            ImGui::End();

        }

        game.input(window);

        if (paramsManager->getRenderFractal()) {

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