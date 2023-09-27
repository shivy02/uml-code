/**********************************************************************
 *  ps3-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Your name: Shivam Patel

Hours to complete assignment: 9hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
This assignment used math and a ConvexShape from the sfml library in order
to draw a variation of the Serpinkski triangle. A class of vectors was used
to store the points and the points were then drawn. A recursive function fTree
was used to recursively call the math for the three triangles around the base
triangle and draw more.


 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
One data structure that was used was a Vector2f. This structure was used to store
the three points for the triangle (x, y). The points were then drawn using a ConvexShape.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
My fTree function consisted of a 3 vectors for the points which were then 
passed back into fTree in order to apply math to the points and then draw them.


 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
I learned how to use a vector of points and a ConvexShape in order to draw
points onto the screen, and how to use recursion in doing so.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Discord, Stack Overflow, sfml


/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
One problem that I encountered was that I was overcomplicating the code
by not having the recursion inside of fTree but in a seperate function.
This was fixed.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 N/A