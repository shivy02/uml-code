#include <stdio.h>
#include <stdlib.h>


int smallestNum(int array[], int size);
int smallestNumIndex(int array[], int size);
int largestSumOfArray(int array[], int size);

struct student {

	int age;
	float gpa;

};
typedef struct student STUDENT;

void readArrayItems(STUDENT class[], int size); 
void printArrayItems(STUDENT class[], int size);

int main(void){

  STUDENT myStudents[5];
  readArrayItems(myStudents,5);
  printArrayItems(myStudents,5);

  return 0;
}

int smallestNum(int array[], int size){
    //output variable and initializes iterative variable
    int output = array[0], i;

    //iterates through list and selects smallest int
    for(i = 1; i<size; i++){
        if(array[i]<output){
            output = array[i];
        }
    }

    //returns smallest int
    return output;
}

int smallestNumIndex(int array[], int size){
    //output variable and initializes iterative variable
    int output = 0, i;

    //iterates through list and selects the index of smallest int
    for(i = 1; i<size; i++){
        if(array[i]<array[output]){
            output = i;
        }
    }

    //returns smallest int index
    return output;
}

int largestSumOfArray(int array[], int size){
    //output variable and initializes iterative variable
    int output = array[0]+array[1], i;

    //iterates through list and selects the largest sum of adjacents
    for(i = 1; i<size -1; i++){
        if(output <array[i]+array[i+1]){
            output = array[i]+array[i+1];
        }
    }

    //returns largest sum
    return output;
}

void readArrayItems(STUDENT class[], int size){

	for (int i = 0; i<size; ++i){
		class[i].age = 20 + (rand()%10);
		class[i].gpa = (float)(rand()%5);
	
	}


}


void printArrayItems(STUDENT class[], int size){

	for (int i = 0; i<size; ++i){
		printf("Student %d is %d years old has %.2f gpa \n", i+1, class[i].age, class[i].gpa);
	
	}

	return;
}










