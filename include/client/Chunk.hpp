//
// Created by Mathieu on 22/02/2026.
//

#ifndef SAMPLEGAME_TERRAIN_HPP
#define SAMPLEGAME_TERRAIN_HPP
#include "hybrid/Mesh.hpp"
#include "hybrid/SceneObject.hpp"


class Chunk: public SceneObject, public Mesh {
  public:

  Chunk(glm::vec3 pos);

  void Enable();
  void Disable();
  bool IsLoaded();

  static constexpr int ChunkSize = 32;
private:

  bool _isLoaded;
};


#endif //SAMPLEGAME_TERRAIN_HPP