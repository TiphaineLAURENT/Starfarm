//
// Created by TipLa on 30/04/2019.
//

#ifndef STARFARM_FPSCOUNTERBEHAVIOUR_HPP
# define STARFARM_FPSCOUNTERBEHAVIOUR_HPP

# include <ostream>
#include "../../Component/MonoBehaviourComponent.hpp"
#include "../../Component/TextComponent.hpp"


namespace game
{

  class FPSCounterBehaviour : public MonoBehaviourComponent
  {
// ATTRIBUTES
  private:
          TextComponent *_text = nullptr;
          sf::Clock _clock;

  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit FPSCounterBehaviour(GameObject *gameObject);
          ~FPSCounterBehaviour() override = default;
          FPSCounterBehaviour(const FPSCounterBehaviour &copy) = default;
          FPSCounterBehaviour(FPSCounterBehaviour &&other) noexcept = default;

  public: // OPERATORS
          FPSCounterBehaviour &operator=(const FPSCounterBehaviour &other) =
          delete;
          FPSCounterBehaviour &operator=(FPSCounterBehaviour &&other) = delete;

  public:
          void awake() override;
          void update() override;
  };

  std::ostream &operator<<(std::ostream &out, const FPSCounterBehaviour &);

}

#endif //STARFARM_FPSCOUNTERBEHAVIOUR_HPP
