//
// Project Starfarm
// Created by Tiphaine LAURENT on 18/06/2019.
//

#ifndef STARFARM_EVENT_HPP
# define STARFARM_EVENT_HPP

# include <ostream>
# include <list>
# include <algorithm>
# include "EventHandler.hpp"


namespace game
{

  template <class... ARGS>
  class Event
  {
// ATTRIBUTES
  private:
          std::list<std::unique_ptr<IEventHandler>> _handlers;

  public:

// METHODS:
  public: // CONSTRUCTORS
          Event() = default;
          ~Event() = default;
          Event(const Event &copy) = default;
          Event(Event &&other) noexcept = default;

  public: // OPERATORS
          Event &operator=(const Event &other) = default;
          Event &operator=(Event &&other) noexcept = default;

  public:
          template <class T>
          HandlerID addListener(Handler<T> &handler, T *const obj)
          {
                  _handlers.push_back(handler);
                  return handler.getId();
          }
          void removeById(HandlerID handlerId)
          {
                  auto handler = std::find_if(
                          _handlers.begin(), _handlers.end(),
                          [handlerId](const EventHandler<ARGS...> &handler) {
                                  return handlerId == handler.getId();
                          }
                  );
                  if (handler != _handlers.end()) {
                          _handlers.erase(handler);
                  }
          }

          void execute() const
          {
                  for (
                          auto &handler : _handlers
                          ) {
                          handler->execute();
                  }
          }
  };

  template <class... ARGS>
  std::ostream &operator<<(std::ostream &out, const Event<ARGS...> &);

}

#endif //STARFARM_EVENT_HPP
