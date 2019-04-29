//
// Created by tiphaine on 07/04/19.
//

#include <iostream>
#include "TransformSystem.hpp"
#include "ComponentManager.hpp"
#include "../Component/TransformComponent.hpp"

namespace game
{

  void TransformSystem::update()
  {
          for (auto &component : ecs::ComponentManager::getComponentContainer<TransformComponent>()) {
                  component->update();
          }
  }

}
