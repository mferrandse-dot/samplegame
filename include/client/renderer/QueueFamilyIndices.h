//
// Created by Mathi on 16/02/2026.
//

#ifndef SAMPLEGAME_QUEUEFAMILYINDICES_H
#define SAMPLEGAME_QUEUEFAMILYINDICES_H

#include <cstdint>
#include <optional>

struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;
  std::optional<uint32_t> presentFamily;

  bool IsComplete()
  {
    return graphicsFamily.has_value() && presentFamily.has_value();
  }
};

#endif //SAMPLEGAME_QUEUEFAMILYINDICES_H