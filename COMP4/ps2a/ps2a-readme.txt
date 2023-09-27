/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name:Shivam Patel
Hours to complete assignment: 13

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this assignment we were able to create a commandline app that reads 
values for celestial bodies from a text file into a CelestialBody Class.
After the values were stored, they area scaled to draw the bodies within 
the window to scale.



  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
One thing that was used in this assignment was a vector. The vector was used
in order to store pointers to Celestial bodies so that they can be
iterated through and outputted on to the screen. This also made it easier to
read in the values




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
One feature that I implemented was a function that scaled the values for
the position of the Celestial bodies.

double tmpX = (ix / 2) + ((this->x / radius)/2) * ix;
double tmpY = (iy / 2) + ((this->y / radius)/2) * iy;



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
classmates/discord

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
One problem that I encountered was that all of my celestial bodies printed
in the middle of the screen instead of next to eachother.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/