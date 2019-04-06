/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** Component
*/

#ifndef ECS_COMPONENT_HPP
# define ECS_COMPONENT_HPP

# include <ostream>
# include "IComponent.hpp"

namespace ecs
{

  template <class C>
  class Component : public IComponent
  {
// ATTRIBUTES
    private:
    public:
	  static const ComponentTypeID _componentTypeID;

// METHODS
    public:// CONSTRUCTORS
	  Component() = default;
	  virtual ~Component() = default;
	  Component(const Component &copy) = default;
	  Component(Component &&) noexcept = default;

    public: //OPERATORS
	  Component &operator=(const Component &other) = default;
	  Component &operator=(Component &&) = default;

    public:
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

}

#endif /* !ECS_COMPONENT_HPP */
