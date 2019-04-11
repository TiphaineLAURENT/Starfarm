//
// Created by tiphaine on 07/04/19.
//

#include <ComponentManager.hpp>
#include <iostream>
#include "TransformSystem.hpp"
#include "../Component/TransformComponent.hpp"

namespace game
{

  void game::TransformSystem::update()
  {
          for (auto it = ecs::ComponentManager::begin<TransformComponent>();
               it != ecs::ComponentManager::end<TransformComponent>();
               ++it) {
                  auto component = dynamic_cast<TransformComponent*>(it->get());
                  component->update();
          }
  }

}
