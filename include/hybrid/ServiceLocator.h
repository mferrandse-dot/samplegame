//
// Created by Mathi on 18/02/2026.
//

#ifndef SAMPLEGAME_SERVICELOCATOR_H
#define SAMPLEGAME_SERVICELOCATOR_H

#include <memory>
#include <unordered_map>
#include <typeindex>
#include <cassert>
#include <iostream>
#include <ostream>
#include <string>

class ServiceLocator {
public:
  template<typename T>
  static void Register(T service) {
    instance[std::type_index(typeid(T))] = service;
  }

  template<typename T>
  static T GetService() {
    auto it = instance.find(std::type_index(typeid(T)));

    std::string s = "Service not registered :";
    s.append(typeid(T).name());
    if (it == instance.end()) {
      std::cout << s.c_str() << std::endl;
    }
    assert(it != instance.end() && "Service not registered");
    return reinterpret_cast<T>(it->second);
  }

private:
  static std::unordered_map<std::type_index, void*> instance;
};

#endif //SAMPLEGAME_SERVICELOCATOR_H