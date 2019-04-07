//
// Created by tiphaine on 06/04/19.
//

#ifndef ECS_SIMPLESYSTEMMANAGER_HPP
# define ECS_SIMPLESYSTEMMANAGER_HPP

# include <ostream>
# include <vector>
# include <memory>
# include <map>
# include <list>
# include <algorithm>
# include "../util/util.hpp"
# include "ISystem.hpp"

namespace ecs
{

  class SimpleSystemManager
  {
// ATTRIBUTES
  private:
          class SystemCompare {
                  bool operator()(const std::unique_ptr<ISystem> &lhs,
                                  const std::unique_ptr<ISystem> &rhs) const {
                          return lhs->getPriority() < rhs->getPriority();
                  }
          };

          using SystemRegistry = std::map<
                  util::ID,
                  std::unique_ptr<ISystem>
          >;

          static SimpleSystemManager *_instance;
          SystemRegistry _systems;

  public:

// METHODS:
  public: // CONSTRUCTORS
          SimpleSystemManager() = default;
          ~SimpleSystemManager() = default;
          SimpleSystemManager(const SimpleSystemManager &copy) = delete;
          SimpleSystemManager(SimpleSystemManager &&other) noexcept = delete;

  public: // OPERATORS
          SimpleSystemManager &operator=(const SimpleSystemManager &other) = delete;
          SimpleSystemManager &operator=(SimpleSystemManager &&other) = delete;

  public:
          static SimpleSystemManager &getInstance();

          template <class S, class ...ARGS>
          static S &createSystem(ARGS&&... args)
          {
                  static_assert(std::is_base_of<ISystem, S>::value,
                                "System must be derived from ISystem"
                  );

                  const SystemTypeID  systemTypeID = S::getSystemTypeID();
                  SimpleSystemManager &instance    = getInstance();

                  auto system = std::make_unique<S>(std::forward<ARGS>(args)...);
                  instance._systems[systemTypeID] = std::move(system);

                  return instance.getSystem<S>();
          }

          template <class S>
          static S &getSystem()
          {
                  static_assert(std::is_base_of<ISystem, S>::value,
                                "System must be derived from ISystem"
                  );

                  const SystemTypeID systemTypeID = S::getSystemTypeID();
                  SimpleSystemManager &instance       = getInstance();

                  return *static_cast<S*>(instance._systems[systemTypeID].get());
          }

          template <class S>
          static S &enableSystem()
          {
                  static_assert(std::is_base_of<ISystem, S>::value,
                                "System must be derived from ISystem"
                  );

                  const SystemTypeID systemTypeID = S::getSystemTypeID();
                  SimpleSystemManager      &instance    = getInstance();

                  auto system = instance.getSystem<S>();
                  system.enable();
                  return system;
          }

          template <class S>
          static S &disableSystem()
          {
                  static_assert(std::is_base_of<ISystem, S>::value,
                                "System must be derived from ISystem"
                  );

                  const SystemTypeID systemTypeID = S::getSystemTypeID();
                  SimpleSystemManager      &instance    = getInstance();

                  auto system = instance.getSystem<S>();
                  system.disable();
                  return system;
          }

          template <class S>
          static S &setSystemUpdateInterval(float interval)
          {
                  static_assert(std::is_base_of<ISystem, S>::value,
                                "System must be derived from ISystem"
                  );

                  const SystemTypeID systemTypeID = S::getSystemTypeID();
                  SimpleSystemManager      &instance    = getInstance();

                  auto system = instance.getSystem<S>();
                  system.setUpdateInterval(interval);
                  return system;
          }

          template <class S>
          static S &setSystemPriority(SystemPriority priority)
          {
                  static_assert(std::is_base_of<ISystem, S>::value,
                                "System must be derived from ISystem"
                  );

                  const SystemTypeID systemTypeID = S::getSystemTypeID();
                  SimpleSystemManager      &instance    = getInstance();

                  auto system = instance.getSystem<S>();
                  system.setPriority(priority);
                  return system;
          }

          static void update();
  };

  std::ostream &operator<<(std::ostream &out, const SimpleSystemManager &);

}

#endif //ECS_SIMPLESYSTEMMANAGER_HPP
