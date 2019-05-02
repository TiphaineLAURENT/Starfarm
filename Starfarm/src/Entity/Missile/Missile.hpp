//
// Project Starfarm
// Created by Tiphaine LAURENT on 02/05/2019.
//

#ifndef STARFARM_MISSILE_HPP
# define STARFARM_MISSILE_HPP

# include <ostream>
# include "../GameObject.hpp"


namespace game
{

  class Missile
          : public GameObject
  {
// ATTRIBUTES
  private:
  public:

// METHODS:
  public: // CONSTRUCTORS
          Missile();
          ~Missile() override = default;
          Missile(const Missile &copy) = default;
          Missile(Missile &&other) noexcept = default;

  public: // OPERATORS
          Missile &operator=(const Missile &other) = default;
          Missile &operator=(Missile &&other) = default;

  public:
  };

  std::ostream &operator<<(std::ostream &out, const Missile &);

}

#endif //STARFARM_MISSILE_HPP
