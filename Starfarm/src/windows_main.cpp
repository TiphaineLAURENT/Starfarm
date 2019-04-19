//
// Created by Hugo on 06/04/2019.
//
#include <Windows.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Game.hpp"
#include "GameTest.hpp"

int wmain(int argc, wchar_t* argv[])
{
    game::Game game;
    game.loop();

    return 0;
}
