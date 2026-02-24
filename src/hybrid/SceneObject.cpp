//
// Created by Mathieu on 21/02/2026.
//

#include <hybrid/SceneObject.hpp>

void SceneObject::UpdateChildrens() const {
  for (auto &it: this->childrens) {
    it.second->Update();
    it.second->UpdateChildrens();
  }
}

void SceneObject::CleanChildrens() const {
  for (auto &it: this->childrens) {
    it.second->CleanChildrens();
    delete this;
  }
}
