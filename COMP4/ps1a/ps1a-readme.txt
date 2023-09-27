/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Shivam Patel
Hours to complete assignment: 5hrs
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 **********************************************************************/
 
This assignment required that we implement the FibLFSR class along with
the default constructor, a step function that extracts bits and xors them,
and a generate function that takes an integer k and runs step k number of times.
The generate function additionally creates a k bit binary number returned from 
stepping k number of times and converts that binary number to an integer and returns
it. I was able to successfully implement the class and both of these functions and 
also overload the insertion operator to display the register in its current state.




/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/

The representation that I used for the register was a string. The default
constructor initilizes a seed in a string and the step function extracts 
the bits that we need using the str.at() function from the string library. The
reason I did this was because it was easy for me to use strings since I was 
familiar with the functions and how they can be used to do something like this.
Converting from string to integer was simple with the implementation of a 
unstrigify function which I created in order to make the bits integers so operations
could be performed.

 
/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/

In my first boost test, I tested my getter function to make sure that the 
string that represents the seed is getting updated after each step. This was
done by initializing a seed and stepping it once and the using l2.getSeed()
and comparing the value returned by it to the value that it should be after a step.
I did this 3 times and compared the values. For the second test I tested my unstrigify
function. This was done by initilizing two characters as '0' and '1'. These characters
were inputted to my unstringify function and the value returned by the function was
compared with the integer 1 or 0 to make sure that the character was getting converted
to an integer.




/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Stack OverFlow
Mandar Kapadia

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
 
One problem that I encountered was in my makefile. I was having trouble linking
the boost library since I am on a Mac M1 architecture chip.

Another problem that I encountered was

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/