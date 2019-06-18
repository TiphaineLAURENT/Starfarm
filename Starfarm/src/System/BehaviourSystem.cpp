//
// Created by tiphaine on 11/04/19.
//

#include <ComponentManager.hpp>
#include "BehaviourSystem.hpp"
#include "../Component/MonoBehaviourComponent.hpp"

namespace game
{
  BehaviourSystem::BehaviourSystem()
          : System(), _behaviours(
          ecs::ComponentManager::getComponentContainer
                  <MonoBehaviourComponent>()
  )
  {
          for (
                  auto &behaviour : _behaviours
                  ) {
                  behaviour->awake();
          }
  }

  void BehaviourSystem::start()
  {
          for (
                  auto &behaviour : _behaviours
                  ) {
                  behaviour->start();
          }
  }

  void BehaviourSystem::update()
  {
          auto &components = _behaviours.getComponents();
          for (
                  auto &component : components
                  ) {
                  component->update();
          }
          for (
                  auto &component : components
                  ) {
                  component->lateUpdate();
          }
  }
}
