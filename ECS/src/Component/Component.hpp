/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** Component
*/

#ifndef ECS_COMPONENT_HPP
#define ECS_COMPONENT_HPP

# include <ostream>
# include "IComponent.hpp"

namespace ecs
{

  template <class C>
  class Component : public IComponent
  {
// ATTRIBUTES
  private:
          static ComponentID _componentTypeCount;

  public:
          static const ComponentTypeID _componentTypeID;

// METHODS
  public:// CONSTRUCTORS
          Component()
                : IComponent()
          {
                  ++_componentTypeCount;
          }
          ~Component() override
          {
                  --_componentTypeCount;
          }
          Component(const Component &copy) = default;
          Component(Component &&) noexcept = default;

  public: //OPERATORS
          Component &operator=(const Component &other) = default;
          Component &operator=(Component &&) noexcept = default;

  public:
          static const ComponentID getComponentTypeCount()
          {
                  return _componentTypeCount;
          }

          const ComponentTypeID getComponentTypeID() const override
          {
                  return _componentTypeID;
          }

  private:
  };

  template <class C>
  std::ostream &operator<<(std::ostream &out, const Component<C> &);

  template <class C>
  const ComponentTypeID Component<C>::_componentTypeID =
          util::FamilyTypeID<IComponent>::getTypeID<C>();
  template <class C>
  ComponentID Component<C>::_componentTypeCount = 0;
}

#endif /* !ECS_COMPONENT_HPP */
