//
// Created by Mathi on 18/02/2026.
//

#ifndef SAMPLEGAME_PLAYER_H
#define SAMPLEGAME_PLAYER_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <hybrid/Location.h>

#include "Camera.h"

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
};


#endif //SAMPLEGAME_PLAYER_H