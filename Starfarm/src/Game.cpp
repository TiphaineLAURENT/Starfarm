//
// Created by Hugo on 07/04/2019.
//

#include "Game.hpp"

namespace game
{
    Game::Game()
    {

    }

    void Game::loop()
    {
        sf::Window mainWindow(sf::VideoMode(640, 480), "Game");

        while (mainWindow.isOpen())
        {
            sf::Event event;
            while (mainWindow.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    mainWindow.close();
            }
        }
    }
}