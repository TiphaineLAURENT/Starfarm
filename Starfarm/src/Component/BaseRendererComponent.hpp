//
// Created by Tiphaine LAURENT on 30/04/2019.
//

#ifndef STARFARM_BASERENDERERCOMPONENT_HPP
# define STARFARM_BASERENDERERCOMPONENT_HPP

# include <ostream>
# include <Component.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Drawable.hpp>


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
          virtual const sf::Vector2f &getOrigin() const = 0;
          virtual void setOrigin(float x, float y) = 0;
          virtual void setOriginCenter() = 0;

          virtual const sf::Vector2f &getPosition() const = 0;
          virtual void setPosition(float x, float y) = 0;

          virtual float getRotation() const = 0;
          virtual void setRotation(float angle) = 0;

          virtual const sf::Vector2f &getScale() const = 0;
          virtual void setScale(float x, float y) = 0;
  };

  std::ostream &operator<<(std::ostream &out, const BaseRendererComponent &);

}

#endif //STARFARM_BASERENDERERCOMPONENT_HPP
