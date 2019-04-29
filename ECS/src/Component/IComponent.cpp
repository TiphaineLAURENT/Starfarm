/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** IComponent
*/

#include "IComponent.hpp"

namespace ecs
{

  std::vector<ComponentID> IComponent::_freeID;
  ComponentID IComponent::_componentCount = 0;

  IComponent::IComponent()
          : _componentID(INVALID_COMPONENT_ID)
  {
          if (!_freeID.empty()) {
                  _componentID = _freeID.back();
                  _freeID.pop_back();
                  ++_componentCount;
          } else {
                  _componentID = _componentCount++;
          }
  }

  const ComponentID IComponent::getComponentCount()
  {
          return _componentCount;
  }

  const ComponentID IComponent::getComponentID() const
  {
          return _componentID;
  }

  IComponent::~IComponent()
  {
          _freeID.push_back(_componentID);
          --_componentCount;
  }

  const EntityID IComponent::getOwner() const
  {
          return _owner;
  }

  IComponent &IComponent::setActive(bool state)
  {
          _active = state;
          return *this;
  }

  const bool IComponent::isActive() const
  {
          return _active;
  }

  IComponent &IComponent::setOwner(const EntityID entityID)
  {
          _owner = entityID;

          return *this;
  }

  std::ostream &operator<<(std::ostream &out, const IComponent *component)
  {
          out << "{ "
              << "ID: " << component->getComponentID() << ", "
              << "Count: " << component->getComponentCount() << ", "
              << "TypeID: " << component->getComponentTypeID() << ", "
              << "Owner: " << component->getOwner() << ", "
              << "Active: " << component->isActive() << true
              << " }";
          return out;
  }

}
