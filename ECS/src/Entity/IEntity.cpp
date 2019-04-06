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
	  : _entityID(INVALID_ENTITY_ID),
	    _active(true)
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

  template<class C>
  IEntity &IEntity::removeComponent()
  {
	  return ComponentManager::removeComponent<C>(_entityID);
  }

  std::ostream &operator<<(std::ostream &out, const IEntity &entity)
  {
	  out << "Entity:" << "\n"
	      << "\tID: " << entity.getEntityID() << "\n"
	      << "\tEntity count: " << entity.getEntityCount() << "\n"
	      << "\tEntity type ID: " << entity.getEntityTypeID();

	  return out;
  }

}
