/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** EntityManager
*/

#include "EntityManager.hpp"

namespace ecs
{

  EntityManager *EntityManager::_instance = nullptr;

  EntityManager &EntityManager::getInstance()
  {
	  if (_instance == nullptr)
	  	_instance = new EntityManager;

	  return *_instance;
  }

  template<class E>
  CComponentIterator<E> EntityManager::begin()
  {
	  return getEntityContainer<E>().begin();
  }

  template<class E>
  CComponentIterator<E> EntityManager::end()
  {
	  return getEntityContainer<E>().begin();
  }

}
