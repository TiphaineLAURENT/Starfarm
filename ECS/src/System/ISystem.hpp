//
// Created by tiphaine on 06/04/19.
//

#ifndef ECS_ISYSTEM_HPP
# define ECS_ISYSTEM_HPP

# include <ostream>
# include "../util/util.hpp"

namespace ecs
{

  using SystemTypeID = util::ID;

  enum class SystemPriority {
          LOWEST,
          LOW,
          NORMAL,
          MEDIUM,
          HIGH,
          HIGHEST
  };

  class ISystem
  {
// ATTRIBUTES
  protected:
          float _timeSinceLastUpdate = 0.;
          float _updateInterval;

          SystemPriority _priority;

          bool _enabled = true;
          bool _needUpdate = true;
          bool _reserved = false;

  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit ISystem(SystemPriority = SystemPriority::NORMAL,
                  float = 1.);
          virtual ~ISystem() = default;
          ISystem(const ISystem &copy) = delete;
          ISystem(ISystem &&other) noexcept = delete;

  public: // OPERATORS
          ISystem &operator=(const ISystem &other) = delete;
          ISystem &operator=(ISystem &&other) noexcept = delete;

  public:
          virtual const SystemTypeID getSystemTypeID() const = 0;
          virtual const char *getSystemTypeName() const = 0;

          virtual void preUpdate() = 0;
          virtual void update() = 0;
          virtual void postUpdate() = 0;

          bool isEnable() const
          {
                  return _enabled;
          }
          void enable()
          {
                  _enabled = true;
          }
          void disable()
          {
                  _enabled = false;
          }

          float getUpdateInterval() const
          {
                  return _updateInterval;
          }
          void setUpdateInterval(float interval)
          {
                  _updateInterval = interval;
          }

          SystemPriority getPriority() const
          {
                  return _priority;
          }
          void setPriority(SystemPriority priority)
          {
                  _priority = priority;
          }

  };

  std::ostream &operator<<(std::ostream &out, const ISystem &);

}

#endif //ECS_ISYSTEM_HPP
