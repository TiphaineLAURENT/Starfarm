/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** ComponentManager
*/

#include "ComponentManager.hpp"

namespace ecs
{

  ComponentManager &ComponentManager::getInstance()
  {
          static ComponentManager instance;
          return instance;
  }

}
