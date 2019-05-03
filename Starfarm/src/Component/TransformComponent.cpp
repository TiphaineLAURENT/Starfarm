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
          : Component(), _positions(position), _rotations(rotation),
            _scales(scale)
  {
  }

  void TransformComponent::update() const
  {
  }

  TransformComponent &TransformComponent::move(float dx, float dy, bool outside)
  {
          _positions.x += dx;
          _positions.y += dy;
          if (!outside) {
                  if (_positions.x < 0) {
                          _positions.x = game::Game::SETTINGS::WIDTH;
                  } else if (_positions.x > game::Game::SETTINGS::WIDTH) {
                          _positions.x = 0;
                  }

                  if (_positions.y < 0) {
                          _positions.y = game::Game::SETTINGS::HEIGHT;
                  } else if (_positions.y > game::Game::SETTINGS::HEIGHT) {
                          _positions.y = 0;
                  }
          }

          if (_renderer) {
                  _renderer->setPositions(_positions.x, _positions.y);
          }
          return *this;
  }
  TransformComponent &TransformComponent::setPositions(float x, float y)
  {
          _positions.x = x;
          _positions.y = y;
          if (_renderer) {
                  _renderer->setPositions(x, y);
          }
          return *this;
  }
  const TransformComponent::Positions &TransformComponent::getPositions() const
  {
          return _positions;
  }
  TransformComponent &TransformComponent::setRotations(
          float x,
          float y,
          float z
  )
  {
          _rotations.x = x;
          _rotations.y = y;
          _rotations.z = z;
          if (_renderer) {
                  _renderer->setRotation(z);
          }
          return *this;
  }

  TransformComponent &TransformComponent::operator=(const TransformComponent &other)
  {
          setPositions(other._positions);
          setRotations(other._rotations);
          setScales(other._scales);
          return *this;
  }
  const TransformComponent::Rotations &TransformComponent::getRotations() const
  {
          return _rotations;
  }
  TransformComponent &TransformComponent::setPositions(const TransformComponent::Positions &positions)
  {
          setPositions(positions.x, positions.y);
          return *this;
  }
  TransformComponent &TransformComponent::setRotations(const TransformComponent::Rotations &rotations)
  {
          setRotations(rotations.x, rotations.y, rotations.z);
          return *this;
  }
  TransformComponent &TransformComponent::setScales(float x, float y)
  {
          _scales.x = x;
          _scales.y = y;
          if (_renderer) {
                  _renderer->setScales(x, y);
          }
          return *this;
  }
  TransformComponent &TransformComponent::setScales(
          const
          TransformComponent::Scales &scales
  )
  {
          setScales(scales.x, scales.y);
          return *this;
  }
  const TransformComponent::Scales &TransformComponent::getScales() const
  {
          return _scales;
  }
  const TransformComponent::Rotations TransformComponent::getForward() const
  {
          return {0, 0, forward.z * _rotations.z};
  }

}
