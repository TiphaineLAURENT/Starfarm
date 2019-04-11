//
// Created by tiphaine on 11/04/19.
//

#ifndef STARFARM_RENDERERCOMPONENT_HPP
# define STARFARM_RENDERERCOMPONENT_HPP

# include <ostream>
#include <Component.hpp>
#include <SFML/Graphics.hpp>

namespace game
{

  class RendererComponent : public ecs::Component<RendererComponent>
  {
// ATTRIBUTES
  private:
          sf::Sprite _sprite;
          sf::Color _color = sf::Color::White;
		  std::pair<bool, bool> _flip = { false, false };
          size_t _order = 0;

  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit RendererComponent(const sf::Texture&);
          ~RendererComponent() override = default;
          RendererComponent(const RendererComponent &copy) = default;
          RendererComponent(RendererComponent &&other) noexcept = default;

  public: // OPERATORS
          RendererComponent &operator=(const RendererComponent &other) = default;
          RendererComponent &operator=(RendererComponent &&other) = default;

  public:
		  const sf::Sprite &getSprite() const;
  };

  std::ostream &operator<<(std::ostream &out, const RendererComponent &);

}

#endif //STARFARM_RENDERERCOMPONENT_HPP
