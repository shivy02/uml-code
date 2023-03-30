#include<stdio.h>

enum schooldays{Mon = 1, Tue, Wed, Thur,Fri};

typedef enum schooldays Days;

/*
Make a function (include prototype) and definition; for a function called
preferred day which asks students for their prefer day 
and then uses a switch statment to print out the day;

Student record keeping
-FName (String -- multiple characters)
-Quiz1 - int
-Quiz2 - int
-Quiz3 - int
-Average - float

ANSWER - use C-Structures
A way for a programmer to be able to group attributes relating to one object/entity

Use C-struct to create an entity called date that stores year, month, day (all integers)
Use typedef to create a synonym called DATE;

Write a function called updateAverage that returns the
average for a particular instance of STUDENT that is passed to it.
*/


struct student{
	//member variables
	char* fName; //an array is collection of items of similar data type
	int Quiz1;
	int Quiz2;
	int Quiz3;
	float Average; 

};

typedef struct student STUDENT;


void preferredDay(void);
float updateAverage(STUDENT myStudent);
void printRecord(STUDENT myStudent);


int main (void){

//The data type here is "enum schooldays" which is similar to an integer
Days day1 = 18;

//struct variable declaration and initialization 
STUDENT Nathan = {"Nathan", 17, 20, 78, 0.0};
Nathan.Average = updateAverage(Nathan);

STUDENT Shivam = {.fName = "Shivam", .Quiz1 = 20, .Quiz2 = 17, .Quiz3 = 89, .Average = 0.0};
Shivam.Average = updateAverage(Shivam);
//Declare without initialization
STUDENT Patrick; 
//assign values
Patrick.fName = "Patrick";
Patrick.Quiz1 = 19;
Patrick.Quiz2 = 18;
Patrick.Quiz3 = 99;
Patrick.Average =  updateAverage(Patrick);

printRecord(Nathan);
printRecord(Shivam);
printRecord(Patrick);


return 0;
}
float updateAverage(STUDENT myStudent){
		
	return (float)(myStudent.Quiz1 + myStudent.Quiz2 + myStudent.Quiz3)/3;

}
void printRecord(STUDENT myStudent){

	printf("%s %d %d %d %.2f \n",myStudent.fName, myStudent.Quiz1, myStudent.Quiz2, myStudent.Quiz3, myStudent.Average);

	return;
}
