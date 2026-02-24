//
// Created by Mathi on 18/02/2026.
//

#ifndef SAMPLEGAME_VERTEX_H
#define SAMPLEGAME_VERTEX_H

#include <vulkan/vulkan.h>
#include <glm/glm.hpp>
#include <array>

class Vertex
{
public:
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 texCoord;

  static VkVertexInputBindingDescription GetBindingDescription();
  static std::array<VkVertexInputAttributeDescription, 3> GetAttributeDescriptions();
};



#endif //SAMPLEGAME_VERTEX_H
