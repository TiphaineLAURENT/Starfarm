//
// Created by tiphaine on 11/04/19.
//

#include "RendererComponent.hpp"

namespace game
{

  RendererComponent::RendererComponent(const sf::Texture &texture)
	  : Component()
  {
	  _sprite.setTexture(texture);
  }

  const sf::Sprite & RendererComponent::getSprite() const
  {
	  return _sprite;
  }

}
