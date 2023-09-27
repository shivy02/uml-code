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
#include <cmath>
#include <fstream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std; // NOLINT

const double G = 6.67e-11;

class CelestialBody: public sf::Drawable {
 public:
        CelestialBody();
        CelestialBody(double ix, double iy, double iXvelocity, double iYvelocity, double imass, std::string iFileName); // NOLINT
        double getx()const;
        double gety()const;
        double getXVelocity()const;
        double getYVelocity()const;
        double getMass()const;
        double getForceX()const;
        double getForceY()const;
        double getAccX()const;
        double getAccY()const;
        double getR()const;

        std::string getFileName()const;
        sf::Sprite getSprite()const;

        void setPos(double ix, double iy, double radius);
        void setXpos(double ix);
        void setYpos(double iy);
        void setXYVelocity(double ixVelocity, double iyVelocity);
        void setFileName(std::string iFileName);
        void setMass(double iMass);

        void setForceX(double iFx);
        void setForceY(double iFy);
        void setAccX(double iAx);
        void setAccY(double iAy);
        void setR(double iR);

        friend const std::istream & operator >> (std::istream &in,  CelestialBody &body); // NOLINT

 private:
        double x;
        double y;
        double xVelocity;
        double yVelocity;
        double mass;
        std::string fileName;
        sf::Sprite thisSprite;
        sf::Texture thisTexture;

        double Fy, Fx;
        double Ax, Ay;
        double r;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{ // NOLINT
        target.draw(thisSprite, states);
        }
};
