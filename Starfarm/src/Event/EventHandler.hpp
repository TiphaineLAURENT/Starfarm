//
// Project Starfarm
// Created by Tiphaine LAURENT on 18/06/2019.
//

#ifndef STARFARM_EVENTHANDLER_HPP
# define STARFARM_EVENTHANDLER_HPP

# include <ostream>
#include "../../../ECS/src/util/util.hpp"


namespace game
{

  using HandlerID = ecs::util::ID;
  static const HandlerID INVALID_HANDLER_ID = ecs::util::INVALID_ID;

  template <class... ARGS>
  class EventHandler
  {
// ATTRIBUTES
  private:
          using Handler = void(ARGS...);

          Handler _handler;

          HandlerID _id;

  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit EventHandler(Handler &handler)
                  : _handler(handler)
          {
          }
          ~EventHandler() = default;
          EventHandler(const EventHandler &copy) = default;
          EventHandler(EventHandler &&other) noexcept = default;

  public: // OPERATORS
          EventHandler &operator=(const EventHandler &other) = default;
          EventHandler &operator=(EventHandler &&other) noexcept = default;

          void operator()(ARGS... args) const
          {
                  if (_handler) {
                          _handler(args...);
                  }
          }
          bool operator==(const EventHandler &other) const
          {
                  return _id == other._id;
          }

  public:
          HandlerID getId() const
          {
                  return _id;
          }
  };

  template <class... ARGS>
  std::ostream &operator<<(std::ostream &out, const EventHandler<ARGS...> &);

}

#endif //STARFARM_EVENTHANDLER_HPP
