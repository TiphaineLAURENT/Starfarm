//
// Project Starfarm
// Created by Tiphaine LAURENT on 02/05/2019.
//

#include <cmath>
#include <SFML/Graphics/Transformable.hpp>
#include "MissileBehaviour.hpp"
#include "../GameObject.hpp"
#include "../../Component/TransformComponent.hpp"
#include "../../Component/SpriteComponent.hpp"


namespace game
{
  MissileBehaviour::MissileBehaviour(GameObject *object)
          : MonoBehaviourComponent(object)
  {
  }
  void MissileBehaviour::awake()
  {
          _transform->linkToRenderer
                            (_gameObject->getComponent<SpriteComponent>());
  }
  void MissileBehaviour::update()
  {
          moveForward();
  }
  void MissileBehaviour::moveForward()
  {
          auto rotations = _transform->getRotations();
          _transform->move(
                  _speed * cos(rotations.z * DEG_TO_RAD),
                  _speed * sin(rotations.z * DEG_TO_RAD),
                  true
          );
  }
}
