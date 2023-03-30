#include<stdio.h>
#include<stdlib.h>

struct point{

	int x, y, z;
}; 

typedef struct point Point; 
//when we pass an array to a function, we perform pass by reference 

void updateLocation (Point array[], int size);

void print (Point* array, int size);
int main (void){

	Point location[5]; 
	printf("Name of array is %u \n", location);
    updateLocation(location, 5);
    
    Point * pLocate = location; 
    /*
    for (int i = 0; i< 5; ++i){
    printf("Address for index %d is %u which is same as %u \n", i, &location[i], (location + i));

    }
    */
    //Name of the array is POINTER  that keeps/holds/stores address of the first element
    //An array and a pointer are different types but can be used in a same manner. 
	int nums[5] = {45, 13,7, 88, 9};
	
	 for (int i = 0; i< 5; ++i){
    printf("value is %d and is similar to %d \n",nums[i], *(nums + i));

    }
	print(location, 5);
	
return 0;

}
void print (Point* array, int size){
	printf("Name of array in function is %u \n", array);
	for (int i = 0; i<size; i++){
		printf("%d %d %d \n", (array + i)->x,  
		(array + i)->y,
		(array + i)->z);
	}
 return; 

}

void updateLocation (Point* array, int size){
	printf("Name of array in function is %u \n", array);
	for (int i = 0; i<size; i++){
		(*(array + i)).x = rand () % 20; 
		(*(array + i)).y = rand () % 20; 
		(*(array + i)).z = rand () % 20; 
	}
 return; 

}