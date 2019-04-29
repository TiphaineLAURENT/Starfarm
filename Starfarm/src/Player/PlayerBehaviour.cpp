//
// Created by Tiphaine on 19/04/2019.
//

#include "PlayerBehaviour.hpp"
#include "../Entity/GameObject.hpp"
#include "../Component/TransformComponent.hpp"
#include <SFML/Graphics.hpp>

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
          auto position = transform->getPosition();

          if (leftFlag && position.first - _speed > 0) {
                  transform->move(-_speed, 0);
          }
          if (rightFlag && position.first + _speed < 640) {
                  transform->move(_speed, 0);
          }
          if (upFlag && position.second - _speed > 0) {
                  transform->move(0, -_speed);
          }
          if (downFlag && position.second + _speed < 480) {
                  transform->move(0, _speed);
          }
  }

  const float PI = 3.14159265f;
  float PlayerBehaviour::getAngleMouse()
  {
          auto mousePosition = sf::Mouse::getPosition();
          auto position = _gameObject->_transform->getPosition();
          auto angle = atan2(
                  mousePosition.y - position.second,
                  mousePosition.x - position.first
          );

          float dx = position.first - mousePosition.x;
          float dy = position.second - mousePosition.y;

          return atan2(dy, dx) * 180 / PI;
  }

  void PlayerBehaviour::awake()
  {
          _gameObject->_transform->linkToRenderer
                  (_gameObject->getComponent<RendererComponent>());
  }
}
