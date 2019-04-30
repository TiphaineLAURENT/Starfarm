//
// Created by Tiphaine on 19/04/2019.
//

#include <cmath>
#include <SFML/Graphics.hpp>
#include <EntityManager.hpp>
#include "PlayerBehaviour.hpp"
#include "../Entity/GameObject.hpp"
#include "../Component/TransformComponent.hpp"

namespace game
{
  PlayerBehaviour::PlayerBehaviour(GameObject *gameObject)
          : MonoBehaviourComponent(gameObject)
  {
  }

  void PlayerBehaviour::update()
  {
          upFlag = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
          downFlag = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
          leftFlag = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
          rightFlag = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

          auto &transform = _gameObject->_transform;
          if (leftFlag) {
                  transform->move(-_speed, 0);
          }
          if (rightFlag) {
                  transform->move(_speed, 0);
          }
          if (upFlag) {
                  transform->move(0, -_speed);
          }
          if (downFlag) {
                  transform->move(0, _speed);
          }
  }

  const float PI = 3.14159265f;
  float PlayerBehaviour::getAngleMouse()
  {
          auto mousePosition = sf::Mouse::getPosition();
          auto position = _gameObject->_transform->getPosition();
          auto angle = atan2(
                  mousePosition.y - position.y,
                  mousePosition.x - position.x
          );

          float dx = position.x - mousePosition.x;
          float dy = position.y - mousePosition.y;

          return atan2(dy, dx) * 180 / PI;
  }

  void PlayerBehaviour::awake()
  {
          _gameObject->_transform->linkToRenderer
                  (_gameObject->getComponent<RendererComponent>());
  }
}
