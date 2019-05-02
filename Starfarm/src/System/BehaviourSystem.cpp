//
// Created by tiphaine on 11/04/19.
//

#include <ComponentManager.hpp>
#include "BehaviourSystem.hpp"
#include "../Component/MonoBehaviourComponent.hpp"

namespace game
{
  BehaviourSystem::BehaviourSystem()
          : System(), _container(
          ecs::ComponentManager::getComponentContainer
                  <MonoBehaviourComponent>()
  )
  {
          for (
                  auto &behaviour : _container
                  ) {
                  behaviour->awake();
          }
  }

  void BehaviourSystem::start()
  {
          for (
                  auto &behaviour : _container
                  ) {
                  behaviour->start();
          }
  }

  void BehaviourSystem::update()
  {
          auto &components = _container.getComponents();
          for (
                  size_t i = 0; i < components.size(); ++i
                  ) {
                  components[i]->update();
          }
          for (
                  size_t i = 0; i < components.size(); ++i
                  ) {
                  components[i]->lateUpdate();
          }
  }
}
