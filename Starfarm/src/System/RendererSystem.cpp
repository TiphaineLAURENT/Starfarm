//
// Created by tiphaine on 11/04/19.
//

#include <iostream>
#include <ComponentManager.hpp>
#include "RendererSystem.hpp"
#include "../Component/RendererComponent.hpp"

namespace game
{

  RendererSystem::RendererSystem(sf::RenderWindow *const window)
          : _window(window)
  {}

  void RendererSystem::update()
  {
	  _window->clear();
          for (auto &component :
                  ecs::ComponentManager::getComponentContainer
                          <RendererComponent>()) {
                  _window->draw(dynamic_cast<RendererComponent*>(component.get())->getSprite());
          }
		  _window->display();
  }
}
