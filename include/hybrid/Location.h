//
// Created by Mathi on 18/02/2026.
//

#ifndef SAMPLEGAME_LOCATION_H
#define SAMPLEGAME_LOCATION_H

#include <glm/glm.hpp>

#include "glm/ext/matrix_transform.hpp"

class Location
{
public:

  inline void SetPosition(glm::vec3 _position) {position = _position;}
  inline glm::vec3 GetPosition() {return position;}

  inline glm::mat4 GetModelMatrix() {
    return glm::translate(glm::mat4(1.f), position);
  }

private:

  glm::vec3 position = glm::vec3(1.0f);
  glm::mat4 modelMatrix = glm::mat4(1.0f);
};

#endif //SAMPLEGAME_LOCATION_H