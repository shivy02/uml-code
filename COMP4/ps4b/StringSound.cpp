/**
 * @file StringSound.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "StringSound.h"
#include <vector>

unsigned SAMPLES_PER_SEC = 44100;

StringSound::StringSound(double frequency) {
    _cb = std::unique_ptr<CircularBuffer>(new CircularBuffer(static_cast<size_t>(ceil(SAMPLES_PER_SEC / frequency)))); // NOLINT
}

StringSound::StringSound(std::vector<sf::Int16> init) {
    _time = 0;
    _cb = std::unique_ptr<CircularBuffer>(new CircularBuffer(static_cast<size_t>(init.size())));  // NOLINT

    for (int i = 0; i < init.size(); i++) {
        _cb->enqueue(init[i]);
    }
}

void StringSound::pluck() {
    while (!(_cb->isEmpty())) {
      _cb->dequeue();
    }
    while (!(_cb->isFull())) {
      _cb->enqueue((sf::Int16)(rand() & 0xffff));  // NOLINT
    }
}

void StringSound::tic() {
    int16_t f = _cb->dequeue();
    int16_t l = _cb->peek();

    _cb->enqueue(0.5*0.996*(f+l));
    _time++;
}

sf::Int16 StringSound::sample() {
    return _cb->peek();
}

int StringSound::time() {
    return _time;
}
