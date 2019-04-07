//
// Created by Hugo on 07/04/2019.
//

#ifndef STARFARM_WINDOW_HPP
#define STARFARM_WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>

namespace game
{
    class Window
    {
    public:
        Window(const std::string& Title = "Window", const sf::Vector2u& Size = {640, 480});
        ~Window();

    public:
        void Update();

    private:
        sf::Vector2u _size;
    };
}

#endif //STARFARM_WINDOW_HPP
