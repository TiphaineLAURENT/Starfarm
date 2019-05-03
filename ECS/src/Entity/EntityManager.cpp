/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** EntityManager
*/

#include "EntityManager.hpp"

namespace ecs
{

  EntityManager &EntityManager::getInstance()
  {
          static EntityManager instance;
          return instance;
  }

  template <class E>
  CComponentIterator<E> EntityManager::begin()
  {
          return getEntityContainer<E>().begin();
  }

  template <class E>
  CComponentIterator<E> EntityManager::end()
  {
          return getEntityContainer<E>().begin();
  }

}
