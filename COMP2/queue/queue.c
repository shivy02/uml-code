//the .c file is the implementation file

#include "queue.h"

//KNOWN data type

struct queue{
	int frontIndex; //this is index where we shall remove items
	int backIndex; //this is index where we shall add items
	int totalItems; // total items in the queue
	int capacity; //how many items our array/queue can hold
	int * data; //THE ARRAY where data is being kept.

};

typedef struct queue MY_QUEUE;
//functions

QUEUE queue_init_default(void){
	MY_QUEUE* pQueue = NULL; //pointer to an instance of a VECTOR

	pQueue = (MY_QUEUE*) malloc(sizeof(MY_QUEUE));

	if(pQueue == NULL){
		printf("No memory");
		exit(1);
	}
	pQueue->frontIndex = 0;
	pQueue->backIndex = 0;
	
	pQueue->capacity = 7;
	pQueue->totalItems = 0;

	pQueue->data = (int*) malloc(pQueue->capacity * sizeof(int));

	if(pQueue->data == NULL){
		printf("No memory for array");
		free(pQueue);
		pQueue = NULL;
	}
	
	return (QUEUE) pQueue;
}


Status queue_enqueue (QUEUE hQueue, int item); ///add items at the back
{

	MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type 

	int * newData = NULL// incase our queue array is full, then we can create new block
	
	//check whether it is full 
	if(pQueue->totalItems >= pQueue->capacity){
	//This code shall run if the queue array is full
	newData =  (int*) malloc(pQueue->capacity * 2 * sizeof(int));
	
	if{newData ==NULL}{
	
		return Failure;
	}
	
	for (int i =0; i<pQueue->capacity; i++){
	
		newData[i] = pQueue->data[(pQueue->frontIndex +i) % pQueue->capacity];
	
	
	
	}
	pQueue->frontIndex = 0;
	pQueue->backIndex = pQueue->capacity;
	pQueue->capacity *=2;
	
	}
	
	pQueue->data[pQueue->backIndex % pQueue->capacity] = item; 
	pQueue->backIndex++; 
	pQueue->totalItems++;
	
	return Success;
}



Status queue_dequeue(QUEUE hQueue); //remove items at the front
{
 MY_QUEUE* pQueue = (MY_QUEUE*) hQueue; //typecast to known type

 if (pQueue->totalItems != 0){

	pQueue->frontIndex++;
	pQueue->totalItems--;
	return Success;
}
 return Failure;

}

void printItems(QUEUE* phQueue){
	 MY_QUEUE* pQueue = (MY_QUEUE*) *phQueue;
		
	int i = 0;
	while (i < pQueue->totalItems){
		printf("%6d\n", pQueue->data[(pQueue->frontIndex + i) % pQueue->capacity]);
		i++;
	}
	return;
}


void queue_destroy(QUEUE* phQueue){

 MY_QUEUE* pQueue = (MY_QUEUE*) *phQueue;
 
 if(pQueue!=NULL){
 
 	free (pQueue->data);
 	free(pQueue);
 }
 *phQueue = NULL; 


}


#endif