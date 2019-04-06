/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** ComponentContainer
*/

#ifndef ECS_COMPONENTCONTAINER_HPP
# define ECS_COMPONENTCONTAINER_HPP

# include <ostream>
# include <memory>
# include <vector>
#include <algorithm>
# include "IComponentContainer.hpp"

namespace ecs
{

  template <class C>
  using CComponentIterator =
  typename std::vector<std::unique_ptr<IComponent>>::iterator;

  template <class C>
  class ComponentContainer : public IComponentContainer
  {
// ATTRIBUTES
    private:
	  std::vector<std::unique_ptr<IComponent>> _components;

    public:

// METHODS
    public:// CONSTRUCTORS
	  ComponentContainer() = default;
	  ~ComponentContainer() override = default;
	  ComponentContainer(const ComponentContainer &copy) = default;
	  ComponentContainer(ComponentContainer &&) noexcept = default;

    public: //OPERATORS
	  ComponentContainer &operator=(const ComponentContainer &other) = default;
	  ComponentContainer &operator=(ComponentContainer &&) noexcept = default;

    public:
	  const char *getComponentContainerTypeName() const override
	  {
		  static const char *componentTypeName{typeid(C).name()};

		  return componentTypeName;
	  }

	  template <class ...ARGS>
	  C &addComponent(EntityID entityID, ARGS&&... args)
	  {
		  static_assert(std::is_base_of<IComponent, C>::value,
		                "Component must be derived from IComponent");

		  auto component = std::make_unique<C>(std::forward(args)...);
		  component->setOwner(entityID);

		  _components.push_back(std::move(component));
		  return *static_cast<C*>(_components.back().get());
	  }
	  C *getComponent(EntityID entityID)
	  {
		  for (auto &component : _components) {
			  if (component->getOwner() == entityID)
				  return static_cast<C*>(component.get());
		  }
		  return nullptr;
	  }
	  std::vector<C*> getComponents(EntityID entityID)
	  {
		  std::vector<C*> components;

		  for (auto &component : _components) {
			  if (component->getOwner() == entityID)
				  components.push_back(static_cast<C*>
				                       (component.get()));
		  }
		  return components;
	  }
	  void removeComponent(EntityID entityID) override
	  {
		  auto toRemove = std::find_if(_components.begin(),
		                               _components.end(),
			          [&](std::unique_ptr<IComponent>&component)
		                               {return component->getOwner() == entityID;}
		  );
		  _components.erase(toRemove);
	  }

	  CComponentIterator<C> begin()
	  {
		  return _components.begin();
	  }
	  CComponentIterator<C> end()
	  {
		  return _components.end();
	  }

    private:
  };

  template <class C>
  std::ostream &operator<<(std::ostream &out, const ComponentContainer<C> &);

}

#endif /* !ECS_COMPONENTCONTAINER_HPP */
