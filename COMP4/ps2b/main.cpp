/**
 * @file main.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// #include "CelestialBody.h"
#include "Universe.h"

using namespace std; // NOLINT
using namespace sf; // NOLINT

int main(int argc, char *argv[]) {
    Universe u1;
    cin >> u1;

    cout << u1;

    double time = atof(argv[1]);
    double deltaTime = atof(argv[2]);
    double cTime = 0.0;

    sf::Image image;
    if (!image.loadFromFile("starfield.jpg")) {
        return -1;
    }

    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sf::Vector2u size = image.getSize();
    u1.setx(size.x);
    u1.sety(size.y);

    sf::RenderWindow window(sf::VideoMode(size.x, size.y), "This is the Solar System!"); // NOLINT
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);

        if (cTime < time) {
            u1.step(deltaTime);
            cTime += deltaTime;
        } else if (cTime >= time) {
            cout << u1 << std::endl;
            window.close();
        }
        for (int i = 0; i < u1.getNumBodies(); i++) {
            window.draw(u1.getPlanet(i));
        }
        window.display();
    }

    return 0;
}
