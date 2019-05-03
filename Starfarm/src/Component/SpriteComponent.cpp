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
          setPositions(0, 0);
  }
  SpriteComponent::SpriteComponent(const sf::Texture &texture)
          : Sprite(texture)
  {
          setOriginCenter();
          setPositions(0, 0);
  }
  SpriteComponent::SpriteComponent(
          const sf::Texture &texture,
          const sf::IntRect &rectangle
  )
          : Sprite(texture, rectangle)
  {
          setOriginCenter();
          setPositions(0, 0);
  }
  const sf::Vector2f &SpriteComponent::getOrigins() const
  {
          return Transformable::getOrigin();
  }
  void SpriteComponent::setOrigins(float x, float y)
  {
          Transformable::setOrigin(x, y);
  }
  const sf::Vector2f &SpriteComponent::getPositions() const
  {
          return Transformable::getPosition();
  }
  void SpriteComponent::setPositions(float x, float y)
  {
          Transformable::setPosition(x, y);
  }
  float SpriteComponent::getRotations() const
  {
          return Transformable::getRotation();
  }
  void SpriteComponent::setRotation(float angle)
  {
          Transformable::setRotation(angle);
  }
  const sf::Vector2f &SpriteComponent::getScales() const
  {
          return Transformable::getScale();
  }
  void SpriteComponent::setScales(float x, float y)
  {
          Transformable::setScale(x, y);
  }
  void SpriteComponent::setOriginCenter()
  {
          auto bounds = getLocalBounds();
          setOrigins(bounds.width / 2, bounds.height / 2);
  }

}
