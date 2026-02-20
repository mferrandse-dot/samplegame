cmake_minimum_required(VERSION 3.11)
project(samplegame)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.3
)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(
        glslang
        GIT_REPOSITORY https://github.com/KhronosGroup/glslang.git
        GIT_TAG main
)
FetchContent_MakeAvailable(glslang)

add_executable(samplegame
        src/client/main.cpp
        src/client/renderer/RendererInit.cpp
        src/client/renderer/RendererDraw.cpp
        src/client/renderer/SpirvHelper.cpp
        src/client/renderer/Vertex.cpp
        src/client/renderer/UniformBufferObject.cpp
        src/client/player/LocalPlayer.cpp
        src/hybrid/ServiceLocator.cpp
        src/client/player/Camera.cpp
        src/client/Utils/stb_image_impl.cpp
)

file(GLOB VULKAN_LIB "$ENV{VULKAN_SDK}/Lib/*.lib")

target_link_libraries(samplegame
        PRIVATE glfw
        #PRIVATE ${VULKAN_LIB}
        PRIVATE $ENV{VULKAN_SDK}/Lib/vulkan-1.lib
        PRIVATE glslang
        PRIVATE glm
)

target_include_directories(samplegame
        PRIVATE include
        PRIVATE $ENV{VULKAN_SDK}/Include
)
