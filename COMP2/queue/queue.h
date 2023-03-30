//the .h file is the API file. 

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef void* QUEUE;

typedef enum status{Failure, Success}Status;

//functions

QUEUE queue_init_default();

Status queue_enqueue (QUEUE hQueue, int item); ///add items at the back
Status queue_dequeue(QUEUE hQueue); //remove items at the front


void queue_destroy(QUEUE* phQueue);


#endif