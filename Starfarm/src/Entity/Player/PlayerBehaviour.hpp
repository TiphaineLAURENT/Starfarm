//
// Created by TipLa on 14/04/2019.
//

#ifndef STARFARM_PLAYERBEHAVIOUR_HPP
# define STARFARM_PLAYERBEHAVIOUR_HPP

# include <ostream>
# include "../../Component/MonoBehaviourComponent.hpp"

namespace game
{

  class PlayerBehaviour : public MonoBehaviourComponent
  {
// ATTRIBUTES
  private:
          bool upFlag = false;
          bool downFlag = false;
          bool leftFlag = false;
          bool rightFlag = false;

          float _speed = 3;
  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit PlayerBehaviour(GameObject *gameObject);
          ~PlayerBehaviour() override = default;
          PlayerBehaviour(const PlayerBehaviour &copy) = default;
          PlayerBehaviour(PlayerBehaviour &&other) noexcept = default;

  public: // OPERATORS
          PlayerBehaviour &operator=(const PlayerBehaviour &other) = delete;
          PlayerBehaviour &operator=(PlayerBehaviour &&other) = delete;

  public:
          void awake() override;
          void update() override;

  private:
          float getAngleMouse();
          void moveForward();
  };

  std::ostream &operator<<(std::ostream &out, const PlayerBehaviour &);

}

#endif //STARFARM_PLAYERBEHAVIOUR_HPP
