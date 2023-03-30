#include<stdio.h>

/*
To work with arrays in functions -- we MUST pass the array and its size to a function
The content stored by name of the array is the address of the first element
When we pass an array into a function, we are passing the address of the first element

---POINTERS----
A pointer is a variable that stores addresses. 
The name of the array is a pointer that stores address of the first element. 
When we pass an array into a function , we are passing by address
*/
void printArray(int arr[], int size);
void readItems (int arr[], int size);
int  computeAverage(int arr[], int size);


int main (void){
	//A collection of items of similar data type; stored in a continguos block in memory
	
	//Declare an array
	int Age[5];
	
	
		//Declare and Initializing
	int myIntegers[5] = {45, 8, 9, 3, 4};
	int _myInts[] = {78, 45, 123, 45, 6};
	/*
	Determine size/length of array using the sizeof operator
	*/
	int len_myInts =  sizeof  _myInts/sizeof  _myInts[0];
	
	printf("Length of array Age is %d \n",len_myInts);
	
	
	//Assigning after declaration -- Important , MUST assign 1 by 1
	//By design array indices start at 0
	Age[0] = 9;
	Age[1] = 10;
	Age[2] = 4;
	Age[3] = 8;
	Age[4] = 11;
	
	
	readItems (Age, 5);
	
	printArray(Age, 5);
	
	//going past the array is known as off by one error
	
	//function call is down here. 
		printf("The average is: %d \n", computeAverage(Age, 5)); 
	

	return 0;

}
//Function goes here


void readItems (int arr[], int size){
	
	//populate array
	for (int i = 0; i<5; i++){
		printf("Enter an Age at index %d ", i);
		scanf("%d",&arr[i]);
	
	}

}


void printArray(int arr[], int size){
	//print out of the content
	//You need a repeating or iterating mechanism to do so
	printf("What is ARR all about %p \n", arr);
	
	for (int i = 0; i<size; i++){
		printf("Index: %d Age is: %d %p\n", i, arr[i], &arr[i]);
	
	}


}