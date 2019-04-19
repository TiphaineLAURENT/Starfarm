//
// Created by Hugo on 07/04/2019.
//

#include <SimpleSystemManager.hpp>
#include <EntityManager.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "GameTest.hpp"
#include "System/TransformSystem.hpp"
#include "System/RendererSystem.hpp"
#include "Player/PlayerEntity.hpp"

#define SPEED 5

namespace game
{
    float getAngleMouse(sf::Sprite _sprite, sf::RenderWindow *mainWindow) {

        sf::Vector2i mouseVector = sf::Mouse::getPosition(*mainWindow);
        sf::Vector2f spriteVector = _sprite.getPosition();
        const float PI = 3.14159265;

        float dx = (spriteVector.x) - mouseVector.x;
        float dy = (spriteVector.y) - mouseVector.y;

        float rotation = (atan2(dy, dx)) * 180 / PI;
        return rotation;
    }

    void GameTest::loop()
    {
        sf::RenderWindow window(sf::VideoMode(640, 480), "Starfarm");
        window.setFramerateLimit(60);
        sf::Texture texture;
        sf::Sprite sprite;

        bool upFlag = false;
        bool downFlag = false;
        bool leftFlag = false;
        bool rightFlag = false;

        texture.loadFromFile("darkgrey_05.png");

        sprite.setTexture(texture);
        sprite.setPosition(640 / 2, 480 / 2);
        sprite.setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
        sprite.setRotation(0);

        while (window.isOpen()) {
            sf::Event event;

            sprite.setRotation(getAngleMouse(sprite, &window) - 90);
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {
                        case sf::Keyboard::Escape :
                            window.close();
                            break;

                        case sf::Keyboard::Up :
                            upFlag = true;
                            break;
                        case sf::Keyboard::Down:
                            downFlag = true;
                            break;
                        case sf::Keyboard::Left:
                            leftFlag = true;
                            break;
                        case sf::Keyboard::Right:
                            rightFlag = true;
                            break;
                        default :
                            break;
                    }
                }
                if (event.type == sf::Event::KeyReleased) {
                    switch (event.key.code) {
                        case sf::Keyboard::Up :
                            upFlag = false;
                            break;
                        case sf::Keyboard::Down:
                            downFlag = false;
                            break;
                        case sf::Keyboard::Left:
                            leftFlag = false;
                            break;
                        case sf::Keyboard::Right:
                            rightFlag = false;
                            break;
                        default :
                            break;
                    }
                }
            }

            if (leftFlag && sprite.getPosition().x - SPEED > 0)
                sprite.setPosition(sprite.getPosition().x - SPEED, sprite.getPosition().y);
            if (rightFlag && sprite.getPosition().x + SPEED < 640)
                sprite.setPosition(sprite.getPosition().x + SPEED, sprite.getPosition().y);
            if (upFlag && sprite.getPosition().y - SPEED > 0)
                sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - SPEED);
            if (downFlag && sprite.getPosition().y + SPEED < 480)
                sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + SPEED);

            window.clear(sf::Color::Black);

            window.draw(sprite);

            window.display();
        }
    }
}
