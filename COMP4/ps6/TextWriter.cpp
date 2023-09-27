/**
 * @file TextWriter.cpp
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
#include <cstdlib>
#include <sstream>
#include "RandWriter.h"

int main(int argc, const char* argv[]) {
  if (argc != 3) {
    std::cout << "Error: Invalid Arguments";
    return 0;
  }

  std::string str_k(argv[1]);
  std::string str_t(argv[2]);
  std::string input = "";
  std::string curr_str = "";
  std::string out_str = "";

  int k = std::stoi(str_k);
  int t = std::stoi(str_t);

  while (std::cin >> curr_str) {
    input += " " + curr_str;
    curr_str = "";
  }

  std::cout << "Input String:" << std::endl << std::endl;
  for (int a = 0; a < t; a++) {
    std::cout << input[a];
    if (input[a] == '.' || input[a] == '!') {
      std::cout << std::endl;
    }
  }
  RandWriter generator(input, k);
  out_str += "" + generator.generate(input.substr(0, k), t);
  std::cout << std::endl << std::endl << "Output String:" << std::endl << std::endl;
  for (int a = 0; a < t; a++) {
    std::cout << out_str[a];
    if (out_str[a] == '.' || out_str[a] == '!') {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
  return 0;
}