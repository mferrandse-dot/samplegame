//
// Created by Mathi on 18/02/2026.
//

#ifndef SAMPLEGAME_UNIFORMBUFFEROBJECT_H
#define SAMPLEGAME_UNIFORMBUFFEROBJECT_H

#include <vulkan/vulkan.h>
#include <glm/glm.hpp>

class UniformBufferObject {
public:
  glm::mat4 view;
  glm::mat4 proj;
};


#endif //SAMPLEGAME_UNIFORMBUFFEROBJECT_H