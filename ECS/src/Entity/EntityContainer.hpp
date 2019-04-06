/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** EntityContainer
*/

#ifndef ECS_ENTITYCONTAINER_HPP
# define ECS_ENTITYCONTAINER_HPP

# include <ostream>
# include <map>
# include "IEntityContainer.hpp"

namespace ecs
{

  template <class E>
  using EEntityIterator =
  typename std::vector<std::unique_ptr<IEntity>>::iterator;

  template <class E>
  class EntityContainer : public IEntityContainer
  {
// ATTRIBUTES
    private:
	  std::map<EntityID, std::unique_ptr<IEntity>> _entities;

    public:

// METHODS
    public:// CONSTRUCTORS
	  EntityContainer() = default;
	  ~EntityContainer() override = default;
	  EntityContainer(const EntityContainer &copy) = default;
	  EntityContainer(EntityContainer &&) noexcept = default;

    public: //OPERATORS
	  EntityContainer &operator=(const EntityContainer &other) = default;
	  EntityContainer &operator=(EntityContainer &&) = default;

    public:
	  const char* getEntityContainerTypeName() const override
	  {
		  static const char *entityTypeName{typeid(E).name()};

		  return entityTypeName;
	  }

	  template <class ...ARGS>
	  E &createEntity(ARGS&& ...args)
	  {
		  static_assert(std::is_base_of<IEntity, E>::value,
		                "Entity must be derived from IEntity");

		  auto entity = std::make_unique<E>(std::forward(args)...);
		  const EntityID entityID = entity->getEntityID();

		  _entities[entityID] = std::move(entity);
		  return *static_cast<E*>(_entities[entityID].get());
	  }
	  E *getEntityById(EntityID entityID)
	  {
		  return static_cast<E*>(_entities[entityID].get());
	  }
	  std::vector<E*> getEntities()
	  {
		  return std::vector<E*>(_entities.begin(), _entities.end());
	  }
	  void destroyEntity(IEntity *entity) override
	  {
		  _entities.erase(entity->getEntityID());
	  }

	  EEntityIterator<E> begin()
	  {
		  return _entities.begin();
	  }
	  EEntityIterator<E> end()
	  {
		  return _entities.end();
	  }

    private:
  };

  template <class E>
  std::ostream &operator<<(std::ostream &out, const EntityContainer<E> &);

}

#endif /* !ECS_ENTITYCONTAINER_HPP */
