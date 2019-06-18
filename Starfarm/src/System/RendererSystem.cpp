//
// Created by tiphaine on 11/04/19.
//

#include <iostream>
#include <ComponentManager.hpp>
#include "RendererSystem.hpp"
#include "../Component/SpriteComponent.hpp"
#include "../Component/TextComponent.hpp"


namespace game
{

  RendererSystem::RendererSystem(sf::RenderWindow *const window)
          : System(), _window(window)
  {
  }

  void RendererSystem::preUpdate()
  {
          _window->display();
  }

  void RendererSystem::update()
  {
          _window->clear();
  }

  void RendererSystem::postUpdate()
  {
          for (auto &component :
                  ecs::ComponentManager::getComponentContainer<SpriteComponent>
                          ()) {
                  _window->draw(*component);
          }
          for (auto &component :
                  ecs::ComponentManager::getComponentContainer<TextComponent>
                          ()) {
                  _window->draw(*component);
          }
  }
}
