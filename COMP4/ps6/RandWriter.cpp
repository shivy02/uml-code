
/**
 * @file RandWriter.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <map>
#include <ctime>
#include <stdexcept>
#include <utility>
#include <vector>
#include <cstdlib>
#include "RandWriter.h"

RandWriter::RandWriter(std::string text, int k) {
  order = k;
  char tmp;
  bool isAlpha = false;
  std::string tmp_str;
  int x, y;
  init = text;

  srand((int)time(NULL)); //NOLINT
  std::string text2 = text;
  for (int a = 0; a < order; a++) {
    text2.push_back(text[a]);
  }

  int text_size = text.length();

  for (int i = 0; i < text_size; i++) {
    tmp = text.at(i);
    isAlpha = false;

    for (int y = 0; y < alpha.length(); y++) {
      if (alpha.at(y) == tmp) {
        isAlpha = true;
      }
    }
    if (!isAlpha) {
      alpha.push_back(tmp);
    }
  }
  std::sort(alpha.begin(), alpha.end());



  for (x = order; x <= order + 1; x++) {
    for (y = 0; y < text_size; y++) {
      tmp_str.clear();
      tmp_str = text2.substr(y, x);
      kgrams.insert(std::pair<std::string, int>(tmp_str, 0));
    }
  }
  std::map<std::string, int>::iterator it;
  int count_tmp = 0;

  for (x = order; x <= order + 1; x++) {
    for (y = 0; y < text_size; y++) {
      tmp_str.clear();
      tmp_str = text2.substr(y, x);
      it = kgrams.find(tmp_str);
      count_tmp = it->second;
      count_tmp++;
      kgrams[tmp_str] = count_tmp;
    }
  }
}

int RandWriter::orderK() const {
  return order;
}

int RandWriter::freq(std::string kgram) {
  if (kgram.size() != order)
    throw std::runtime_error("kgram is not of size k");

  if (order == 0)
    return init.size();
  else
    return kgrams[kgram];
}

int RandWriter::freq(std::string kgram, char c) {
  if (kgram.size() != order)
    throw std::runtime_error("kgram is not of size k");

  if (order == 0) {
    int count = 0;
    for (int i = 0; i < init.size(); i++)
      if (init[i] == c)
        count++;
    return count;
  } else {
    return kgrams[kgram + c];
  }

  return 0;
}

char RandWriter::kRand(std::string kgram) {
  if (kgram.size() != order || kgrams.end() == kgrams.find(kgram))
    throw std::runtime_error("kRand/ Error: kgram not found");

  std::string temp;
  for (unsigned i = 0; i < alpha.size(); i++)
    for (int j = 0; j < kgrams[kgram + alpha[i]]; j++)
      temp.push_back(alpha[i]);

  return temp[rand() % temp.size()];
}

std::string RandWriter::generate(std::string kgram, int L) {
  std::string s1 = kgram;
  std::string s2 = kgram;
  char c;

  for (int i = 0; i < L - order; i++) {
    c = kRand(s1);
    s2.push_back(c);
    s1.erase(s1.begin());
    s1.push_back(c);
  }

  return s2;
}

std::ostream& operator<<(std::ostream& os, RandWriter& print) {
  os << "\n" << "Original String \"" << print.init << "\"" << std::endl;
  os << "Order: " << print.order << std::endl;
  os << "word: \"" << print.alpha << "\"" << "\n" << std::endl;

  os << "RandWriter Map" << std::endl;
  std::map <std::string, int> temp = print.kgrams;
  for (std::map<std::string, int>::iterator it = temp.begin();
       it != temp.end(); ++it) {
    os << it->first << " " << it->second << " => ";
    for (unsigned i = 0; i < print.alpha.size(); i++) {
      it++;
      os << it->first << " " << it->second << " ";
    }

    os << std::endl;
  }

  return os;
}