//
// Created by Hugo on 07/04/2019.
//

#include <SimpleSystemManager.hpp>
#include <EntityManager.hpp>
#include "Game.hpp"
#include "System/TransformSystem.hpp"
#include "Player/PlayerEntity.hpp"
#include <iostream>

namespace game
{
    Game::Game()
    {
            ecs::SimpleSystemManager::createSystem<TransformSystem>();
    }

    void Game::loop()
    {
            ecs::EntityManager::createEntity<PlayerEntity>();
            ecs::EntityManager::createEntity<PlayerEntity>();
            ecs::EntityManager::createEntity<PlayerEntity>();
            ecs::EntityManager::createEntity<PlayerEntity>();
            ecs::EntityManager::createEntity<PlayerEntity>();
            ecs::EntityManager::createEntity<PlayerEntity>();
            ecs::EntityManager::createEntity<PlayerEntity>();
            auto player = ecs::EntityManager::createEntity<PlayerEntity>();

            std::clog << player.getComponent<TransformComponent>()->getComponentCount()
                      << "\n";
        sf::Window mainWindow(sf::VideoMode(640, 480), "Game");

        while (mainWindow.isOpen())
        {
                ecs::SimpleSystemManager::update();
            sf::Event event;
            while (mainWindow.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    mainWindow.close();
            }
        }
    }
}
