//
// Created by Tiphaine LAURENT on 30/04/2019.
//

#ifndef STARFARM_BASERENDERERCOMPONENT_HPP
# define STARFARM_BASERENDERERCOMPONENT_HPP

# include <Component.hpp>
# include <SFML/Graphics.hpp>


namespace game
{

  class BaseRendererComponent
          : public ecs::Component<BaseRendererComponent>
  {
// ATTRIBUTES
  private:
          size_t _zindex = 0;

  public:

// METHODS:
  public: // CONSTRUCTORS
          BaseRendererComponent() = default;
          ~BaseRendererComponent() override = default;
          BaseRendererComponent(const BaseRendererComponent &copy) = default;
          BaseRendererComponent(BaseRendererComponent &&other) noexcept = default;

  public: // OPERATORS
          BaseRendererComponent &operator=(const BaseRendererComponent &other) = default;
          BaseRendererComponent &operator=(BaseRendererComponent &&other) = default;

  public:
          virtual const sf::Vector2f &getOrigins() const = 0;
          virtual void setOrigins(float x, float y) = 0;
          virtual void setOriginCenter() = 0;

          virtual const sf::Vector2f &getPositions() const = 0;
          virtual void setPositions(float x, float y) = 0;

          virtual float getRotations() const = 0;
          virtual void setRotation(float angle) = 0;

          virtual const sf::Vector2f &getScales() const = 0;
          virtual void setScales(float x, float y) = 0;
  };

  std::ostream &operator<<(std::ostream &out, const BaseRendererComponent &);

}

#endif //STARFARM_BASERENDERERCOMPONENT_HPP
