//
// Created by Mathieu on 21/02/2026.
//

#ifndef SAMPLEGAME_SCENE_HPP
#define SAMPLEGAME_SCENE_HPP
#include "SceneObject.hpp"

class Scene: public SceneObject {
  public:

  inline void UpdateLoop() {
    while (!this->stopLoop) {
        this->Update();
    }
  }

  inline void SetStop() {
    stopLoop = true;
  }

  private:

  inline void Update() {
    this->UpdateChildrens();
  }
    bool stopLoop = false;
};

#endif //SAMPLEGAME_SCENE_HPP