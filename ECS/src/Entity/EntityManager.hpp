/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** EntityManager
*/

#ifndef ECS_ENTITYMANAGER_HPP
# define ECS_ENTITYMANAGER_HPP

# include <ostream>
# include "EntityContainer.hpp"

namespace ecs
{

  using EntityContainerMap = std::unordered_map<EntityTypeID,
                                                std::unique_ptr<IEntityContainer>>;

  class EntityManager
  {
// ATTRIBUTES
  private:
          EntityContainerMap _containers{};

  public:

// METHODS
  public:// CONSTRUCTORS
          constexpr EntityManager() = default;
          ~EntityManager() = default;
          EntityManager(const EntityManager &copy) = delete;
          EntityManager(EntityManager &&) noexcept = delete;

  public: //OPERATORS
          EntityManager &operator=(const EntityManager &other) = delete;
          EntityManager &operator=(EntityManager &&) = delete;

  public:
          static EntityManager &getInstance();
          template <class E>
          constexpr static EntityContainer<E> &getEntityContainer()
          {
                  static_assert(
                          std::is_base_of<IEntity, E>::value,
                          "Entity must be derived from IEntity"
                  );

                  const ComponentTypeID entityTypeID = E::_entityTypeID;
                  EntityManager &instance = getInstance();

                  if (instance._containers.find(entityTypeID)
                      == instance._containers.end()) {
                          auto container =
                                  std::make_unique<EntityContainer<E>>();
                          instance._containers[entityTypeID] = std::move(
                                  container
                          );
                  }

                  return *static_cast<EntityContainer<E> *>(instance
                          ._containers[entityTypeID].get());
          }

          template <class E, class ...ARGS>
          static E &createEntity(ARGS &&... args)
          {
                  EntityContainer<E> &container = getEntityContainer<E>();

                  return container.createEntity(std::forward(args)...);
          }
          template <class E>
          static E &getEntityById(EntityID entityID)
          {
                  EntityContainer<E> &container = getEntityContainer<E>();

                  return container.getEntityById(entityID);
          }
          template <class E>
          static EntityMap<E> &getComponents(EntityID entityID)
          {
                  EntityContainer<E> &container = getEntityContainer<E>();

                  return container.getEntities(entityID);
          }
          template <class E>
          static void removeEntity(EntityID entityID)
          {
                  EntityContainer<E> &container = getEntityContainer<E>();

                  container.destroyEntity(entityID);
          }

          template <class E>
          static CComponentIterator<E> begin();
          template <class E>
          static CComponentIterator<E> end();

  private:
  };

  std::ostream &operator<<(std::ostream &out, const EntityManager &);

}

#endif /* !ECS_ENTITYMANAGER_HPP */
