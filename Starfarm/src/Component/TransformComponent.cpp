#include <utility>

//
// Created by tiphaine on 07/04/19.
//

#include "TransformComponent.hpp"
#include "../Game.hpp"
#include "BaseRendererComponent.hpp"

namespace game
{

  TransformComponent::TransformComponent(
          const TransformComponent::Positions &position,
          const TransformComponent::Rotations &rotation,
          const TransformComponent::Scales &scale
  )
          : Component(), _position(position), _rotation(rotation), _scale(scale)
  {
  }

  void TransformComponent::update() const
  {
  }

  TransformComponent &TransformComponent::move(float dx, float dy, bool outside)
  {
          _position.x += dx;
          _position.y += dy;
          if (!outside) {
                  if (_position.x < 0) {
                          _position.x = game::Game::SETTINGS::WIDTH;
                  } else if (_position.x > game::Game::SETTINGS::WIDTH) {
                          _position.x = 0;
                  }

                  if (_position.y < 0) {
                          _position.y = game::Game::SETTINGS::HEIGHT;
                  } else if (_position.y > game::Game::SETTINGS::HEIGHT) {
                          _position.y = 0;
                  }
          }

          if (_renderer) {
                  _renderer->setPosition(_position.x, _position.y);
          }
          return *this;
  }
  TransformComponent &TransformComponent::setPosition(float x, float y)
  {
          _position.x = x;
          _position.y = y;
          if (_renderer) {
                  _renderer->setPosition(x, y);
          }
          return *this;
  }
  const TransformComponent::Positions &TransformComponent::getPosition() const
  {
          return _position;
  }
  TransformComponent &TransformComponent::setRotation(float angle)
  {
          _rotation.z = angle;
          if (_renderer) {
                  _renderer->setRotation(angle);
          }
          return *this;
  }

  TransformComponent &TransformComponent::operator=(const TransformComponent &other)
  {
          _position = other._position;
          _rotation = other._rotation;
          _scale = other._scale;
          if (_renderer) {
                  _renderer->setPosition(_position.x, _position.y);
                  _renderer->setRotation(_rotation.z);
                  _renderer->setScale(_scale.x, _scale.y);
          }
          return *this;
  }
  const TransformComponent::Rotations &TransformComponent::getRotations() const
  {
          return _rotation;
  }

}
