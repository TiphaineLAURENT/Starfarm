//
// Created by tiphaine on 07/04/19.
//

#ifndef STARFARM_TRANSFORMSYSTEM_HPP
# define STARFARM_TRANSFORMSYSTEM_HPP

# include <ostream>
# include <System.hpp>

namespace game
{

  class TransformSystem : public ecs::System<TransformSystem>
  {
// ATTRIBUTES
  private:
  public:

// METHODS:
  public: // CONSTRUCTORS
          TransformSystem() = default;
          ~TransformSystem() final = default;
          TransformSystem(const TransformSystem &copy) = delete;
          TransformSystem(TransformSystem &&other) noexcept = delete;

  public: // OPERATORS
          TransformSystem &operator=(const TransformSystem &other) = delete;
          TransformSystem &operator=(TransformSystem &&other) = delete;

  public:
          void update() final;
  };

  std::ostream &operator<<(std::ostream &out, const TransformSystem &);

}

#endif //STARFARM_TRANSFORMSYSTEM_HPP
