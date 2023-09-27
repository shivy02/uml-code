/**
 * @file test.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "RandWriter.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

// testing constructor
BOOST_AUTO_TEST_CASE(construct) {
    BOOST_REQUIRE_NO_THROW(RandWriter("gagggagaggcgagaaa", 2));
}

// testing orderK
BOOST_AUTO_TEST_CASE(orderK) {
    RandWriter model0("gagggagaggcgagaaa", 0);
    RandWriter model1("gagggagaggcgagaaa", 1);
    RandWriter model2("gagggagaggcgagaaa", 2);
    BOOST_REQUIRE(model0.order() == 0);
    BOOST_REQUIRE(model1.order() == 1);
    BOOST_REQUIRE(model2.order() == 2);
}

// testing single freq
BOOST_AUTO_TEST_CASE(Sfreq) {
    RandWriter model("gagggagaggcgagaaa", 1);
    BOOST_REQUIRE_THROW(model.freq(""), std::runtime_error);
    BOOST_REQUIRE_THROW(model.freq("xx"), std::runtime_error);

    BOOST_REQUIRE(model.freq("a") == 7);
    BOOST_REQUIRE(model.freq("g") == 9);
    BOOST_REQUIRE(model.freq("c") == 1);
}

// testing double freq
BOOST_AUTO_TEST_CASE(Dfreq) {
    RandWriter model("gagggagaggcgagaaa", 1);
    BOOST_REQUIRE(model.freq("a", 'a') == 2);
    BOOST_REQUIRE(model.freq("a", 'c') == 0);
    BOOST_REQUIRE(model.freq("a", 'g') == 5);

    BOOST_REQUIRE(model.freq("c", 'a') == 0);
    BOOST_REQUIRE(model.freq("c", 'c') == 0);
    BOOST_REQUIRE(model.freq("c", 'g') == 1);

    BOOST_REQUIRE(model.freq("g", 'a') == 5);
    BOOST_REQUIRE(model.freq("g", 'c') == 1);
    BOOST_REQUIRE(model.freq("g", 'g') == 3);
}

// testing kRand
BOOST_AUTO_TEST_CASE(kRand) {
    RandWriter model("gagggagaggcgagaaa", 1);
    BOOST_REQUIRE_NO_THROW(model.randk("a"));
    BOOST_REQUIRE_NO_THROW(model.randk("c"));
    BOOST_REQUIRE_NO_THROW(model.randk("g"));

    BOOST_REQUIRE_THROW(model.randk("x"), std::runtime_error);
    BOOST_REQUIRE_THROW(model.randk("xx"), std::runtime_error);
}
