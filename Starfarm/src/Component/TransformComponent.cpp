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

  TransformComponent &TransformComponent::move(float dx, float dy)
  {
          _position.first += dx;
          _position.second += dy;

          if (_renderer) {
                  _renderer->_sprite.move(dx, dy);
          }
          return *this;
  }
  TransformComponent &TransformComponent::setPosition(float x, float y)
  {
          _position.first = x;
          _position.second = y;
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
