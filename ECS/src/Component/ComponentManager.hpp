/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** ComponentManager
*/

#ifndef ECS_COMPONENTMANAGER_HPP
# define ECS_COMPONENTMANAGER_HPP

# include <ostream>
# include <unordered_map>
# include "ComponentContainer.hpp"

namespace ecs
{

  class ComponentManager
  {
// ATTRIBUTES
    private:
	  static ComponentManager *_instance;

	  std::unordered_map<ComponentTypeID,
		  std::unique_ptr<IComponentContainer>> _containers;

    public:

// METHODS
    public:// CONSTRUCTORS
	  ComponentManager() = default;
	  ~ComponentManager() = default;
	  ComponentManager(const ComponentManager &copy) = delete;
	  ComponentManager(ComponentManager &&) noexcept = delete;

    public: //OPERATORS
	  ComponentManager &operator=(const ComponentManager &other) = delete;
	  ComponentManager &operator=(ComponentManager &&) = delete;

    public:
	  static ComponentManager &getInstance();
	  template <class C>
	  static ComponentContainer<C> &getComponentContainer()
	  {
		  static_assert(std::is_base_of<IComponent, C>::value,
		                "Component must be derived from IComponent");

		  const ComponentTypeID componentTypeID = C::_componentTypeID;
		  ComponentManager &instance = getInstance();

		  if (instance._containers.find(componentTypeID)
		      == instance._containers.end()) {
			  auto container =
				       std::make_unique<ComponentContainer<C>>();
			  instance._containers[componentTypeID] = std::move(container);
		  }

		  return *static_cast<ComponentContainer<C>*>(instance
			  ._containers[componentTypeID].get());
	  }

	  template <class C, class ...ARGS>
	  static C &addComponent(EntityID entityID, ARGS&&... args)
	  {
		  ComponentContainer<C> &container = getComponentContainer<C>();

		  return container.addComponent(entityID, std::forward(args)...);
	  }
	  template <class C>
	  static C *getComponent(EntityID entityID)
	  {
		  ComponentContainer<C> &container = getComponentContainer<C>();

		  return container.getComponent(entityID);
	  }
	  template <class C>
	  static std::vector<C*> getComponents(EntityID entityID)
	  {
		  ComponentContainer<C> &container = getComponentContainer<C>();

		  return container.getComponents(entityID);
	  }
	  template <class C>
	  static void removeComponent(EntityID entityID)
	  {
		  ComponentContainer<C> &container = getComponentContainer<C>();

		  container.removeComponent(entityID);
	  }

	  template <class C>
	  static CComponentIterator<C> begin();
	  template <class C>
	  static CComponentIterator<C> end();

    private:
  };

  std::ostream &operator<<(std::ostream &out, const ComponentManager &);

}

#endif /* !ECS_COMPONENTMANAGER_HPP */
