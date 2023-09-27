/**
 * @file StringSound.h
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef STRINGSOUND_H_
#include "CircularBuffer.h"
#include <vector>
#include <memory>
#endif
class StringSound {
 public:
    explicit StringSound(double frequency);
    explicit StringSound(std::vector<sf::Int16> init);
    StringSound (const StringSound &obj) = delete;  // no copy const
    void pluck();
    void tic();
    sf::Int16 sample();
    int time();
 private:
    std::unique_ptr<CircularBuffer> _cb;
    int _time;
};
