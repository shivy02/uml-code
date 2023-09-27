/**
 * @file test.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief Test cases for CircularBuffer functions
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <vector>
#include <exception>
#include <stdexcept>

#include "StringSound.h"

BOOST_AUTO_TEST_CASE(STRINGSOUND) {
  std::vector<sf::Int16> vec;

  vec.push_back(0);
  vec.push_back(2000);
  vec.push_back(4000);
  vec.push_back(-10000);

  BOOST_REQUIRE_NO_THROW(StringSound test = StringSound(vec));

  StringSound test = StringSound(vec);

  std::cout << "Sample: " << test.sample() << "\n";
  BOOST_REQUIRE(test.sample() == 0);

  test.tic();

  std::cout << "Sample: " << test.sample() << "\n";
  BOOST_REQUIRE(test.sample() == 2000);

  test.tic();

  std::cout << "Sample: " << test.sample() << "\n";
  BOOST_REQUIRE(test.sample() == 4000);

  test.tic();

  std::cout << "Sample: " << test.sample() << "\n";
  BOOST_REQUIRE(test.sample() == -10000);

}


