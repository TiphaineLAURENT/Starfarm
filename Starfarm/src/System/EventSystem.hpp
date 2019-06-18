//
// Project Starfarm
// Created by Tiphaine LAURENT on 18/06/2019.
//

#ifndef STARFARM_EVENTSYSTEM_HPP
# define STARFARM_EVENTSYSTEM_HPP

# include <ostream>
# include <System.hpp>
# include <SFML/Graphics/RenderWindow.hpp>


namespace game
{

  class EventSystem
          : public ecs::System<EventSystem>
  {
// ATTRIBUTES
  private:
  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit EventSystem(sf::RenderWindow *);
          ~EventSystem() override = default;
          EventSystem(const EventSystem &copy) = delete;
          EventSystem(EventSystem &&other) noexcept = delete;

  public: // OPERATORS
          EventSystem &operator=(const EventSystem &other) = delete;
          EventSystem &operator=(EventSystem &&other) = delete;

  public:
          void preUpdate() override;
          void update() override;
          void postUpdate() override;
  };

  std::ostream &operator<<(std::ostream &out, const EventSystem &);

}

#endif //STARFARM_EVENTSYSTEM_HPP
