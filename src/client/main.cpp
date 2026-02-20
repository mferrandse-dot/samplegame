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

int main() {
// YOU WERE THERE https://vulkan-tutorial.com/Drawing_a_triangle/Graphics_pipeline_basics/Shader_modules

    auto player = new LocalPlayer();
    ServiceLocator::Register<LocalPlayer*>(player);

    try
    {
        ServiceLocator::Register<Renderer*>(new Renderer());
    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    std::thread playerThread([player]() {player->UpdateLoop();});

    try
    {
        ServiceLocator::GetService<Renderer*>()->DrawLoop();
    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    delete ServiceLocator::GetService<Renderer*>();

    player->Stop();
    playerThread.join();

    return 0;
}
