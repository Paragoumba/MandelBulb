#include "Renderer.hpp"
#include "Transformation.hpp"
#include "Mesh.hpp"

Renderer::Renderer() :
sceneShader("../res/shaders/scene_shader.vs", "../res/shaders/scene_shader.fs"),
hudShader("../res/shaders/hud_shader.vs", "../res/shaders/hud_shader.vs"){}

void Renderer::renderScene(Scene& scene, Camera &camera){

    sceneShader.use();

    sceneShader.setMat4f("view", Transformation::getViewMatrix(camera));
    sceneShader.setMat4f("projection", Transformation::getProjectionMatrix());

    float vertices[] = {
            0.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f,
            0.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f
    };

    float texCoords[] = {
            0.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f
    };

    unsigned int indices[] = {
            0, 1, 2,
            1, 3, 2
    };

    Mesh mesh(vertices, sizeof(vertices), texCoords, sizeof(texCoords), indices, sizeof(indices));

    mesh.render();

}

void Renderer::renderHUD(HUD& hud){

    hudShader.use();

    sceneShader.setMat4f("projection", Transformation::getProjectionMatrix());

}