#include "Renderer.hpp"
#include "Transformation.hpp"
#include "Mesh.hpp"

Renderer::Renderer() :
sceneShader("../res/shaders/scene_shader.vs", "../res/shaders/scene_shader.fs"),
hudShader("../res/shaders/hud_shader.vs", "../res/shaders/hud_shader.fs"){}

void Renderer::renderScene(Scene& scene, Camera& camera){

    sceneShader.use();

    sceneShader.setMat4f("view", Transformation::getViewMatrix(camera));
    sceneShader.setMat4f("projection", Transformation::getProjectionMatrix());

    std::vector<MeshPtr> meshes = scene.getMeshes();

    for (auto& mesh : meshes){

        sceneShader.setMat4f("model", Transformation::getModelMatrix(mesh.get()));

        mesh->render();

    }
}

void Renderer::renderHUD(HUD& hud){

    hudShader.use();

    //sceneShader.setMat4f("projection", Transformation::getProjectionMatrix());

}