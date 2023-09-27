/**
 * @file CircularBuffer.h
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief Implementation of CircularBuffer class
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <stdint.h>
#include <math.h>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <deque>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class CircularBuffer {
 public:
    explicit CircularBuffer(size_t capacity);         // create an empty ring buffer, with given max capacity  // NOLINT
    size_t size()const;                      // return number of items currently in the buffer // NOLINT
    bool isEmpty()const;                     // is the buffer empty (size equals zero)? // NOLINT
    bool isFull()const;                      // is the buffer full (size equals capacity)? // NOLINT
    void enqueue(int16_t x);                 // add item x to the end// NOLINT
    int16_t dequeue();                       // delete and return item from the front // NOLINT
    int16_t peek()const;                     // return (but do not delete) item from the front // NOLINT

 private:
    size_t _capacity;
    size_t _size;
    std::deque<int16_t> buffer;
};
