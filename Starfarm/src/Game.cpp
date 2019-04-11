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

#define SPEED 5

namespace game {
    Game::Game()
            : _window(sf::VideoMode(640, 480), "Game") {
        ecs::SimpleSystemManager::createSystem<TransformSystem>();
        ecs::SimpleSystemManager::createSystem<RendererSystem>(&_window);
    }

    float GetAngleMouse(sf::Sprite _sprite, sf::RenderWindow *mainWindow) {
        sf::Mouse mouse;
        sf::Vector2i mouseVector = sf::Mouse::getPosition(*mainWindow);
        sf::Vector2f spriteVector = _sprite.getPosition();
        auto angle = atan2(mouseVector.y - spriteVector.y, mouseVector.x - spriteVector.x);
        const float PI = 3.14159265;

        float dx = (spriteVector.x) - mouseVector.x;
        float dy = (spriteVector.y) - mouseVector.y;

        float rotation = (atan2(dy, dx)) * 180 / PI;
        return rotation;
    }

    void Game::loop() {

    }
}
