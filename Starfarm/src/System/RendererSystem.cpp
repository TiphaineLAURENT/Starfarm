//
// Created by tiphaine on 11/04/19.
//

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
  }

}
