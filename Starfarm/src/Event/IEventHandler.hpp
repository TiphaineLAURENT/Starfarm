//
// Project Starfarm
// Created by Tiphaine LAURENT on 18/06/2019.
//

#ifndef STARFARM_IEVENTHANDLER_HPP
#define STARFARM_IEVENTHANDLER_HPP

#include <ostream>


namespace game
{

  class IEventHandler
  {
// ATTRIBUTES
  private:
  public:

// METHODS:
  public: // CONSTRUCTORS
          IEventHandler() = default;
          virtual ~IEventHandler() = default;
          IEventHandler(const IEventHandler &copy) = default;
          IEventHandler(IEventHandler &&other) noexcept = default;

  public: // OPERATORS
          IEventHandler &operator=(const IEventHandler &other) = default;
          IEventHandler &operator=(IEventHandler &&other) noexcept = default;

  public:
          virtual void execute() = 0;
  };

  std::ostream &operator<<(std::ostream &out, const IEventHandler &);

}

#endif //STARFARM_IEVENTHANDLER_HPP
