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

#include "CircularBuffer.h"

// Constructor test
BOOST_AUTO_TEST_CASE(CONSTRUCTOR) {
  // test the constructor
  BOOST_REQUIRE_NO_THROW(CircularBuffer(50));

}


// Checks the size() method
BOOST_AUTO_TEST_CASE(SIZE) {
  CircularBuffer test(1);

  // size should be 0
  BOOST_REQUIRE(test.size() == 0);

  test.enqueue(5);

  // size should be 1
  BOOST_REQUIRE(test.size() == 1);

  test.dequeue();
  BOOST_REQUIRE(test.size() == 0);
}

// Checks the isFull() function
BOOST_AUTO_TEST_CASE(ISFULL) {
  CircularBuffer test(10);
  BOOST_REQUIRE(test.isFull() == false);

  CircularBuffer test2(2);
  test2.enqueue(5);
  test2.enqueue(10);
  BOOST_REQUIRE(test2.isFull() == true);
}

// Checks the isEmpty() method
BOOST_AUTO_TEST_CASE(ISEMPTY) {

  // False
  CircularBuffer test2(3);
  test2.enqueue(4);
  BOOST_REQUIRE(test2.isEmpty() == false);

  // True
  CircularBuffer test(5);
  BOOST_REQUIRE(test.isEmpty() == true);
}

// Test dequeue
BOOST_AUTO_TEST_CASE(DEQUEUE) {
  CircularBuffer test(4);

  test.enqueue(0);
  test.enqueue(1);
  test.enqueue(2);

  BOOST_REQUIRE(test.dequeue() == 0);
  BOOST_REQUIRE(test.dequeue() == 1);
  BOOST_REQUIRE(test.dequeue() == 2);

  // check runtime error
  BOOST_REQUIRE_THROW(test.dequeue(), std::runtime_error);
}

// Test enqueue
BOOST_AUTO_TEST_CASE(ENQUEUE) {

  CircularBuffer test(4);

  BOOST_REQUIRE_NO_THROW(test.enqueue(1));
  BOOST_REQUIRE_NO_THROW(test.enqueue(2));
  BOOST_REQUIRE_NO_THROW(test.enqueue(3));
  BOOST_REQUIRE_NO_THROW(test.enqueue(4));

  // check runtime error
  BOOST_REQUIRE_THROW(test.enqueue(6), std::runtime_error);
}


