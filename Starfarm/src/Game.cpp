//
// Created by Hugo on 07/04/2019.
//

#include <SimpleSystemManager.hpp>
#include <EntityManager.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Game.hpp"
#include "System/TransformSystem.hpp"
#include "System/RendererSystem.hpp"
#include "Player/PlayerEntity.hpp"

namespace game
{
    Game::Game()
		: _window(sf::VideoMode(640, 480, 32), "Game")
    {
            ecs::SimpleSystemManager::createSystem<TransformSystem>();
			ecs::SimpleSystemManager::createSystem<RendererSystem>(&_window);
    }

    float GetAngleMouse(sf::Sprite _sprite)
    {
        const float Pi = 3.141592654f;
        sf::Mouse mouse;
        sf::Vector2i mouseVector = mouse.getPosition();
        sf::Vector2f spriteVector = _sprite.getPosition();
        auto angle = atan2(mouseVector.y - spriteVector.y, mouseVector.x - spriteVector.x);
        return angle / Pi * 180;
    }

    void Game::loop()
    {
		auto player = ecs::EntityManager::createEntity<PlayerEntity>();

        while (_window.isOpen())
        {
			ecs::SimpleSystemManager::update();
            sf::Event event;
            while (_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    _window.close();
            }
        }
    }
}
