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

double Universe::getRadius()const {
    return radius;
}

int Universe::getNumBodies()const {
    return numBodies;
}

CelestialBody Universe::getPlanet(int i) {
    return *(universe[i]);
}

std::ostream& operator<< (std::ostream &output, Universe &c) {
            output << c.getNumBodies() << std::endl;
            output << c.getRadius() << std::endl;


            for (int i = 0; i < c.getNumBodies(); i++) {
                output << c.universe[i]->getx() <<"\t" << c.universe[i]->gety() <<"\t" << c.universe[i]->getXVelocity() <<"\t" << c.universe[i]->getYVelocity() <<"\t" << c.universe[i]->getMass() << "\t" << c.universe[i]->getFileName() << std::endl; // NOLINT
            }
            return output;
}

void Universe::step(double t) {
    vector<pair<double, double>> forcesVector;
    double aX = 0.0, aY = 0.0;
    double vX = 0.0, vY = 0.0;
    double pX = 0.0, pY = 0.0;

    for (int i = 0; i < numBodies; i++) {
    forcesVector.push_back(calcForce(universe[i]));
    }

    for (int k = 0; k < numBodies; k++) {
        aX = forcesVector[k].first/universe[k]->getMass();
        aY = forcesVector[k].second/universe[k]->getMass();

        vX = universe[k]->getXVelocity() + (t * aX);
        vY = universe[k]->getYVelocity() + (t * aY);

        pX = universe[k]->getx() + (t * vX);
        pY = universe[k]->gety() + (t * vY);

        universe[k]->setXYVelocity(vX, vY);


        universe[k]->setXpos(pX);
        universe[k]->setYpos(pY);

        universe[k]->setPos(x, y, radius);
    }
}

pair<double, double>Universe::calcForce(shared_ptr<CelestialBody> currentPlanet) { // NOLINT
    double deltaX = 0.0, deltaY = 0.0;
    double rad = 0.0, rad2 = 0.0;
    double f = 0.0;
    double fX = 0.0, fY = 0.0;

    for (int i = 0; i < numBodies; i++) {
        shared_ptr<CelestialBody> comparePlanet = universe[i];
        if (currentPlanet != comparePlanet) {
                deltaX = (comparePlanet->getx() - currentPlanet->getx());
                deltaY = (comparePlanet->gety() - currentPlanet->gety());
                rad = sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));
                rad2 = pow(deltaX, 2.0) + pow(deltaY, 2.0);
                f = (G * currentPlanet->getMass() * comparePlanet->getMass())/rad2; // NOLINT
                fX += (f * (deltaX/rad));
                fY += (f * (deltaY/rad));
        }
    }
    return pair<double, double> (fX, fY);
}

