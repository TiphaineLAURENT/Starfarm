//
// Created by tiphaine on 06/04/19.
//

#ifndef ECS_SYSTEMMANAGER_HPP
# define ECS_SYSTEMMANAGER_HPP

# include <ostream>
# include <vector>
# include <memory>
# include <map>
# include <list>
# include "../util/util.hpp"
# include "ISystem.hpp"

namespace ecs
{

  using SystemWorkStateMaks = std::vector<bool>;

  class SystemManager
  {
// ATTRIBUTES
  private:
          using SystemDependencyMatrix = std::vector<std::vector<bool>>;
          using SystemRegistry = std::map<util::ID, std::unique_ptr<ISystem>>;
          using SystemWorkOrder = std::vector<ISystem*>;

          static SystemManager *_instance;
          SystemRegistry _systems;
          SystemDependencyMatrix _systemDependencyMatrix;
          SystemWorkOrder _systemWorkOrder;

  public:

// METHODS:
  public: // CONSTRUCTORS
          SystemManager();
          ~SystemManager() = default;
          SystemManager(const SystemManager &copy) = delete;
          SystemManager(SystemManager &&other) noexcept = delete;

  public: // OPERATORS
          SystemManager &operator=(const SystemManager &other) = delete;
          SystemManager &operator=(SystemManager &&other) = delete;

  public:
          static SystemManager &getInstance();

          template <class S, class ...ARGS>
          static S &createSystem(ARGS&&... args)
          {
                  static_assert(std::is_base_of<ISystem, S>::value,
                                "System must be derived from ISystem"
                  );

                  const SystemTypeID systemTypeID = S::getSystemTypeID();
                  SystemManager &instance       = getInstance();

                  auto system = std::make_unique<S>(std::forward<ARGS>(args)...);

                  if (systemTypeID + 1 > instance._systemDependencyMatrix.size()) {
                          instance._systemDependencyMatrix.resize(systemTypeID + 1);
                          for (auto &row : instance._systemDependencyMatrix) {
                                  row.resize(systemTypeID + 1);
                          }
                  }

                  instance._systemWorkOrder.push_back(system.get());
                  instance._systems[systemTypeID] = std::move(system);
                  return *static_cast<S*>(instance._systems[systemTypeID].get());
          }

          template <class S, class D>
          static SystemManager &addSystemDependency(S target, D dependency)
          {
                  static_assert(std::is_base_of<ISystem, S>::value,
                                "Target must be derived from ISystem"
                  );
                  static_assert(std::is_base_of<ISystem, D>::value,
                                "Dependency must be derived from ISystem"
                  );

                  SystemTypeID targetTypeID = target.getSystemTypeID();
                  SystemTypeID dependencyTypeID = dependency.getSystemTypeID();

                  SystemManager &instance       = getInstance();
                  instance
                  ._systemDependencyMatrix[targetTypeID][dependencyTypeID] = true;

                  return instance;
          }

          template <class S, class D, class ...DS>
          static SystemManager &addSystemDependency(S target, D dependency,
                  DS&&... dependencies)
          {
                  static_assert(std::is_base_of<ISystem, S>::value,
                                "Target must be derived from ISystem"
                  );
                  static_assert(std::is_base_of<ISystem, D>::value,
                                "Dependency must be derived from ISystem"
                  );

                  SystemTypeID targetTypeID = target.getSystemTypeID();
                  SystemTypeID dependencyTypeID = dependency.getSystemTypeID();

                  SystemManager &instance       = getInstance();
                  instance
                          ._systemDependencyMatrix[targetTypeID][dependencyTypeID] = true;

                  return instance.addSystemDependency(target,
                                                      std::forward<DS>(dependencies)...);
          }

          template <class S>
          static S &getSystem()
          {
                  static_assert(std::is_base_of<ISystem, S>::value,
                                "System must be derived from ISystem"
                  );

                  const SystemTypeID systemTypeID = S::getSystemTypeID();
                  SystemManager &instance       = getInstance();

                  return *static_cast<S*>(instance._systems[systemTypeID].get());
          }

          template <class S>
          static S &enableSystem()
          {
                  static_assert(std::is_base_of<ISystem, S>::value,
                                "System must be derived from ISystem"
                  );

                  const SystemTypeID systemTypeID = S::getSystemTypeID();
                  SystemManager      &instance    = getInstance();

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
                  SystemManager      &instance    = getInstance();

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
                  SystemManager      &instance    = getInstance();

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
                  SystemManager      &instance    = getInstance();

                  auto system = instance.getSystem<S>();
                  system.setPriority(priority);
                  return system;
          }

          static SystemWorkStateMaks getSystemWorkState();
          static void setSystemWorkState(SystemWorkStateMaks);

          template <class... ActiveSystems>
          static SystemWorkStateMaks generateActiveSystemWorkState
          (ActiveSystems&&... activeSystems)
          {
                  SystemManager      &instance    = getInstance();

                  SystemWorkStateMaks mask(instance._systemWorkOrder.size(),
                                           false);
                  std::list<ISystem*> as{activeSystems...};
                  for (auto &system : as) {
                          for (size_t i = 0; i < instance._systemWorkOrder
                                                         .size(); ++i) {
                                  if (instance
                                              ._systemWorkOrder[i]->getSystemTypeID() ==
                                      system->getSystemTypeID()) {
                                          mask[i] = true;
                                          break;
                                  }
                          }
                  }

                  return mask;
          }

          static void updateSystemWorkOrder();
          static void update();
  };

  std::ostream &operator<<(std::ostream &out, const SystemManager &);

}

#endif //ECS_SYSTEMMANAGER_HPP
