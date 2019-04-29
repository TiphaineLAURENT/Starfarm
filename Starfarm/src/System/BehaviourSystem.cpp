//
// Created by tiphaine on 11/04/19.
//

#include "BehaviourSystem.hpp"
#include "../Component/MonoBehaviourComponent.hpp"
#include <ComponentManager.hpp>

namespace game
{
  BehaviourSystem::BehaviourSystem()
          : System()
  {
          for (auto &behaviour :
                  ecs::ComponentManager::getComponentContainer
                          <MonoBehaviourComponent>()) {
                  behaviour->awake();
          }
  }

  void BehaviourSystem::start()
  {
          for (auto &behaviour : ecs::ComponentManager::getComponentContainer<MonoBehaviourComponent>()) {
                  behaviour->start();
          }
  }

  void BehaviourSystem::update()
  {
          for (auto &behaviour : ecs::ComponentManager::getComponentContainer<MonoBehaviourComponent>()) {
                  behaviour->update();
          }
          for (auto &behaviour : ecs::ComponentManager::getComponentContainer<MonoBehaviourComponent>()) {
                  behaviour->lateUpdate();
          }
  }
}
