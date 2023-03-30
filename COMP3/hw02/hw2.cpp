/***********************************************
Author: Shivam Patel
Date: 9/15/21
Purpose: The purpose of this program is to practice reading from
        a file and performing an operation on the data recieved from it.
Sources of Help: http://www.cplusplus.com/reference/string/string/
Time Spent: 15 min
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
Date: 9/15/21
Name: Shivam Patele
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (void) {

    string dislike("dislike");
    string love("love");
    string word("");

    ifstream myFile;
    myFile.open("input.txt"); //open the file
    

    if(myFile.fail()){
        cout<< "Error in opening the file." << endl;     //check if the file opened
		exit(1);
    }
        
    while(myFile >> word){ //read a word at a time from the file

        if(word == dislike){
            word = love; //if the word is dislike then replace it with word
        }

        cout << word; //print the word

        if(!myFile.eof()){
            cout << ' '; //print a space if it is not the end of the file
        }

    }

    myFile.close();




    return 0;
}