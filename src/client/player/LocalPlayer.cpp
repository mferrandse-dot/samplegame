//
// Created by Mathi on 18/02/2026.
//

#include <iostream>
#include <client/player/LocalPlayer.h>

#include "client/renderer/Renderer.h"
#include "../../../include/hybrid/ServiceLocator.h"

#define printvec3(xx) std::cout << " PLAYER LOC: x" << xx.x << " PLAYER LOC: y" << xx.y << " PLAYER LOC: z" << xx.z << "\n";

void mouse_callback(GLFWwindow* window);

LocalPlayer::LocalPlayer()
{
  camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

void LocalPlayer::UpdateLoop()
{

  while (!stopLoop)
  {
    Update();
  }
}

void LocalPlayer::Update()
{

  static float deltaTime = 0.0f;	// Time between current frame and last frame
  static float lastFrame = 0.0f;

  auto currentFrame = static_cast<float>(glfwGetTime());
  deltaTime = currentFrame - lastFrame;
  lastFrame = currentFrame;

  static GLFWwindow* window = ServiceLocator::GetService<Renderer*>()->GetWindow();

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    camera.ProcessKeyboard(FORWARD, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    camera.ProcessKeyboard(BACKWARD, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    camera.ProcessKeyboard(LEFT, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    camera.ProcessKeyboard(RIGHT, deltaTime);

  std::string pipelines[] = {"default", "spooky"};
  if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
  {
    ServiceLocator::GetService<Renderer*>()->ChangeGraphicsPipeline(pipelines[0]);
  }

  if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
  {
    ServiceLocator::GetService<Renderer*>()->ChangeGraphicsPipeline(pipelines[1]);
  }


  double xpos;
  double ypos;
  glfwGetCursorPos(window, &xpos, &ypos);

  static double lastX, lastY;

  static bool firstMouse = true;
  if (firstMouse)
  {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }

  double xoffset = xpos - lastX;
  double yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

  lastX = xpos;
  lastY = ypos;

  camera.ProcessMouseMovement((float)xoffset, (float)yoffset);

  location.position = camera.Position;
}