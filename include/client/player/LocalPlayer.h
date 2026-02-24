//
// Created by Mathi on 18/02/2026.
//

#ifndef SAMPLEGAME_PLAYER_H
#define SAMPLEGAME_PLAYER_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <hybrid/Location.h>

#include "Camera.h"
#include "client/renderer/Vertex.h"

/*
 * Class that receive a scene object then handle movement and interactions
 * Mainly record inputs
 */

class LocalPlayer
{
  public:

    LocalPlayer();
    inline Location* GetLocation() {return &location;}
    inline Camera* GetCamera() {return &camera;}

    void UpdateLoop();
    void Update();

    void Stop() {stopLoop = true;}

  private:

    Camera camera;
    Location location;
    bool stopLoop = false;

  std::vector<Vertex>vertices = {
      {{-1.f, -2.5f, -1.f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.f}},
      {{1.f, -2.5f, -1.f}, {1.0f, 0.0f, 0.0f}, {.0f, 0.f}},
      {{1.f, -0.5f, -1.f}, {0.0f, 0.0f, 1.0f}, {.0f, 1.f}},
      {{-1.f, -0.5f, -1.f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.f}},
  };
  std::vector<uint32_t>indices = {
      0, 1, 2, 2, 3, 0
  };
};


#endif //SAMPLEGAME_PLAYER_H