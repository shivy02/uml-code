/**
 * @file TFractal.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief implementation of fTree
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Triangle.h"

void fTree(double L, int N, sf::RenderWindow &window, sf::Vector2f base);


int main (int argc, char *argv[]){

    double L = atof(argv[1]);
    int N = atof(argv[2]);

    
    sf::RenderWindow window(sf::VideoMode(L*4, L*4), "TFractal");
    sf::Vector2f base(window.getSize().x/2, window.getSize().y/2);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        fTree(L, N, window, base);
        window.display();
    }

    return 0;
}

void fTree(double L, int N, sf::RenderWindow &window, sf::Vector2f base){

    Triangle tri(L, N, base);
    window.draw(tri);

    if(N == 0){
        return;
    }
    
    const double tri_h = L/2 * 0.5 * sqrt(3);

    sf::Vector2f left(tri.getLeftX(), tri.getLeftY() - (tri_h/2));
    sf::Vector2f right(tri.getRightX() + (L/4), tri.getRightY() + (tri_h/2));
    sf::Vector2f bottom(tri.getBottomX() - (L/4), tri.getBottomY() + (tri_h/2));

    if(N > 1){
        fTree(L/2, N-1, window, left);
        fTree(L/2, N-1, window, right);
        fTree(L/2, N-1, window, bottom);
    }else{
        return;
    }
}
