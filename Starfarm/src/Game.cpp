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
#include "Player/PlayerEntity.hpp"

#define SPEED 5

namespace game
{
    Game::Game()
    {
            ecs::SimpleSystemManager::createSystem<TransformSystem>();
    }

    float GetAngleMouse(sf::Sprite _sprite, sf::RenderWindow* mainWindow)
    {
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

    void Game::loop()
    {
        sf::RenderWindow mainWindow(sf::VideoMode(640, 480), "Game");
        sf::Texture texture;
        sf::Sprite sprite;
        bool upFlag=false;
        bool downFlag=false;
        bool leftFlag=false;
        bool rightFlag=false;

        texture.loadFromFile("darkgrey_05.png");
        sprite.setTexture(texture);
        sprite.setPosition(640 / 2, 480 / 2);
        sprite.setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
        sprite.setRotation(0);
        while (mainWindow.isOpen())
        {
            sf::Event event;
            sprite.setRotation(GetAngleMouse(sprite, &mainWindow) - 90);
            while (mainWindow.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    mainWindow.close();
                if (event.type == sf::Event::KeyPressed)
                {
                    switch (event.key.code)
                    {
                        case  sf::Keyboard::Escape : mainWindow.close(); break;

                        case sf::Keyboard::Up :     upFlag=true; break;
                        case sf::Keyboard::Down:    downFlag=true; break;
                        case sf::Keyboard::Left:    leftFlag=true; break;
                        case sf::Keyboard::Right:   rightFlag=true; break;
                        default : break;
                    }
                }
                if (event.type == sf::Event::KeyReleased)
                {
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up :     upFlag=false; break;
                        case sf::Keyboard::Down:    downFlag=false; break;
                        case sf::Keyboard::Left:    leftFlag=false; break;
                        case sf::Keyboard::Right:   rightFlag=false; break;
                        default : break;
                    }
                }
            }

            if (leftFlag && sprite.getPosition().x - SPEED > 0) sprite.setPosition(sprite.getPosition().x - SPEED, sprite.getPosition().y);
            if (rightFlag && sprite.getPosition().x + SPEED < 640) sprite.setPosition(sprite.getPosition().x + SPEED, sprite.getPosition().y);
            if (upFlag && sprite.getPosition().y - SPEED > 0) sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - SPEED);
            if (downFlag && sprite.getPosition().y + SPEED < 480) sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + SPEED);

            mainWindow.clear(sf::Color::Black);

            mainWindow.setFramerateLimit(60);

            mainWindow.draw(sprite);

            mainWindow.display();
        }
    }
}
