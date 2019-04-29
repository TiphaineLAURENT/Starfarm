//
// Created by Hugo on 07/04/2019.
//

#include <SimpleSystemManager.hpp>
#include <EntityManager.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"
#include "System/RendererSystem.hpp"
#include "Player/PlayerEntity.hpp"
#include "System/BehaviourSystem.hpp"

namespace game
{

  Game::Game()
          : _window(sf::VideoMode(640, 480), "Game")
  {
          ecs::EntityManager::createEntity<PlayerEntity>();
          ecs::SimpleSystemManager::createSystem<RendererSystem>(&_window);
          ecs::SimpleSystemManager::createSystem<BehaviourSystem>();
  }

  void Game::loop()
  {
          while (_window.isOpen()) {
                  ecs::SimpleSystemManager::update();
                  // Process events
                  sf::Event event{};
                  while (_window.pollEvent(event)) {
                          // Close window: exit
                          if (event.type == sf::Event::Closed) {
                                  _window.close();
                          }
                  }
          }
  }
}
