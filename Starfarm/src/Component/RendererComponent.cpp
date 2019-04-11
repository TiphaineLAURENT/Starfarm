//
// Created by tiphaine on 11/04/19.
//

#include "RendererComponent.hpp"

namespace game
{

  RendererComponent::RendererComponent()
  {
	  _texture.loadFromFile("texture/darkgrey_05.png");
	  _sprite.setTexture(_texture);
  }

  const sf::Sprite & RendererComponent::getSprite() const
  {
	  return _sprite;
  }

}
