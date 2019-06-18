//
// Project Starfarm
// Created by Tiphaine LAURENT on 18/06/2019.
//

#ifndef STARFARM_EVENTMANAGER_HPP
# define STARFARM_EVENTMANAGER_HPP

# include <ostream>
# include <map>
# include "Event.hpp"


namespace game
{

  class EventManager
  {
// ATTRIBUTES
  private:
          std::map<std::string, Event> _events;

  public:

// METHODS:
  public: // CONSTRUCTORS
          EventManager() = default;
          ~EventManager() = default;
          EventManager(const EventManager &copy) = delete;
          EventManager(EventManager &&other) noexcept = delete;

  public: // OPERATORS
          EventManager &operator=(const EventManager &other) = delete;
          EventManager &operator=(EventManager &&other) = delete;

  public:
          static EventManager &getInstance();
          Event &createEvent(const std::string &eventName);
          Event &getEvent(const std::string &eventName);
          template <class T>
          void subscribe(
                  const std::string &eventName, T *obj,
                  Handler<T> handler
          );
          void publish(const std::string &eventName);
          void clearEvents();
          void clearListeners(const std::string &eventName);
  };

  std::ostream &operator<<(std::ostream &out, const EventManager &);

}

#endif //STARFARM_EVENTMANAGER_HPP
