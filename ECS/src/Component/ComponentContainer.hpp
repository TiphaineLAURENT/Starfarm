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
  typename std::vector<C>::iterator;

  template <class C>
  class ComponentContainer : public IComponentContainer
  {
// ATTRIBUTES
  private:
          std::vector<C> _components;

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
          C &addComponent(EntityID entityID, ARGS &&... args)
          {
                  static_assert(
                          std::is_base_of<IComponent, C>::value,
                          "Component must be derived from IComponent"
                  );

                  auto component = C{std::forward<ARGS>(args)...};
                  component.setOwner(entityID);

                  _components.push_back(component);
                  return _components.back();
          }
          C &getComponent(EntityID entityID)
          {
                  for (auto &component : _components) {
                          if (component.getOwner() == entityID) {
                                  return component;
                          }
                  }
          }
          std::vector<C *const> getComponents(EntityID entityID)
          {
                  std::vector<C *const> components;

                  for (auto &component : _components) {
                          if (component->getOwner() == entityID) {
                                  components.emplace_back(&component);
                          }
                  }
                  return components;
          }
          const std::vector<C *const> getComponents(EntityID entityID) const
          {
                  std::vector<C *const> components;

                  for (auto &component : _components) {
                          if (component->getOwner() == entityID) {
                                  components.emplace_back(&component);
                          }
                  }
                  return components;
          }
          void removeComponent(EntityID entityID) override
          {
                  auto toRemove = std::find_if(
                          _components.begin(),
                          _components.end(),
                          [&](C &component) {
                                  return component.getOwner()
                                         == entityID;
                          }
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

          std::vector<C> &getComponents()
          {
                  return _components;
          }

          const std::vector<C> &getComponents() const
          {
                  return _components;
          }

  private:
  };

  template <class C>
  std::ostream &operator<<(std::ostream &out, const ComponentContainer<C> &);

}

#endif /* !ECS_COMPONENTCONTAINER_HPP */
