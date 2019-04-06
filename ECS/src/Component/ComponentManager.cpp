/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** ComponentManager
*/

#include "ComponentManager.hpp"

namespace ecs
{

  ComponentManager *ComponentManager::_instance = nullptr;

  ComponentManager &ComponentManager::getInstance()
  {
	  if (!_instance)
	  	_instance = new ComponentManager;

	  return *_instance;
  }

  template<class C>
  CComponentIterator<C> ComponentManager::begin()
  {
	  return getComponentContainer<C>().begin();
  }

  template<class C>
  CComponentIterator<C> ComponentManager::end()
  {
	  return getComponentContainer<C>().end();
  }
}
