//
// Created by Hugo on 07/04/2019.
//

#ifndef STARFARM_GAME_HPP
#define STARFARM_GAME_HPP

#include <SFML/Window.hpp>

namespace game
{
    class Game {
    public:
        Game();
        ~Game() = default;

    public:
        void loop();
    private:
		sf::RenderWindow _window;
    };
}


#endif //STARFARM_GAME_HPP
