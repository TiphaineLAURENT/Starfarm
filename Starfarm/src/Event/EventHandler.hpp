//
// Project Starfarm
// Created by Tiphaine LAURENT on 18/06/2019.
//

#ifndef STARFARM_EVENTHANDLER_HPP
# define STARFARM_EVENTHANDLER_HPP

# include <ostream>
# include "../../../ECS/src/util/util.hpp"
# include "IEventHandler.hpp"


namespace game
{

  template <class T>
  using Handler = void(T *const);
  using HandlerID = ecs::util::ID;
  static const HandlerID INVALID_HANDLER_ID = ecs::util::INVALID_ID;

  template <class T>
  class EventHandler
          : public IEventHandler
  {

// ATTRIBUTES
  private:
          Handler<T> _handler;

          T *const _obj;

          static HandlerID _lastId;
          HandlerID _id;

  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit EventHandler(Handler<T> &handler, T *const obj)
                  : _handler(handler), _obj(obj), _id(++_lastId)
          {
          }
          ~EventHandler() override = default;
          EventHandler(const EventHandler &copy) = default;
          EventHandler(EventHandler &&other) noexcept = default;

  public: // OPERATORS
          EventHandler &operator=(const EventHandler &other) = default;
          EventHandler &operator=(EventHandler &&other) noexcept = default;

  public:
          HandlerID getId() const
          {
                  return _id;
          }
          void execute() override
          {
                  _handler(_obj);
          }
  };

  template <class T>
  std::ostream &operator<<(std::ostream &out, const EventHandler<T> &);

}

#endif //STARFARM_EVENTHANDLER_HPP
