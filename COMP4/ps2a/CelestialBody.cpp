/**
 * @file Celestialbody.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Universe.h"

CelestialBody::CelestialBody(double ix, double iy, double iXvelocity, double iYvelocity, double imass, std::string iFileName){
    x = ix;
    y = iy;
    xVelocity = iXvelocity;
    yVelocity = iYvelocity;
    mass = imass;
    fileName = iFileName;

    //create a sprite/texture
    sf::Image image;
    image.loadFromFile(fileName);

    thisTexture.loadFromImage(image);
    thisSprite.setTexture(thisTexture);

}

double CelestialBody::getx()const{
    return x;
}

double CelestialBody::gety()const{
    return y;
}

double CelestialBody::getXVelocity()const{
    return xVelocity;
}

double CelestialBody::getYVelocity()const{
    return yVelocity;
}

std::string CelestialBody::getFileName()const{
    return fileName;
}

double CelestialBody::getMass()const{
    return mass;
}

sf::Sprite CelestialBody::getSprite()const{
    return thisSprite;
}

void CelestialBody::setPos(double ix, double iy, double radius){
    //scale the positions according to the Universe size
    double tmpX = (ix / 2) + ((this->x / radius)/2) * ix;
    double tmpY = (iy / 2) + ((this->y / radius)/2) * iy;
    this->thisSprite.setPosition(tmpX, tmpY);
}

void CelestialBody::setXYVelocity(double ixVelocity, double iyVelocity){
    xVelocity = ixVelocity;
    yVelocity = iyVelocity;
}

void CelestialBody::setFileName(std::string iFileName){
    fileName = iFileName;
}

void CelestialBody::setMass(double iMass){
    mass = iMass;
}

const std::istream & operator >> (std::istream &in,  CelestialBody &body){

    //read in the data needed
    in >> body.x >> body.y >> body.xVelocity >> body.yVelocity >> body.mass >> body.fileName;

    return in;
}