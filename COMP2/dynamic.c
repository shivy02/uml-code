#include <stdio.h>
#include <stdlib.h>

int find_max(int array[], int size);

int main( int arg, char *argv[]) {

    int n; //this will act as the size of the array
    int *array; //pointer for our array

    printf("\nPlease enter the size of the array: "); //gets the size of the array from the user
    scanf("%d", &n);
    array = (int *)malloc(sizeof(int) * n); //allocates enough memory for the size of the array that the user specified

    for(int i = 0; i < n; i++){
        array[i] = rand()%RAND_MAX; //rand function assigns values to each index
        printf("index value: %3d     value at index: %11d\n", i, array[i]);
        //This line just prints the array indexes and values of each index if needed
    }

    printf("\nThe index that holds the largest value is: %d\n\n", find_max(array, n)); //uses our find_max function to print the largest numbers index

    free(array); //remember to free up memory
    return 0;
}

int find_max(int array[], int size){ //takes two arguments (the array and the size of the array)

    int largestNum;
    int largestIndex = 0;
    int i = 0;

    largestNum = array[i];
    for(i = 0; i < size; i++){ //iterates through the array and keeps track of the largest number and index for that number
        if(array[i] > largestNum){ 
        largestNum = array[i]; //sets the largest number to the largestNum variable
        largestIndex = i;      //keeps track of the index for the largest number so far
        }
    }

    return largestIndex; //returns the index of the largest number of the array
}