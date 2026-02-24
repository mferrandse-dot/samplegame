//
// Created by Mathieu on 22/02/2026.
//

#include "../../include/hybrid/TerrainGenerator.hpp"

#define intCast(x) static_cast<int>(x)

void TerrainGenerator::Update() {

  auto pos = localPlayer->GetLocation()->GetPosition();

  int index = (int)(pos.x / Chunk::ChunkSize) + (int)(pos.z / Chunk::ChunkSize) * WorldSize;
  if (chunkMap[index] == nullptr) {
    chunkMap[index] = new Chunk(glm::vec3((int)(pos.x / Chunk::ChunkSize), -1.f, (int)(pos.z / Chunk::ChunkSize)));
    chunkMap[index]->Enable();
  }
}

TerrainGenerator::TerrainGenerator() {
  localPlayer = ServiceLocator::GetService<LocalPlayer*>();
  chunkMap.fill(nullptr);
}
