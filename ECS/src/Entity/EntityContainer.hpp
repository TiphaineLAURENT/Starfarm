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
# include <memory>
# include "IEntityContainer.hpp"

namespace ecs
{

  template <class E>
  using EntityMap = std::map<EntityID, std::unique_ptr<E>>;

  template <class E>
  using EEntityIterator =
  typename EntityMap<E>::iterator;

  template <class E>
  class EntityContainer : public IEntityContainer
  {
// ATTRIBUTES
  private:
          EntityMap<E> _entities;

  public:

// METHODS
  public:// CONSTRUCTORS
          EntityContainer() = default;
          ~EntityContainer() override = default;
          EntityContainer(const EntityContainer &copy) = delete;
          EntityContainer(EntityContainer &&) noexcept = delete;

  public: //OPERATORS
          EntityContainer &operator=(const EntityContainer &other) = delete;
          EntityContainer &operator=(EntityContainer &&) noexcept = delete;

  public:
          const char *getEntityContainerTypeName() const override
          {
                  static const char *entityTypeName{typeid(E).name()};

                  return entityTypeName;
          }

          template <class ...ARGS>
          E &createEntity(ARGS &&...args)
          {
                  static_assert(
                          std::is_base_of<IEntity, E>::value,
                          "Entity must be derived from IEntity"
                  );

                  auto entity = std::make_unique<E>(std::forward(args)...);
                  const EntityID entityID = entity->getEntityID();

                  _entities[entityID] = std::move(entity);
                  return getEntityById(entityID);
          }
          E &getEntityById(EntityID entityID)
          {
                  return *_entities[entityID].get();
          }
          EntityMap<E> &getEntities()
          {
                  return _entities;
          }
          const EntityMap<E> &getEntities() const
          {
                  return _entities;
          }
          void destroyEntity(EntityID entityId) override
          {
                  _entities.erase(entityId);
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
