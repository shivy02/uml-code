/***********************************************
Author: Shivam Patel
Date: 12/3/21
Purpose: The purpose of this program is to create permutations
         when given a list of strings. 
Sources of Help: Stack Overflow, cplusplus.com
Time Spent: 1.5hr
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
Date: 12/3/21
Name: Shivam Patel
*/

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string generate_permutations(list<string> &inputList);
void print_permutations(string permutations);

int main(int argc, char *argv[])
{
 list<string> inputList;
 string aLine, aString;

 // read in strings from stdin
 cout << "Enter strings, separated by a space:";
 getline(cin, aLine); //read a line from keyboard
 std::istringstream iss(aLine); //convert aLine to an istringstream obj

 //parse each string
 while(iss >> aString)
 {
 inputList.push_back(aString);
 }

 auto permutations = generate_permutations(inputList);

 // print permutations to stdout
 print_permutations(permutations);

 return 0;
}

string generate_permutations(list<string> &inputList){
    inputList.sort();
    int i = 0;
    int size = inputList.size();
    string thisString[size];

    for (list<string>::iterator it=inputList.begin(); it != inputList.end(); ++it){
        thisString[i]= *it;
        i++;
    }
    string temp = "";
    do {

    for (i = 0; i < size; i++){
    temp = temp + thisString[i] + " ";
    }

    temp = temp + "\n";
      
    } while (next_permutation(thisString,thisString+size)); 
    return temp;
}

void print_permutations(string permutations){

    cout<<permutations<<"\n";

}
