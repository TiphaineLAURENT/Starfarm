//
// Project Starfarm
// Created by Tiphaine LAURENT on 02/05/2019.
//

#ifndef STARFARM_MISSILEBEHAVIOUR_HPP
# define STARFARM_MISSILEBEHAVIOUR_HPP

# include <ostream>
# include "../../Component/MonoBehaviourComponent.hpp"


namespace game
{

  class MissileBehaviour
          : public MonoBehaviourComponent
  {
// ATTRIBUTES
  private:
          float _speed = 5;

  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit MissileBehaviour(GameObject *gameObject);
          ~MissileBehaviour() override = default;
          MissileBehaviour(const MissileBehaviour &copy) = default;
          MissileBehaviour(MissileBehaviour &&other) noexcept = default;

  public: // OPERATORS
          MissileBehaviour &operator=(const MissileBehaviour &other) = delete;
          MissileBehaviour &operator=(MissileBehaviour &&other) = delete;

  public:
          void awake() override;
          void update() override;
  };

  std::ostream &operator<<(std::ostream &out, const MissileBehaviour &);

}

#endif //STARFARM_MISSILEBEHAVIOUR_HPP
