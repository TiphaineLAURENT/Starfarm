/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** IEntity
*/

#include "IEntity.hpp"
#include "../Component/ComponentManager.hpp"

namespace ecs
{

  std::vector<EntityID> IEntity::_freeID;
  EntityID IEntity::_entityCount = 0;

  const EntityTypeID IEntity::getEntityTypeID() const
  {
          return _entityTypeID;
  }

  IEntity::IEntity()
  {
          if (!_freeID.empty()) {
                  _entityID = _freeID.back();
                  _freeID.pop_back();
          } else {
                  _entityID = _entityCount++;
          }
  }

  const EntityID IEntity::getEntityID() const
  {
          return _entityID;
  }

  IEntity &IEntity::setActive(bool state)
  {
          _active = state;
          return *this;
  }

  const bool IEntity::isActive() const
  {
          return _active;
  }

  const EntityID IEntity::getEntityCount()
  {
          return _entityCount;
  }

  IEntity::~IEntity()
  {
          _freeID.push_back(_entityID);
  }

  template <class C>
  IEntity &IEntity::removeComponent()
  {
          return ComponentManager::removeComponent<C>(_entityID);
  }

  std::ostream &operator<<(std::ostream &out, const IEntity *entity)
  {
          out << "{e "
              << "ID: " << entity->getEntityID() << ", "
              << "Entity count: " << entity->getEntityCount() << ", "
              << "Entity type ID: " << entity->getEntityTypeID() << ", "
              << "Entity type name: " << typeid(entity).name()
              << " }";

          return out;
  }

}
