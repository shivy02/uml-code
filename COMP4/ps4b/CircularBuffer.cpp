/**
 * @file CircularBuffer.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief Implementation of CircularBuffer member functions
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(size_t capacity){
    if (capacity < 1){
      throw std::invalid_argument("Capacity must be greater than zero");
    }

    _capacity = capacity;
    _size = 0;
}

size_t CircularBuffer::size()const{
    return _size;
}

bool CircularBuffer::isEmpty()const {
  return _size > 0 ? false : true;
}

bool CircularBuffer::isFull()const {
  return _size < _capacity ? false : true;
}

void CircularBuffer::enqueue(int16_t x) {

    if (isFull()){
      throw std::runtime_error("Can't enqueue to a full buffer");
    }

  buffer.push_back(x);
  _size++;
}

int16_t CircularBuffer::dequeue() {

  if (isEmpty()){
    throw std::runtime_error("Dequeue Error: Can't deque an empty buffer");
  }

  int16_t temp = peek();
  buffer.pop_front();
  _size--;

  return temp;
}

int16_t CircularBuffer::peek()const {

    if (isEmpty())
      throw std::runtime_error("The buffer is empty");

  return buffer.front();
}

