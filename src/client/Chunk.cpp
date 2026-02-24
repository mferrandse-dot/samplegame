//
// Created by Mathieu on 22/02/2026.
//

#include "../../include/client/Chunk.hpp"

#include <client/Utils/PerlinNoise.hpp>

#include "glm/ext/quaternion_exponential.hpp"

glm::vec3 ComputeNormals(glm::vec3 a, glm::vec3 b, glm::vec3 c) {
  return glm::cross(b - a, c - a);
}

Chunk::Chunk(glm::vec3 pos) {
  // define vertices and loc here
  location.SetPosition(glm::vec3(pos.x * ChunkSize, pos.y * ChunkSize, pos.z * ChunkSize));

  int indice_count = 0;

  static const siv::PerlinNoise::seed_type seed = 123456u;
  static const siv::PerlinNoise perlin{ seed };

  // std::cout << "FIRST : " << perlin.octave2D_01(1, 1, 4) << ", SECOND : " << perlin.octave2D_01(1, 1, 4) << std::endl;

  for (int x = 0; x < ChunkSize; x++) {
    for (int y = 0; y < ChunkSize; y++) {

      float realx = (x + pos.x * ChunkSize);
      float realy = (y + pos.z * ChunkSize);

      float height1 = glm::pow((perlin.octave2D_01((realx + 1) / (ChunkSize), (realy + 0) / (ChunkSize), 4) + 1) * 10, 1.3);
      float height2 = glm::pow((perlin.octave2D_01((realx + 0) / (ChunkSize), (realy + 0) / (ChunkSize), 4) + 1) * 10, 1.3);
      float height3 = glm::pow((perlin.octave2D_01((realx + 0) / (ChunkSize), (realy + 1) / (ChunkSize), 4) + 1) * 10, 1.3);
      float height4 = glm::pow((perlin.octave2D_01((realx + 1) / (ChunkSize), (realy + 1) / (ChunkSize), 4) + 1) * 10, 1.3);

      glm::vec3 p1 = {1.f + x, height1, 0.f + y};
      glm::vec3 p2={0.f + x, height2, 0.f + y};
      glm::vec3 p3={0.f + x, height3, 1.f + y};
      glm::vec3 p4={1.f + x, height4, 1.f + y};

      glm::vec3 n1 = ComputeNormals(p1, p2, p3);
      glm::vec3 n2 = ComputeNormals(p1, p3, p4);
      glm::vec3 normal = glm::normalize(n1 + n2);

      // PLEASE NEVER COUT HERE MAKES VERY BIG LAG
      // std::cout << "normal x " << normal.x << "  y " << normal.y << "  z " << normal.z << "\n";

      vertices.push_back({p1, normal, {1.f, 0.f}});
      vertices.push_back({p2, normal, {0.f, 0.f}});
      vertices.push_back({p3, normal, {0.f, 1.f}});
      vertices.push_back({p4, normal, {1.f, 1.f}});

      indices.push_back(0 + indice_count);
      indices.push_back(1 + indice_count);
      indices.push_back(2 + indice_count);
      indices.push_back(2 + indice_count);
      indices.push_back(3 + indice_count);
      indices.push_back(0 + indice_count);

      indice_count += 4;
    }
  }

  _isLoaded = false;
}

void Chunk::Enable() {
  // generate mesh/ vbo
  this->GenerateMesh();
  _isLoaded = true;
}

void Chunk::Disable() {
  // destroy vbo
  this->CleanupMesh();
  _isLoaded = false;
}

bool Chunk::IsLoaded() {
  return _isLoaded;
}
