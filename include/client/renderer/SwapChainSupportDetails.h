//
// Created by Mathi on 16/02/2026.
//

#ifndef SAMPLEGAME_SWAPCHAINSUPPORTDETAILS_H
#define SAMPLEGAME_SWAPCHAINSUPPORTDETAILS_H

#include <vector>
#include <vulkan/vulkan.h>

struct SwapChainSupportDetails
{
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};

#endif //SAMPLEGAME_SWAPCHAINSUPPORTDETAILS_H