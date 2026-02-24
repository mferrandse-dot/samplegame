//
// Created by Mathi on 20/02/2026.
//

#ifndef SAMPLEGAME_VERTEXBUFFEROBJECTDATA_H
#define SAMPLEGAME_VERTEXBUFFEROBJECTDATA_H

#include <vulkan/vulkan.h>
#include <vector>

#include "hybrid/Location.h"

struct VertexBufferObjectData
{
  VkBuffer vertexBuffer;
  VkDeviceMemory vertexBufferMemory;
  VkBuffer indexBuffer;
  VkDeviceMemory indexBufferMemory;
  std::vector<uint32_t>* indices_storage;
  Location* location = nullptr; // used for position with a Location object can be null
};

#endif //SAMPLEGAME_VERTEXBUFFEROBJECTDATA_H