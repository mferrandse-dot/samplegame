//
// Created by Mathieu on 22/02/2026.
//

#ifndef SAMPLEGAME_TERRAINGENERATOR_HPP
#define SAMPLEGAME_TERRAINGENERATOR_HPP
#include "SceneObject.hpp"
#include "client/Chunk.hpp"
#include "client/player/LocalPlayer.h"

/*
 * GENERATE TERRAIN TILES AROUND THE PLAYER
 */

/*
 *Divides the world into cubes of 32 by 32 by 32
 *checks the player position
 *generate  chunks
 *then generate mesh
 *unloads mesh if 3 chunks
 *reloads mesh but not regenerates
 */

class TerrainGenerator: public SceneObject {
  public:
  void Update();
  TerrainGenerator();

  static constexpr int WorldSize = 5; // world area = 25 and world vol = 125 so 125 in the unorderedmap
  static constexpr int WorldArea = WorldSize * WorldSize;
  static constexpr int WorldVol = WorldArea * WorldSize;

  private:

  LocalPlayer* localPlayer;
  std::array<Chunk*, WorldArea> chunkMap;

};


#endif //SAMPLEGAME_TERRAINGENERATOR_HPP