#define CLIENT_SIDE

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include <memory>

#include "client/renderer/Renderer.h"
#include <thread>

#include "client/player/LocalPlayer.h"
#include "../../include/hybrid/ServiceLocator.h"
#include "client/Chunk.hpp"
#include "hybrid/Mesh.hpp"
#include "hybrid/Scene.hpp"
#include "hybrid/TerrainGenerator.hpp"

int main() {

// YOU WERE THERE https://vulkan-tutorial.com/Drawing_a_triangle/Graphics_pipeline_basics/Shader_modules

    auto player = new LocalPlayer();
    ServiceLocator::Register<LocalPlayer*>(player);

    auto scene = new Scene();
    ServiceLocator::Register<Scene*>(scene);

    auto terrainGenerator = new TerrainGenerator();
    scene->AddChild(terrainGenerator);

    // std::vector<Vertex>vertices = {
    //     {{-1.f, -2.5f, -1.f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.f}},
    //     {{1.f, -2.5f, -1.f}, {1.0f, 0.0f, 0.0f}, {.0f, 0.f}},
    //     {{1.f, -0.5f, -1.f}, {0.0f, 0.0f, 1.0f}, {.0f, 1.f}},
    //     {{-1.f, -0.5f, -1.f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.f}},
    // };
    // std::vector<uint32_t>indices = {
    //     0, 1, 2, 2, 3, 0
    // };
    try
    {
        auto ren = new Renderer();
        ServiceLocator::Register<Renderer*>(ren);



    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    // auto testchunk = new Chunk(glm::vec3(0.f, -1.f, 0.f));
    // testchunk->Enable();
    //
    // auto testchunk2 = new Chunk(glm::vec3(0.f, -1.f, 1.f));
    // testchunk2->Enable();

    //auto terrain = new TerrainGenerator();
    //ServiceLocator::Register<TerrainGenerator*>(terrain);

    std::thread playerThread([player]() {player->UpdateLoop();});
    std::thread sceneThread([scene]() {scene->UpdateLoop();});

    try
    {
        ServiceLocator::GetService<Renderer*>()->DrawLoop();
    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    scene->SetStop();
    sceneThread.join();

    scene->CleanChildrens();

    player->Stop();
    playerThread.join();

    delete ServiceLocator::GetService<Renderer*>();
    delete ServiceLocator::GetService<LocalPlayer*>();
    delete ServiceLocator::GetService<TerrainGenerator*>();

    return 0;
}
