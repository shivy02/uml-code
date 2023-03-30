#include<stdio.h>

//A pointer is a VARIABLE that STORES/contains/holds an address. 

//A Variable is named location in memory.

/* 
A pointer is a variable (named location in memory) that 
stores /contains an address (a location in memory)
 */


int main (void){

double x; // x is a variable that STORES a value of type double.
x = 9.56;

printf("Value stored at x is %.2lf \n", x);
printf("Address of x is %p \n", &x);

//the & (ampersand) is called address operator or Reference operator

//POINTERS

double * ptrX; // here datatype refers to the type of data kept at the address being referenced/held.

ptrX = &x; 

printf("Value stored at ptrX is %p \n", ptrX);
printf("Address of ptrX is %p \n", &ptrX);
printf("What is number of bytes reserved for ptrX %d \n", sizeof (ptrX));

double **Address_ptrX = &ptrX;

printf("Value stored at Address_ptrX is %p \n", Address_ptrX);
printf("Address of Address_ptrX is %p \n", &Address_ptrX);


printf("The value of x as given by ptrX is %.2lf\n", *ptrX);
//the * (asterisk) used in this way is called a dereference operator

*ptrX = 3.45;

printf("Value stored at x is %.2lf \n", x);

**Address_ptrX = 5.99 + 0.01;

printf("Value stored at x is %.2lf \n", x);

//declare and initiliase  -- what kind of values can we use to assign a pointer variable
int p; 

int *pX = &p;// assign an address of a variable. 
int *pXX = NULL;// points to no address -- pointer to nothing 
int *pXXX = 0; //the only numerical value that you can assign to a pointer

//We can make generic pointers -- pointers that do not specify data type of the address we are keeping/holding
void* myPointer; // can keep an address of anything 

myPointer = &x;

printf("The value of x as given by myPointer is %.2lf\n", (*(double*)myPointer));





return 0;

}