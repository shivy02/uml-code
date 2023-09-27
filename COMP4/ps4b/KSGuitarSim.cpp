// Copyright [2022] <Shivam Patel
/**
 * @file KSGuitarSim.cpp
 * @author Shivam Patel 
 * @brief 
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <limits.h>

#include "CircularBuffer.h"
#include "StringSound.h"

#include <cmath>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100
const std::string key = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";  // NOLINT

std::vector<sf::Int16> makeSamples(StringSound& ss) {  // NOLINT
    std::vector<sf::Int16> samples;

    ss.pluck();
    int duration = 8;
    int i;
    for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
        ss.tic();
        samples.push_back(ss.sample());
    }

    return samples;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Plucked String Sound Lite");  // NOLINT
    sf::Event event;
    double freq;
    std::vector<sf::Int16> samples;

    std::vector<std::vector<sf::Int16>> samples2;
    std::vector<sf::SoundBuffer> buffers;
    std::vector<sf::Sound> sounds;

    for (int i = 0; i < 37; i++) {
        freq = 440.0 * pow(2.0, (i-24.0)/12.0);
        StringSound gs1(freq);
         samples2.push_back(makeSamples(gs1));
    }

    for (int i = 0; i < 37; i++) {
        sf::SoundBuffer buf1;
         if (!buf1.loadFromSamples(&samples2[i][0], samples2[i].size(), 2, SAMPLES_PER_SEC)) {  // NOLINT
            throw std::runtime_error("failed to load from samples");
         }
         buffers.push_back(buf1);
    }

    for (int i = 0; i < 37; i++) {
           sf::Sound sound1;
           sound1.setBuffer(buffers[i]);
           sounds.push_back(sound1);
    }

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::TextEntered) {
                unsigned int temp = key.find(event.text.unicode);
                if (temp < key.size()) {
                sounds[temp].play();
                }
            }
            

            window.clear();
            window.display();
        }
    }
    return 0;
}

