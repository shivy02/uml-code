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
#include "CelestialBody.h"
#include "Universe.h"

using namespace std;
using namespace sf;

int main (int argc, char *argv[]){

    Universe u1;
    cin >> u1;

    sf::Image image;
    if(!image.loadFromFile("starfield.jpg")){
        return -1;
    }


    sf::Texture texture;
    sf::Sprite sprite;
    
    texture.loadFromImage(image);
    sprite.setTexture(texture);


    sf::Vector2u size = image.getSize();
    

    sf::RenderWindow window(sf::VideoMode(size.x, size.y), "This is the Solar System!");
    
    u1.size(size.x, size.y);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        for(int i = 0; i < u1.getNumBodies(); i++){
            window.draw(u1.getPlanet(i));
        }
        window.display();
    }

    return 0;
}