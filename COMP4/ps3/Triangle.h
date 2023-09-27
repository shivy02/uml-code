/**
 * @file Triangle.h
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief Triangle Class
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Triangle: public sf::Drawable{

    public:
        Triangle(double iLength, int iDepth, sf::Vector2f base){
            left.x = base.x - iLength/2;
            left.y = base.y - iLength/2;

            right.x = base.x + iLength/2;
            right.y = base.y - iLength/2;


            bottom.x = base.x;
            bottom.y = base.y + iLength/2;

            _depth = iDepth;
            _length = iLength;
        }

        void setLength(double iLength);
        void setDepth(int iDepth);

        sf::Vector2f getLeft(){
            return left;
        }

        sf::Vector2f getRight(){
            return right;
        }

        sf::Vector2f getBottom(){
            return bottom;
        }

        double getLeftX(){
            return left.x;
        }

        double getRightX(){
            return right.x;
        }

        double getBottomX(){
            return bottom.x;
        }

        double getLeftY(){
            return left.y;
        }

        double getRightY(){
            return right.y;
        }

        double getBottomY(){
            return bottom.y;
        }
        
    private:

        sf::Vector2f left;
        sf::Vector2f right;
        sf::Vector2f bottom;
        double _length;
        int _depth;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};