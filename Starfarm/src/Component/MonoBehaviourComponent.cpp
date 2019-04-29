//
// Created by TipLa on 14/04/2019.
//

#include "MonoBehaviourComponent.hpp"
#include "../Entity/GameObject.hpp"

namespace game
{
  MonoBehaviourComponent::MonoBehaviourComponent(GameObject *gameObject)
          : Component(), _gameObject(gameObject)
  {
  }
}
