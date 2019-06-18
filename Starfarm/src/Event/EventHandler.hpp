//
// Project Starfarm
// Created by Tiphaine LAURENT on 18/06/2019.
//

#ifndef STARFARM_EVENTHANDLER_HPP
# define STARFARM_EVENTHANDLER_HPP

# include <ostream>
# include "IEventHandler.hpp"


namespace game
{

  template <class T>
  using Handler = void(T *const);

  template <class T>
  class EventHandler
          : public IEventHandler
  {

// ATTRIBUTES
  private:
          Handler<T> _handler;

          T *const _obj;

  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit EventHandler(Handler<T> &handler, T *const obj)
                  : _handler(handler), _obj(obj)
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
