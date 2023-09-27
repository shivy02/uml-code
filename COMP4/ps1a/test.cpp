/**
 * @file test.cpp
 * @author Shivam Patel
 * @brief 
 * Course: Comp 4
 * Due Date: 2022-01-31
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}

// This test case tests our getter function and makes sure that the seed is getting updated after stepping.
// compared the value returned by getSeed (a string) with the value that should be returned to make sure the seed gets updated after each step
BOOST_AUTO_TEST_CASE(getterTest) {
  FibLFSR l2("1011011000110110");
  l2.step();
  BOOST_REQUIRE(l2.getSeed() == "0110110001101100");
  l2.step();
  BOOST_REQUIRE(l2.getSeed() == "1101100011011000");
  l2.step();
  BOOST_REQUIRE(l2.getSeed() == "1011000110110000");
}

// This tests my unstringify fucntion which converts a string passed in as either a '0' or  '1', to an integer 0 or 1.
// Unstrigify was used in my step function.
BOOST_AUTO_TEST_CASE(unstringifyTest) {
  char bit0 = '0';
  BOOST_REQUIRE(unstringify(bit0) == 0);
  char bit1 = '1';
  BOOST_REQUIRE(unstringify(bit1) == 1);
}
