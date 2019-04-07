//
// Created by Hugo on 07/04/2019.
//

#ifndef STARFARM_WINDOW_HPP
#define STARFARM_WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class Window
{
public:
    Window(const std::string& Title = "Window", const sf::Vector2u& Size = {640, 480}, bool useShaders = true);
    ~Window();

    void Update();

    bool isFullscreen();
};

#endif //STARFARM_WINDOW_HPP
