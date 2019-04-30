#include <utility>

//
// Created by tiphaine on 07/04/19.
//

#include "TransformComponent.hpp"

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
                          _position.x = 1920;
                  } else if (_position.x > 1920) {
                          _position.x = 0;
                  }

                  if (_position.y < 0) {
                          _position.y = 1080;
                  } else if (_position.y > 1080) {
                          _position.y = 0;
                  }
          }

          if (_renderer) {
                  _renderer->_sprite.setPosition(_position.x, _position.y);
          }
          return *this;
  }
  TransformComponent &TransformComponent::setPosition(float x, float y)
  {
          _position.x = x;
          _position.y = y;
          if (_renderer) {
                  _renderer->_sprite.setPosition(x, y);
          }
          return *this;
  }
  const TransformComponent::Positions &TransformComponent::getPosition() const
  {
          return _position;
  }

}
