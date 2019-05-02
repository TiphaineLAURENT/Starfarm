//
// Created by tiphaine on 07/04/19.
//

#ifndef STARFARM_TRANSFORMCOMPONENT_HPP
# define STARFARM_TRANSFORMCOMPONENT_HPP

# include <ostream>
# include <array>
# include <Component.hpp>


namespace game
{
  class BaseRendererComponent;

  class TransformComponent : public ecs::Component<TransformComponent>
  {
          // ATTRIBUTES
  private:
          using Positions = struct
          {
                  float x;
                  float y;
          };
          Positions _position;

          using Rotations = struct
          {
                  float x;
                  float y;
                  float z;
          };
          Rotations _rotation;

          using Scales = struct
          {
                  float x;
                  float y;
          };
          Scales _scale;

          BaseRendererComponent *_renderer = nullptr;
  public:

          // METHODS:
  public: // CONSTRUCTORS
          explicit TransformComponent(
                  const Positions &position = Positions{0, 0},
                  const Rotations &rotation = Rotations{0, 0, 0},
                  const Scales &scale = Scales{0, 0}
          );
          ~TransformComponent() override = default;
          TransformComponent(const TransformComponent &copy) = default;
          TransformComponent(TransformComponent &&other) noexcept = default;

  public: // OPERATORS
          TransformComponent &operator=(const TransformComponent &other);
          TransformComponent &operator=(TransformComponent &&other) = default;

  public:
          TransformComponent &linkToRenderer(BaseRendererComponent *renderer)
          {
                  _renderer = renderer;
                  return *this;
          }
          TransformComponent &move(float dx, float dy, bool= false);
          TransformComponent &setPosition(float x, float y);
          const Positions &getPosition() const;

          TransformComponent &setRotation(float angle);
          const Rotations &getRotations() const;

          void update() const;
  };

  std::ostream &operator<<(std::ostream &out, const TransformComponent &);

}

#endif //STARFARM_TRANSFORMCOMPONENT_HPP
