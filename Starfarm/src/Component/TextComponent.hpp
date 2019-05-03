//
// Created by Tiphaine LAURENT on 30/04/2019.
//

#ifndef STARFARM_TEXTCOMPONENT_HPP
# define STARFARM_TEXTCOMPONENT_HPP

# include <SFML/Graphics/Text.hpp>
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
          const sf::Vector2f &getOrigins() const override;
          void setOrigins(float x, float y) override;
          void setOriginCenter() override;

          const sf::Vector2f &getPositions() const override;
          void setPositions(float x, float y) override;

          float getRotations() const override;
          void setRotation(float angle) override;

          const sf::Vector2f &getScales() const override;
          void setScales(float x, float y) override;
  };

  std::ostream &operator<<(std::ostream &out, const TextComponent &);

}

#endif //STARFARM_TEXTCOMPONENT_HPP
