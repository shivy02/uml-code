/***********************************************
Author: Shivam Patel
Date: 9/19/21
Purpose: The purpose of this program is to practice using classes in c++
        and manipulate a point on a graph and diplay the point values using
        a class.
Sources of Help: None
Time Spent: 20 min
***********************************************/

/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: 9/19/21
Name: Shivam Patel
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Point {
	
	public:
		//constructors: init objects
		Point(); //default
        Point(int initX);
		Point(int initX, int initY); 

        //modifier functions
        void move(int moveX, int moveY); //moves the X value by moveX and Y value by moveY
        void rotate(void); //rotates the point 90 degrees

        //accessor functions
		int getX(void)const;
		int getY(void)const;
		
	private: 
		int X; //member variable X
        int Y; //member variable Y
};


int main(void) {

	Point point1(1, 2); //first point
    
    // rotate 4 times
    for(int i = 1; i < 5; i++) {
        point1.rotate();
        cout << "The point (1, 2) after being rotated " << i << " time(s) is: \n\n(" << point1.getX() << ", " << point1.getY() << ")\n\n";

    }

    Point point2(3, 4); //second point
    point2.move(1, 1);

    cout << "The point (3, 4) after being moved by (1, 1) is: \n\n(" << point2.getX() << ", " << point2.getY() << ")\n\n";

    Point point3(5, -4); //third point
    point3.move(-5, 4);

    cout << "The point (5, -4) after being moved by (-5, 4) is: \n\n(" << point3.getX() << ", " << point3.getY() << ")\n\n";
	
	return 0;
}

Point::Point() { //default constructor
	
	X = 0;
	Y = 0; //defaults to the origin
}

Point::Point(int initX) {

    X = initX;
    Y = 0; //defaults Y to 0 if no Y value is put in
}
	
Point::Point(int initX, int initY){ //initialize the point.
		
	X = initX;
	Y = initY;
}
	
int Point::getX(void)const { //accessor function
    return X;
}

int Point::getY(void)const { //accessor function 
    return Y;
}

void Point::move(int moveX, int moveY){
    X = X + moveX; //moves X by moveX
    Y = Y + moveY; //moves Y by moveY
}

void Point::rotate(void){

    int temp = X; //to rotate (x, y) 90 degrees you must apply (y, -x)
    X = Y;
    Y = temp; //swap values
    Y = Y * -1; //make Y negative

}
