//
// Created by Hugo on 07/04/2019.
//

#ifndef STARFARM_GAME_HPP
#define STARFARM_GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>

namespace game
{
  class Game
  {
  private:
          sf::RenderWindow _window;

  public:
          struct SETTINGS
          {
                  static constexpr unsigned int WIDTH = 1920;
                  static constexpr unsigned int HEIGHT = 1080;
                  static constexpr char NAME[] = "Starfarm";
                  static constexpr unsigned int FRAMERATE = 60;
          };

  public:
          Game();
          ~Game() = default;

  public:
          void loop();
  };
}

#endif //STARFARM_GAME_HPP
