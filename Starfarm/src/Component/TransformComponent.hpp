//
// Created by tiphaine on 07/04/19.
//

#ifndef STARFARM_TRANSFORMCOMPONENT_HPP
# define STARFARM_TRANSFORMCOMPONENT_HPP

# include <ostream>
# include <Component.hpp>

namespace game
{

  class TransformComponent : public ecs::Component<TransformComponent>
  {
// ATTRIBUTES
  private:
          using Positions = std::pair<size_t, size_t>;
          Positions _position;

          using Rotations = std::pair<size_t, size_t>;
          Positions _rotation;

          using Scales = std::pair<size_t, size_t>;
          Scales _scale;

  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit TransformComponent(Positions position = Positions(0, 0),
                             Rotations rotation = Rotations(0, 0),
                             Scales scale = Scales(0, 0)
          );
          ~TransformComponent() override = default;
          TransformComponent(const TransformComponent &copy) = default;
          TransformComponent(TransformComponent &&other) noexcept = default;

  public: // OPERATORS
          TransformComponent &operator=(const TransformComponent &other) = default;
          TransformComponent &operator=(TransformComponent &&other) = default;

  public:
          void update() const;
  };

  std::ostream &operator<<(std::ostream &out, const TransformComponent &);

}

#endif //STARFARM_TRANSFORMCOMPONENT_HPP
