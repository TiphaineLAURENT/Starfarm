//
// Created by tiphaine on 06/04/19.
//

#include "ISystem.hpp"

namespace ecs {

  ISystem::ISystem(SystemPriority priority, float updateInterval)
          : _updateInterval(updateInterval), _priority(priority)
  {

  }

}
