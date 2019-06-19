//
// Project Starfarm
// Created by Tiphaine LAURENT on 18/06/2019.
//

#ifndef STARFARM_IEVENTHANDLER_HPP
#define STARFARM_IEVENTHANDLER_HPP

# include <ostream>
# include "../../../ECS/src/util/util.hpp"

namespace game
{

  using HandlerID = ecs::util::ID;
  static const HandlerID INVALID_HANDLER_ID = ecs::util::INVALID_ID;

  class IEventHandler
  {
// ATTRIBUTES
  private:
          static HandlerID _lastId;

          HandlerID _id;

  public:

// METHODS:
  public: // CONSTRUCTORS
          IEventHandler()
                  : _id(++_lastId)
          {
          }
          virtual ~IEventHandler() = default;
          IEventHandler(const IEventHandler &copy) = default;
          IEventHandler(IEventHandler &&other) noexcept = default;

  public: // OPERATORS
          IEventHandler &operator=(const IEventHandler &other) = default;
          IEventHandler &operator=(IEventHandler &&other) noexcept = default;

  public:
          HandlerID getId() const
          {
                  return _id;
          }
          virtual void execute() = 0;
  };

  std::ostream &operator<<(std::ostream &out, const IEventHandler &);

}

#endif //STARFARM_IEVENTHANDLER_HPP
