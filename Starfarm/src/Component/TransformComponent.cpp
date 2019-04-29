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
          : _position(position), _rotation(rotation), _scale(scale)
  {
  }

  void TransformComponent::update() const
  {
  }

}
