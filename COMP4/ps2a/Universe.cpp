/**
 * @file Universe.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Universe.h"

// sf::Sprite Universe::operator[](int index){
//     CelestialBody *temp = this->universe.at(index);
//     return temp->getSprite();
// }

double Universe::getRadius()const{
    return radius;
}

int Universe::getNumBodies()const{
    return numBodies;
}

void Universe::size(int x, int y){
    for(int i=0; i < getNumBodies(); i++){
        this->universe[i]->setPos(x,y,radius);
    }
}

CelestialBody Universe::getPlanet(int i){
    return *(universe[i]);
}
