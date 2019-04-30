//
// Created by Tiphaine LAURENT on 30/04/2019.
//

#include "TextComponent.hpp"


namespace game
{

  TextComponent::TextComponent()
  {
          setOriginCenter();
          setPosition(0, 0);
  }
  TextComponent::TextComponent(
          const std::string &text,
          const sf::Font &font,
          unsigned int characterSize
  )
          : Text(text, font, characterSize)
  {
          setOriginCenter();
          setPosition(0, 0);
  }
  const sf::Vector2f &TextComponent::getOrigin() const
  {
          return Transformable::getOrigin();
  }
  void TextComponent::setOrigin(float x, float y)
  {
          Transformable::setOrigin(x, y);
  }
  const sf::Vector2f &TextComponent::getPosition() const
  {
          return Transformable::getPosition();
  }
  void TextComponent::setPosition(float x, float y)
  {
          Transformable::setPosition(x, y);
  }
  float TextComponent::getRotation() const
  {
          return Transformable::getRotation();
  }
  const sf::Vector2f &TextComponent::getScale() const
  {
          return Transformable::getScale();
  }
  void TextComponent::setScale(float x, float y)
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
          setOrigin(bounds.width / 2, bounds.height / 2);
  }

}
