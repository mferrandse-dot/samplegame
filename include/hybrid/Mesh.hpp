//
// Created by Mathieu on 20/02/2026.
//

#ifndef SAMPLEGAME_MESH_HPP
#define SAMPLEGAME_MESH_HPP

#include <vulkan/vulkan.h>
#include <client/renderer/Vertex.h>
#include <hybrid/ServiceLocator.h>

#include "../client/renderer/Renderer.h"
#include "uuid/UUID-V4.hpp"
#include "hybrid/Location.h"


class Mesh {
  public:

    // create a vbo from vertices and incides
    // need vertices and indices
    inline UUIDv4::UUID GenerateMesh() {
//#ifdef CLIENT_SIDE
      //if (vertices.size() == 0 || indices.size() == 0)
      //  return 0;

      auto renderer = ServiceLocator::GetService<Renderer*>();

      //if (this->vboId.str().size() > 0)
      //  renderer->CleanVertexBufferObjectData(this->vboId);

      this->vboId = renderer->CreateVertexBufferObject(&(this->vertices), &(this->indices), &location);

      return vboId;
//#endif
//    return nullptr;
    }

  inline void CleanupMesh() {
      auto renderer = ServiceLocator::GetService<Renderer*>();
      renderer->CleanVertexBufferObjectData(vboId);
    }

  protected:

  std::vector<Vertex> vertices;
  std::vector<uint32_t> indices;
  Location location;
  UUIDv4::UUID vboId;

};

#endif //SAMPLEGAME_MESH_HPP