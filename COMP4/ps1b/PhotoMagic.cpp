/**
 * @file PhotoMagic.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief implementation for transform function.
 * @version 0.1
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "FibLFSR.h"

void transform(sf::Image& thisImage, FibLFSR *l1);

int main(int argc, char *argv[]){

    //initialize seed
    FibLFSR l1(argv[3]);

    sf::Image image1;
    sf::Image image2;

    //load image
	if (!image1.loadFromFile(argv[1]))
		return -1;
    if (!image2.loadFromFile(argv[1]))
		return -1;

    //transform second image
    transform(image2, &l1);

    //save the output to a file
    if(!image2.saveToFile(argv[2]))
		return -1;

    //set window size
	sf::RenderWindow window1(sf::VideoMode(image1.getSize().x, image1.getSize().y), "first");
    sf::RenderWindow window2(sf::VideoMode(image2.getSize().x, image2.getSize().y), "second");
    
	sf::Texture texture1;
	texture1.loadFromImage(image1);
    sf::Texture texture2;
	texture2.loadFromImage(image2);

	sf::Sprite sprite1;
	sprite1.setTexture(texture1);
    sf::Sprite sprite2;
	sprite2.setTexture(texture2);

    //run the
    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        window1.clear();
        window1.draw(sprite1);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }

	return 0;
}

void transform(sf::Image& thisImage, FibLFSR *l2){

    sf::Color p;

    //transform all of the pixels with the xor operation
    for (int x = 0; x < thisImage.getSize().x; x++) {
        for (int y = 0; y < thisImage.getSize().y; y++) {
            p = thisImage.getPixel(x, y);
            p.r = (p.r ^ l2->generate(10));
            p.g = (p.g ^ l2->generate(10));
            p.b = (p.b ^ l2->generate(10));
            thisImage.setPixel(x, y, p);
        }
    }
}