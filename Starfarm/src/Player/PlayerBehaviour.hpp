//
// Created by TipLa on 14/04/2019.
//

#ifndef STARFARM_PLAYERBEHAVIOUR_HPP
# define STARFARM_PLAYERBEHAVIOUR_HPP

# include <ostream>
# include "../Component/MonoBehaviourComponent.hpp"

namespace game
{

  class PlayerBehaviour : public MonoBehaviourComponent
  {
// ATTRIBUTES
  private:
  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit PlayerBehaviour(GameObject *gameObject);
          ~PlayerBehaviour() override = default;
          PlayerBehaviour(const PlayerBehaviour &copy) = default;
          PlayerBehaviour(PlayerBehaviour &&other) noexcept = default;

  public: // OPERATORS
          PlayerBehaviour &operator=(const PlayerBehaviour &other) = default;
          PlayerBehaviour &operator=(PlayerBehaviour &&other) = default;

  public:
  };

  std::ostream &operator<<(std::ostream &out, const PlayerBehaviour &);

}

#endif //STARFARM_PLAYERBEHAVIOUR_HPP
