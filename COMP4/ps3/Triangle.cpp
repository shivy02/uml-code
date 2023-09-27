/**
 * @file Triangle.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief class function defintions
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Triangle.h"

void Triangle::setLength(double iLength){
    _length = iLength;
}

void Triangle::setDepth(int iDepth){
    _depth = iDepth;
}

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    
    sf::ConvexShape triangle;

    triangle.setPointCount(3);
    triangle.setPoint(0, left);
    triangle.setPoint(1, right);
    triangle.setPoint(2, bottom);

    triangle.setFillColor(sf::Color::Blue);
    triangle.setOutlineColor(sf::Color::Yellow);
    triangle.setOutlineThickness(2);

    //draw convex shape after setting the points
    target.draw(triangle);
}