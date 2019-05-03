//
// Created by Tiphaine LAURENT on 30/04/2019.
//

#include "TextComponent.hpp"


namespace game
{

  TextComponent::TextComponent()
  {
          setOriginCenter();
          setPositions(0, 0);
  }
  TextComponent::TextComponent(
          const std::string &text,
          const sf::Font &font,
          unsigned int characterSize
  )
          : Text(text, font, characterSize)
  {
          setOriginCenter();
          setPositions(0, 0);
  }
  const sf::Vector2f &TextComponent::getOrigins() const
  {
          return Transformable::getOrigin();
  }
  void TextComponent::setOrigins(float x, float y)
  {
          Transformable::setOrigin(x, y);
  }
  const sf::Vector2f &TextComponent::getPositions() const
  {
          return Transformable::getPosition();
  }
  void TextComponent::setPositions(float x, float y)
  {
          Transformable::setPosition(x, y);
  }
  float TextComponent::getRotations() const
  {
          return Transformable::getRotation();
  }
  const sf::Vector2f &TextComponent::getScales() const
  {
          return Transformable::getScale();
  }
  void TextComponent::setScales(float x, float y)
  {
          Transformable::setScale(x, y);
  }
  void TextComponent::setRotation(float angle)
  {
          Transformable::setRotation(angle);
  }
  void TextComponent::setOriginCenter()
  {
          auto bounds = getLocalBounds();
          setOrigins(bounds.width / 2, bounds.height / 2);
  }

}
