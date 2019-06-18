//
// Created by tiphaine on 11/04/19.
//

#ifndef STARFARM_RENDERERSYSTEM_HPP
# define STARFARM_RENDERERSYSTEM_HPP

# include <ostream>
# include <System.hpp>
# include <SFML/Graphics/RenderWindow.hpp>

namespace game
{

  class RendererSystem : public ecs::System<RendererSystem>
  {
// ATTRIBUTES
  private:
          sf::RenderWindow *const _window = nullptr;

  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit RendererSystem(sf::RenderWindow *);
          ~RendererSystem() override = default;
          RendererSystem(const RendererSystem &copy) = delete;
          RendererSystem(RendererSystem &&other) noexcept = delete;

  public: // OPERATORS
          RendererSystem &operator=(const RendererSystem &other) = delete;
          RendererSystem &operator=(RendererSystem &&other) = delete;

  public:
          void preUpdate() override;
          void update() override;
          void postUpdate() override;
  };

  std::ostream &operator<<(std::ostream &out, const RendererSystem &);

}

#endif //STARFARM_RENDERERSYSTEM_HPP
