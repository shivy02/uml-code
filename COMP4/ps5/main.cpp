#include <iostream>
#include <SFML/System.hpp>
#include "edistance.h"

int main(int argc, const char* argv[]) {
    // set up clock
    sf::Clock clock;
    sf::Time t;

    // read in 2 strings
    std::string string1, string2;
    std::cin >> string1 >> string2;

    // EDistance object with 2 strings
    EDistance DNA(string1, string2);

    // Print out the edit distance
    std::cout << "Edit Distance = " << DNA.optDistance() << std::endl;

    // Print out the string alignment
    std::cout << DNA.alignment();

    // print out the time
    t = clock.getElapsedTime();
    std::cout << "\nExecution time is " << t.asSeconds() << " seconds\n";

    return 0;
}
