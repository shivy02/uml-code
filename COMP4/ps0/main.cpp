/**
 * @file main.cpp - Implementation of SFML Sprite 
 * @brief Press arrow keys to move and Num1 and Num2 keys to rotate.
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    const unsigned WINDOW_WIDTH = 600;
    const unsigned WINDOW_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML window");
    sf::Texture texture;

    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;

    sf::Sprite sprite(texture);

    sprite.scale(sf::Vector2f(.12, .12));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.move(-.25, 0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.move(.25, 0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                sprite.move(0, -.25);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sprite.move(0, .25);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                sprite.rotate(1);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                sprite.rotate(-1);
        }

        if (sprite.getPosition().x < 0) {
            sprite.setPosition(0, sprite.getPosition().y);
        }
        if (sprite.getPosition().y < 0) {
            sprite.setPosition(sprite.getPosition().x, 0);
        }
        if (sprite.getPosition().x + sprite.getGlobalBounds().width > WINDOW_WIDTH) {
            sprite.setPosition(WINDOW_WIDTH - sprite.getGlobalBounds().width, sprite.getPosition().y);
        }
        if (sprite.getPosition().y + sprite.getGlobalBounds().width > WINDOW_HEIGHT) {
            sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - sprite.getGlobalBounds().height);
        } 
    }

    return 0;
}
