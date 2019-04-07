/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** Entity
*/

#ifndef ECS_ENTITY_HPP
# define ECS_ENTITY_HPP

# include <ostream>
# include "IEntity.hpp"

namespace ecs
{

  template <class E>
  class Entity : public IEntity
  {
// ATTRIBUTES
    private:
    public:
	  static const EntityTypeID _entityTypeID;

// METHODS
    public:// CONSTRUCTORS
	  Entity() = default;
	  ~Entity() override = default;
	  Entity(const Entity &copy) = default;
	  Entity(Entity &&) noexcept = default;

    public: //OPERATORS
	  Entity &operator=(const Entity &other) = default;
	  Entity &operator=(Entity &&) noexcept = default;

    public:
	  const EntityTypeID getEntityTypeID() const override
	  {
		  return _entityTypeID;
	  }

    private:
  };

  template <class E>
  std::ostream &operator<<(std::ostream &out, const Entity<E> &);

  template <class E>
  const EntityTypeID Entity<E>::_entityTypeID =
	                     util::FamilyTypeID<IEntity>::getTypeID<E>();

}

#endif /* !ECS_ENTITY_HPP */
