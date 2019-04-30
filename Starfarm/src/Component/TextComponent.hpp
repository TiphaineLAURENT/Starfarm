//
// Created by Tiphaine LAURENT on 30/04/2019.
//

#ifndef STARFARM_TEXTCOMPONENT_HPP
# define STARFARM_TEXTCOMPONENT_HPP

# include <SFML/Graphics/Text.hpp>
# include <SFML/Graphics/Font.hpp>
# include "BaseRendererComponent.hpp"


namespace game
{

  class TextComponent
          : public BaseRendererComponent, public sf::Text
  {
// ATTRIBUTES
  private:
  public:

// METHODS:
  public: // CONSTRUCTORS
          TextComponent();
          TextComponent(
                  const std::string &,
                  const sf::Font &,
                  unsigned int=30
          );
          ~TextComponent() override = default;
          TextComponent(const TextComponent &copy) = default;
          TextComponent(TextComponent &&other) = default;

  public: // OPERATORS
          TextComponent &operator=(const TextComponent &other) = default;
          TextComponent &operator=(TextComponent &&other) = default;

  public:
          const sf::Vector2f &getOrigin() const override;
          void setOrigin(float x, float y) override;
          void setOriginCenter() override;

          const sf::Vector2f &getPosition() const override;
          void setPosition(float x, float y) override;

          float getRotation() const override;
          void setRotation(float angle) override;

          const sf::Vector2f &getScale() const override;
          void setScale(float x, float y) override;
  };

  std::ostream &operator<<(std::ostream &out, const TextComponent &);

}

#endif //STARFARM_TEXTCOMPONENT_HPP
