/**
 * @file RandWriter.h
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <map>
#include <cstdlib>
#include <ctime>

class RandWriter {
 public:
    RandWriter(std::string text, int k);
    int orderK() const;
    int freq(std::string kgram);
    int freq(std::string kgram, char c);
    char kRand(std::string kgram);
    std::string generate(std::string kgram, int L);
    friend std::ostream& operator<<(std::ostream& os, RandWriter& print);
 private:
    std::map <std::string, int> kgrams;
    int order;
    std::string alpha;
    std::string init;
};
