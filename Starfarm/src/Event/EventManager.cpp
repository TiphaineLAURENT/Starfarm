//
// Project Starfarm
// Created by Tiphaine LAURENT on 18/06/2019.
//

#include "EventManager.hpp"


namespace game
{

  EventManager &EventManager::getInstance()
  {
          static EventManager manager;
          return manager;
  }

  Event &EventManager::createEvent(const std::string &eventName)
  {
          if (_events.find(eventName) == _events.end()) {
                  _events[eventName] = {};
          }
          return _events[eventName];
  }

  template <class T>
  void EventManager::subscribe(
          const std::string &eventName,
          T *obj,
          Handler<T> handler
  )
  {
          _events[eventName].addListener(handler, obj);
  }

  void EventManager::publish(const std::string &eventName)
  {
          _events[eventName].execute();
  }

  void EventManager::clearEvents()
  {
          _events.clear();
  }

  void EventManager::clearListeners(const std::string &eventName)
  {
          _events[eventName].clearListeners();
  }

  Event &EventManager::getEvent(const std::string &eventName)
  {
          return _events[eventName];
  }

}
