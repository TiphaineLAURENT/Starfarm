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
          auto bounds = _sprite.getGlobalBounds();
          _size = std::pair<float, float>(bounds.width, bounds.height);
          _sprite.setOrigin(_size.first / 2, _size.second / 2);
          _sprite.setPosition(0, 0);
  }

  const sf::Sprite &RendererComponent::getSprite() const
  {
          return _sprite;
  }

}
