//
// Created by Mathi on 16/02/2026.
//

#ifndef SAMPLEGAME_RENDERER_H
#define SAMPLEGAME_RENDERER_H

#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <string>
#include <vector>
#include <GLFW/glfw3native.h>

#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"

#include "../Utils/Constants.h"
#include "client/renderer/Vertex.h"

#include <thread>

#include "VertexBufferObjectData.h"

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

// GOAL
// MAKE THE DRAW LOOP INTO A DIFFERENT THREAD
// MAKE AN ATOMIC SCENE VARIABLE THAT IS DRAWN

class Renderer
{
public:
    Renderer();
    void DrawLoop();

    inline ~Renderer() {this->Cleanup();}

    void SetFramebufferResized(const bool val);

    inline GLFWwindow* GetWindow() {return this->window;}

    inline void ChangeGraphicsPipeline(std::string newpi)
    {
        if (graphicsPipelines.find(newpi) != graphicsPipelines.end())
            currentGraphicsPipeline = newpi;
    };

private:
    void Cleanup();
    void Init();
    void InitVulkan();

    void PickPhysicalDevice();
    void CreateLogicalDevice();

    void CreateSurface();

    void CreateSwapChain();
    void CreateImageViews();

    void CreateRenderPass();

    void CreateDescriptorSetLayout();
    void CreateDescriptorPool();
    void CreateDescriptorSets();

    void CreateGraphicsPipeline(std::string shadername);

    void CreateFramebuffers();

    void CreateCommandPool();

    uint32_t CreateVertexBufferObject(std::vector<Vertex>* vbo, std::vector<uint32_t>* ebo);
    void CreateVertexBuffer(std::vector<Vertex>* vbo, uint32_t id);
    void CreateIndexBuffer(std::vector<uint32_t>* ebo,uint32_t id);

    void CreateUniformBuffers();
    void CreateCommandBuffers();

    void CreateSyncObjects();

    void CreateDepthResources();
    void CreateTextureImage();
    void CreateTextureImageView();

    void Draw();

    int RateDeviceSuitability(VkPhysicalDevice _device);
    bool CheckDeviceSuitability(VkPhysicalDevice _device);

    QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice _device);

    SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice _device);

    VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    template <typename T> VkShaderModule CreateShaderModule(const std::vector<T>& code);

    void RecordCommandBuffer(VkCommandBuffer _commandBuffer, uint32_t imageIndex);

    bool CheckValidationLayerSupport();

    void CleanupSwapChain();
    void RecreateSwapChain();

    uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

    void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
    void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

    void UpdateUniformBuffer(uint32_t currentImage);

    VkFormat FindSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
    VkFormat FindDepthFormat();
    bool HasStencilComponent(VkFormat format);

    void CreateImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling,
        VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);

    VkCommandBuffer BeginSingleTimeCommands();
    void EndSingleTimeCommands(VkCommandBuffer commandBuffer);

    void TransitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout) ;

    void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);

    VkImageView CreateImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags);

    void CreateTextureSampler();

    GLFWwindow* window{};

    VkInstance instance{};

    VkPhysicalDevice physicalDevice{};
    VkDevice device{};
    const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
      };

    VkQueue graphicsQueue{};
    VkQueue presentQueue;

    VkSurfaceKHR surface;

    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;

    std::vector<VkImageView> swapChainImageViews;

    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    std::unordered_map<std::string, VkPipelineLayout> pipelineLayouts;
    std::unordered_map<std::string, VkPipeline> graphicsPipelines;
    std::string currentGraphicsPipeline;

    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> commandBuffers;

    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;

    bool framebufferResized = false;

    uint32_t currentFrame = 0;

    std::unordered_map<uint32_t, VertexBufferObjectData> vertexBufferObjects;

    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;

    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;

    // TODO ADD VECTOR SO MULTIPLE IMAGES
    VkImage textureImage;
    VkDeviceMemory textureImageMemory;
    VkImageView textureImageView;
    VkSampler textureSampler;

    VkImage depthImage;
    VkDeviceMemory depthImageMemory;
    VkImageView depthImageView;

public:

    std::vector<Vertex> vertices = {
        {{-0.5f, -0.5f, 1.f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.f}},
        {{0.5f, -0.5f, 1.f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.f}},
        {{0.5f, 0.5f, 1.f}, {0.0f, 0.0f, 1.0f}, {.0f, 1.f}},
        {{-0.5f, 0.5f, 1.f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.f}},
    };
    std::vector<uint32_t> indices = {
        0, 1, 2, 2, 3, 0
    };

    std::vector<Vertex> vertices2 = {
        {{-1.f, -2.5f, -1.f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.f}},
        {{1.f, -2.5f, -1.f}, {1.0f, 0.0f, 0.0f}, {.0f, 0.f}},
        {{1.f, -0.5f, -1.f}, {0.0f, 0.0f, 1.0f}, {.0f, 1.f}},
        {{-1.f, -0.5f, -1.f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.f}},
    };
    std::vector<uint32_t> indices2 = {
        0, 1, 2, 2, 3, 0
    };
};


#endif //SAMPLEGAME_RENDERER_H