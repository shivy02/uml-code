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

#include <iostream>
#include <stdint.h>
#include <math.h>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <deque>

class CircularBuffer {
 public:
    CircularBuffer(size_t capacity);         // create an empty ring buffer, with given max capacity
    size_t size()const;                      // return number of items currently in the buffer
    bool isEmpty()const;                     // is the buffer empty (size equals zero)?
    bool isFull()const;                      // is the buffer full (size equals capacity)?
    void enqueue(int16_t x);                 // add item x to the end
    int16_t dequeue();                       // delete and return item from the front
    int16_t peek()const;                     // return (but do not delete) item from the front

 private:
    size_t _capacity;
    size_t _size;
    std::deque<int16_t> buffer;

};