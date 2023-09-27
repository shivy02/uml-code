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
#include <string>
#include <vector>
#include <utility>

class Universe {
 public:
        double getRadius()const;
        int getNumBodies()const;

        CelestialBody getPlanet(int i);

        friend const std::istream& operator>> (std::istream& in, Universe &thisUniverse) { // NOLINT
            in >> thisUniverse.numBodies >> thisUniverse.radius;
            double ix;
            double iy;
            double iMass;
            double iXVelocity;
            double iYVelocity;
            std::string iFileName;
            // read in values / set
            for(int i = 0; i < thisUniverse.numBodies; i++){ // NOLINT
                in >> ix >> iy >> iXVelocity >> iYVelocity >> iMass >> iFileName; // NOLINT
                thisUniverse.universe.push_back(std::shared_ptr<CelestialBody>(new CelestialBody(ix, iy, iXVelocity, iYVelocity, iMass, iFileName))); // NOLINT
            }

            return in;
        }

        double getx() {
            return x;
        }
        double gety() {
            return y;
        }

        void setx(double iX) {
            x = iX;
        }
        void sety(double iY) {
            y = iY;
        }

        friend std::ostream& operator<< (std::ostream &output, Universe &c);
        void step(double seconds);

        pair<double, double>calcForce(shared_ptr<CelestialBody> currentPlanet); // NOLINT

 private:
        std::vector<std::shared_ptr<CelestialBody>> universe;
        double radius;
        int numBodies;
        double x;
        double y;
};
