/**
 * @file Universe.h
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include "CelestialBody.h"
#include <memory>

class Universe {

    public:

        // sf::Sprite operator[](int index);

        double getRadius()const;

        int getNumBodies()const;

        void size(int x, int y);

        CelestialBody getPlanet(int i);

        friend const std::istream& operator>> (std::istream& in, Universe &thisUniverse){
            in >> thisUniverse.numBodies >> thisUniverse.radius;
            // CelestialBody b1;
            double ix;
            double iy;
            double iMass;
            double iXVelocity;
            double iYVelocity;
            std::string iFileName;
            //read in values / set
            for(int i = 0; i < thisUniverse.numBodies; i++){
                in >> ix >> iy >> iXVelocity >> iYVelocity >> iMass >> iFileName;
                thisUniverse.universe.push_back(std::shared_ptr<CelestialBody>(new CelestialBody(ix, iy, iXVelocity, iYVelocity, iMass, iFileName)));
                        // thisUniverse.universe.push_back(make_shared<CelestialBody>(b1);
            }

            return in;
        }

    private:

        std::vector<std::shared_ptr<CelestialBody>> universe;
        double radius;
        int numBodies;

};