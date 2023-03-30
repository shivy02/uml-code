/**********************************************************************
Program: <Priority Queue>
Author: <Shivam Patel>
Date: <4/21/21>
Time spent: <2hr>
Purpose: The purpose of this program is to use a priority que to give items priority and remove them according to the priority.
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

struct pair
{
    int priority;
    int value;
};
typedef struct pair Pair;

struct priority_queue
{
    int size;
    int capacity;
    Pair* data;
    int front;
    int back;
};
typedef struct priority_queue Priority_queue;


PRIORITY_QUEUE priority_queue_init_default(void)
{
    Priority_queue* pPriority_queue;
    pPriority_queue = (Priority_queue*)malloc(sizeof(Priority_queue));
    if (pPriority_queue != NULL)
    {
        pPriority_queue->size = 0;
        pPriority_queue->capacity = 1;
        pPriority_queue->front = 0;
        pPriority_queue->back = 0;
        pPriority_queue->data = (Pair*)malloc(sizeof(Pair)*pPriority_queue->capacity);
        if (pPriority_queue->data == NULL)
        {
            free(pPriority_queue);
            pPriority_queue = NULL;
        }
    }
    return pPriority_queue;
}


Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
    Priority_queue* pPriority_queue = (Priority_queue*)hQueue;
    Pair* temp, tmp;
    int i;
    if (pPriority_queue->size >= pPriority_queue->capacity)
    {
        //not enough space make new queue
        temp = (Pair*)malloc(sizeof(Pair) * 2 * pPriority_queue->capacity);
        if (temp == NULL)
        {
            return FAILURE;
        }
        for (i = 0; i < pPriority_queue->size; i++)
        {
            temp[i] = pPriority_queue->data[i];

        }
        pPriority_queue->capacity *= 2;
        free(pPriority_queue->data);
        pPriority_queue->data = temp;
    }
    i = pPriority_queue->size;
    (pPriority_queue->data[i]).priority = priority_level;
    (pPriority_queue->data[i]).value = data_item;
    int parent_index;
    parent_index = (i - 1) / 2;
    while (i >= 1 && ((pPriority_queue->data[i]).priority > (pPriority_queue->data[parent_index]).priority))
    {

        tmp = pPriority_queue->data[parent_index];
        pPriority_queue->data[index_of_parent] = pPriority_queue->data[i];
        pPriority_queue->data[i] = tmp;
        i = parent_index
        parent_index = (i - 1) / 2;
    }
    pPriority_queue->size++;
    pPriority_queue->front = 0;
    pPriority_queue->back = pPriority_queue->size-1;
    return SUCCESS;
}


Status priority_queue_service(PRIORITY_QUEUE hQueue) {
    Priority_queue* pPriority_queue = (Priority_queue*)hQueue;
    Pair* temp;
    Pair* tmp;
    temp = (Pair*)malloc(sizeof(Pair));
    tmp = (Pair*)malloc(sizeof(Pair));
    if (priority_queue_is_empty(pPriority_queue))
    {
        return FAILURE;
    }


    *temp = pPriority_queue->data[0];
    pPriority_queue->data[0] = pPriority_queue->data[pPriority_queue->back];
    pPriority_queue->data[pPriority_queue->back] = *temp;
    pPriority_queue->size--;
    int i = 0;
    int flag = 1;
    int left_index = 2 * i + 1;
    int right_index = 2 * i + 2;
    while (left_index < pPriority_queue->size && flag==1)
    {
        flag = 0;
        if (right_index < pPriority_queue->size && (pPriority_queue->data[right_index]).priority>(pPriority_queue->data[left_index]).priority)
        {
            if ((pPriority_queue->data[right_index]).priority > (pPriority_queue->data[i]).priority)
            {
                *tmp = pPriority_queue->data[i];
                pPriority_queue->data[i] = pPriority_queue->data[right_index];
                pPriority_queue->data[right_index] = *tmp;
                i = right_index;
                left_index = 2 * i + 1;
                right_index = 2 * i + 2;
                flag = 1;

            }
        }
        else
        {
            if ((pPriority_queue->data[left_index]).priority > (pPriority_queue->data[i]).priority)
            {
                *tmp = pPriority_queue->data[i];
                pPriority_queue->data[i] = pPriority_queue->data[left_index];
                pPriority_queue->data[left_index] = *tmp;
                i = left_index;
                left_index = 2 * i + 1;
                right_index = 2 * i + 2;
                flag = 1;
            }
        }
    }

    pPriority_queue->back = pPriority_queue->size - 1;

    return SUCCESS;
}


int priority_queue_front(PRIORITY_QUEUE hQueue, Status* status)
{
    Priority_queue* pPriority_queue = (Priority_queue*)hQueue;
    if (priority_queue_is_empty(pPriority_queue))
    {
        if (status != NULL)
        {
            *status = FAILURE;
        }
        return 0;
    }
    if (status != NULL)
    {
        *status = SUCCESS;
    }
    return (pPriority_queue->data[pPriority_queue->front]).value;
}


Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
    Priority_queue* pPriority_queue = (Priority_queue*)hQueue;
    return (Boolean)(pPriority_queue->size == 0);
}


void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
    Priority_queue* pPriority_queue = (Priority_queue*)*phQueue;
    free(pPriority_queue->data);
    free(*phQueue);
    *phQueue = NULL;
    return;
}
