//
// Created by tiphaine on 11/04/19.
//

#ifndef ECS_BEHAVIOURSYSTEM_HPP
# define ECS_BEHAVIOURSYSTEM_HPP

# include <ostream>
# include <System.hpp>

namespace ecs
{

  class BehaviourSystem : public ecs::System<BehaviourSystem>
  {
// ATTRIBUTES
  private:
  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit BehaviourSystem();
          ~BehaviourSystem() override = default;
		  BehaviourSystem(const BehaviourSystem&copy) = delete;
		  BehaviourSystem(BehaviourSystem&&other) noexcept = delete;

  public: // OPERATORS
		  BehaviourSystem&operator=(const BehaviourSystem&other) = delete;
		  BehaviourSystem&operator=(BehaviourSystem&&other) = delete;

  public:
          void start();
          void update() override;
  };

  std::ostream &operator<<(std::ostream &out, const BehaviourSystem&);

}

#endif //ECS_BEHAVIOURSYSTEM_HPP
