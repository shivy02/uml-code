/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Shivam Patel


Hours to complete assignment: 1

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

This assignments objective was to set up a ring buffer with a data structure.
I was able to implement this buffer using a deque and it's helper functions
in order to resize and change elements of the deque.



/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

One key data structure that I used was a deque. This was important because
it allowed me to get all of the functionality of a ring buffer with a 
minimum time complexity.



/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

One feature that was implemented was the enqueue function which added an
element to the back of the buffer. This was done using the helper function
push_back() for a deque which automatically adds the given element to the
end of the buffer. In order to implement the peek function, the front() function
was used which returns the element that is at the top of the deque.



/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

I was able to complete the whole assignment completely. I think that the
whole thing is working because 6 test cases were written testing various aspects
of each of the functions that were to be implemented. All of these test cases
were passed.



/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/

Yes the implementation passes the unit tests because 6 tests were written
and all test cases passed. The test cases utilized all of the functions which
means that all aspects of the functions work.




/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/
All functions are run with a O(1) time complexity because all of the\
helper functions for a deque use O(1) time complexity.




/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Stack Overflow, STL Library


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
There weren't any serious problems that were encountered as the assignment
was fairly simple and short.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 N/A
