/**
 * @file Celestialbody.h
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class CelestialBody: public sf::Drawable {

    public:
        CelestialBody();
        CelestialBody(double ix, double iy, double iXvelocity, double iYvelocity, double imass, std::string iFileName);
        double getx()const;
        double gety()const;
        double getXVelocity()const;
        double getYVelocity()const;
        double getMass()const;
        std::string getFileName()const;
        sf::Sprite getSprite()const;

        void setPos(double ix, double iy, double radius);
        void setXYVelocity(double ixVelocity, double iyVelocity);
        void setFileName(std::string iFileName);
        void setMass(double iMass);

        friend const std::istream & operator >> (std::istream &in,  CelestialBody &body);
        

    private:
        double x;
        double y;
        double xVelocity;
        double yVelocity;
        double mass;
        std::string fileName;
        sf::Sprite thisSprite;
        sf::Texture thisTexture;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(thisSprite, states);
        }
};