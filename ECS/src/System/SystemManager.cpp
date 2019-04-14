//
// Created by tiphaine on 06/04/19.
//

#include <cassert>
#include "SystemManager.hpp"

namespace ecs
{
  SystemManager *SystemManager::_instance = nullptr;

  SystemManager &SystemManager::getInstance()
  {
          if (_instance == nullptr) {
                  _instance = new SystemManager;
          }
          return *_instance;
  }

  SystemWorkStateMaks SystemManager::getSystemWorkState()
  {
          SystemManager &instance = getInstance();

          SystemWorkStateMaks mask(instance._systemWorkOrder.size());
          for (size_t i = 0; i < instance._systemWorkOrder.size(); ++i) {
                  mask[i] = instance._systemWorkOrder[i]->isEnable();
          }

          return mask;
  }

  void SystemManager::setSystemWorkState(SystemWorkStateMaks mask)
  {
          SystemManager &instance = getInstance();

          assert(mask.size() == instance._systemWorkOrder.size() && "Provided"
                                                                    " mask "
                                                                    "does not"
                                                                    " match "
                                                                    "current "
                                                                    "used one");

          for (size_t i = 0; i < instance._systemWorkOrder.size(); ++i) {
                  if (mask[i]) {
                          instance._systemWorkOrder[i]->enable();
                  } else {
                          instance._systemWorkOrder[i]->disable();
                  }
          }
  }

  void updateSystemWorkOrder()
  {

  }

  void update()
  {

  }

}
