//
// Project Starfarm
// Created by Tiphaine LAURENT on 30/04/2019.
//

#include "SpriteComponent.hpp"


namespace game
{

  SpriteComponent::SpriteComponent()
  {
          setOriginCenter();
          setPosition(0, 0);
  }
  SpriteComponent::SpriteComponent(const sf::Texture &texture)
          : Sprite(texture)
  {
          setOriginCenter();
          setPosition(0, 0);
  }
  SpriteComponent::SpriteComponent(
          const sf::Texture &texture,
          const sf::IntRect &rectangle
  )
          : Sprite(texture, rectangle)
  {
          setOriginCenter();
          setPosition(0, 0);
  }
  const sf::Vector2f &SpriteComponent::getOrigin() const
  {
          return Transformable::getOrigin();
  }
  void SpriteComponent::setOrigin(float x, float y)
  {
          Transformable::setOrigin(x, y);
  }
  const sf::Vector2f &SpriteComponent::getPosition() const
  {
          return Transformable::getPosition();
  }
  void SpriteComponent::setPosition(float x, float y)
  {
          Transformable::setPosition(x, y);
  }
  float SpriteComponent::getRotation() const
  {
          return Transformable::getRotation();
  }
  void SpriteComponent::setRotation(float angle)
  {
          Transformable::setRotation(angle);
  }
  const sf::Vector2f &SpriteComponent::getScale() const
  {
          return Transformable::getScale();
  }
  void SpriteComponent::setScale(float x, float y)
  {
          Transformable::setScale(x, y);
  }
  void SpriteComponent::setOriginCenter()
  {
          auto bounds = getLocalBounds();
          setOrigin(bounds.width / 2, bounds.height / 2);
  }

}
