//
// Created by tiphaine on 07/04/19.
//

#include <iostream>
#include "TransformComponent.hpp"

namespace game
{

  TransformComponent::TransformComponent(TransformComponent::Positions position,
                                         TransformComponent::Rotations rotation,
                                         TransformComponent::Scales scale
  )
  {
          _position = std::move(position);
          _rotation = std::move(rotation);
          _scale = std::move(scale);
  }

  void TransformComponent::update() const
  {
          std::clog << "Transform Component Update" << getComponentID() << "\n";
  }

}
