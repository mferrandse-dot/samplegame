//
// Created by Mathieu on 20/02/2026.
//

#ifndef SAMPLEGAME_SCENEOBJECT_HPP
#define SAMPLEGAME_SCENEOBJECT_HPP
#include <unordered_map>
#include <vector>

#include "uuid/UUID-V4.hpp"

class SceneObject {

  public:
  SceneObject() {}
  virtual ~SceneObject() = default;

  virtual void Update() {}
  void UpdateChildrens() const;
  void CleanChildrens() const;

  inline SceneObject* GetChild(const UUIDv4::UUID t) const {return childrens.at(t);}
  inline SceneObject* GetParent() const {return parent;}
  inline void AddChild(SceneObject* obj) {childrens.emplace(obj->GetUUID(), obj);}

  inline UUIDv4::UUID GetUUID() const {return id;}

  private:

  SceneObject* parent = nullptr;
  std::unordered_map<UUIDv4::UUID, SceneObject*> childrens;
  UUIDv4::UUID id;
};

#endif //SAMPLEGAME_SCENEOBJECT_HPP
