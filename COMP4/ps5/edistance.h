/** // NOLINT
 * @file edistance.h
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

class EDistance {
 public:
    EDistance(std::string s1, std::string s2);
    static int penalty(char a, char b);
    static int min(int a, int b, int c);
    int optDistance();
    std::string alignment();

 private:
    std::string s1, s2;
    size_t rows, cols;
    std::string* matrix;
};
