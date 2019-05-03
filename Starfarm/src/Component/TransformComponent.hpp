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
  constexpr float PI = 3.14159265f;
  constexpr float TWO_PI = 2 * PI;

  constexpr float RAD_TO_DEG = 180 / PI;
  constexpr float DEG_TO_RAD = PI / 180;

  class BaseRendererComponent;

  class TransformComponent : public ecs::Component<TransformComponent>
  {
          // ATTRIBUTES
  private:
          using Positions = struct
          {
                  float x;
                  float y;
                  float z;
          };

          Positions _positions{0, 0, 0};

          using Rotations = struct
          {
                  float x;
                  float y;
                  float z;
          };

          Rotations _rotations{0, 0, 0};

          static constexpr Rotations forward{0, 0, 1};

          using Scales = struct
          {
                  float x;
                  float y;
          };

          Scales _scales{0, 0};

          BaseRendererComponent *_renderer = nullptr;
  public:

          // METHODS:
  public: // CONSTRUCTORS
          TransformComponent() = default;
          explicit TransformComponent(
                  const Positions &position,
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
          TransformComponent &move(float dx, float dy, bool outside = false);
          TransformComponent &setPositions(float x, float y);
          TransformComponent &setPositions(const Positions &positions);
          const Positions &getPositions() const;

          TransformComponent &setRotations(float x, float y, float z);
          TransformComponent &setRotations(const Rotations &rotations);
          const Rotations &getRotations() const;
          const Rotations getForward() const;

          TransformComponent &setScales(float x, float y);
          TransformComponent &setScales(const Scales &scales);
          const Scales &getScales() const;

          void update() const;
  };

  std::ostream &operator<<(std::ostream &out, const TransformComponent &);

}

#endif //STARFARM_TRANSFORMCOMPONENT_HPP
