#include<stdio.h>//include preprocessor directive

int greaterThan(int a, int b); // function declaration OR function prototype
void printNumbers (int a, int b);
float compute(float a, int b);
void getNumber(void);

//variables whose scope is the lifetime of the program are called Global variables
int myNumber = 0;


//RLWM
int main (void){
//Main is a function that receives NOTHING but returns an Integer
//Curly braces -- demarcates a block of code specifying the work accomplished by the function
//Variables declared within the curly braces have a local scope to that block of code. 
//Return Keyword terminates the function and returns CONTROL Back to the function that called this function
//The variables declared within the parenthesis are called Formal Parameters
//Formal parameters have a local scope within the function where they are created.
int a = 9;
int b = 89;

//when we call/invoke a function and direct place values or variables-- this is called pass by value
printf("Result is: %d \n", greaterThan(a, b));

//the assignment operator (=) has right to left association
float result = compute ((float)a, b);
getNumber();

printf("Result is: %f \n", result);
printNumbers (a, b);


return 0;
}

//Function definitions -- define how the function will actually work
int greaterThan(int d, int c){

	//make some decisions - requires comparisons
	/*
	Relational operators
	> greater than
	>= greater than or equal to
	< less than
	<= less than or equal to
	== equality operator (is same)
	
	*/
	int result = 0;
	
	if (d > c){
		result = d;
	}
	result = c;
	
	return result;
}

// a function that does not return anything is called a NON-Value returning function
void printNumbers (int a, int b){
	a = 19;
	printf("Numbers are: %d %d\n", a, b);
	printf("The global value is: %d \n", myNumber);
	
	return; 

}
float compute(float a, int b){
	
	return b/a;

}

void getNumber(void){
	printf("Enter a number:  ");
	scanf("%d", &myNumber);
	return;
}