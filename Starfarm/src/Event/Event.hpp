//
// Project Starfarm
// Created by Tiphaine LAURENT on 18/06/2019.
//

#ifndef STARFARM_EVENT_HPP
# define STARFARM_EVENT_HPP

# include <ostream>
# include <list>
# include <algorithm>
# include <memory>
# include "EventHandler.hpp"


namespace game
{

  class Event
  {
// ATTRIBUTES
  private:
          std::list<std::unique_ptr<IEventHandler>> _listeners;

  public:

// METHODS:
  public: // CONSTRUCTORS
          Event() = default;
          ~Event() = default;
          Event(const Event &copy) = default;
          Event(Event &&other) = default;

  public: // OPERATORS
          Event &operator=(const Event &other) = default;
          Event &operator=(Event &&other) noexcept = default;

  public:
          template <class T>
          HandlerID addListener(Handler<T> &handler, T *const obj)
          {
                  auto eventHandler = std::make_unique<EventHandler<T>>
                          (handler, obj);
                  auto id = eventHandler->getId();
                  _listeners.push_back(eventHandler);
                  return id;
          }
          void removeById(HandlerID handlerId)
          {
                  auto handler = std::find_if(
                          _listeners.begin(), _listeners.end(),
                          [handlerId](auto &handler) {
                                  return handlerId == handler->getId();
                          }
                  );
                  if (handler != _listeners.end()) {
                          _listeners.erase(handler);
                  }
          }
          void clearListeners();

          void execute() const
          {
                  for (
                          auto &handler : _listeners
                          ) {
                          handler->execute();
                  }
          }
  };

  std::ostream &operator<<(std::ostream &out, const Event &);

}

#endif //STARFARM_EVENT_HPP
