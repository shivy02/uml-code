/***********************************************************
Author: Shivam Patel
Date: 03/04/21
Effort: 4 hours
Purpose: The purpose of this assignment is to practice making an
         opaque object wrapper.
 Interface proposal: A function that could be added to this is a 
                     function that resizes for you by reference.
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

typedef struct bit_flags {
   int size;
   int capacity;
   int *bit;

} Bit_flags;


BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits){

    Bit_flags* pBit_flags;

    if(number_of_bits > 0){
        pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));

        if(pBit_flags != NULL){
            pBit_flags->capacity = sizeof(int);
            pBit_flags->size = number_of_bits;
            pBit_flags->bit = (int*)malloc(sizeof(int));

            if(pBit_flags->bit != NULL){
               *pBit_flags->bit = 0;
           }
           else{
               printf("No memory.\n"); //check if memory is allocated
               pBit_flags = NULL;
           }
        }
    }
    else{
       printf("Number of bits can't be negative.\n"); //makes sure the number isn't negative
       pBit_flags = NULL;
   }

   return pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position){

    Bit_flags* phBit_flags = (Bit_flags*)hBit_flags;
    int bit = flag_position;
    int* temp;

    while(flag_position >= phBit_flags->capacity){

        phBit_flags->capacity *= 2;
        temp = (int*)malloc(sizeof(int) * phBit_flags->capacity); //make another array with double the capacity

        if(temp != NULL) {
            *temp = *(phBit_flags->bit);
            free(phBit_flags->bit); 
            phBit_flags->bit = temp; //reassign
        }
        else{
            printf("Failed to resize.\n");
            return FAILURE;
        }
    }

    flag_position /= phBit_flags->capacity;
    phBit_flags->bit[flag_position] |= 1U << (bit%phBit_flags->capacity);
    phBit_flags->size--;
    printf("Bit set successfully.\n");

    return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position){

    Bit_flags* phBit_flags = (Bit_flags*)hBit_flags;
    int bit = flag_position;
    int* temp;

    while(flag_position >= phBit_flags->capacity){
        phBit_flags->capacity *= 2;
        temp = (int*)malloc(sizeof(int) * phBit_flags->capacity);

        if(temp != NULL){
            *temp = *(phBit_flags->bit);
            free(phBit_flags->bit);
            phBit_flags->bit = temp;
        }
        else{
            printf("Failed to resize.\n");
            return FAILURE;
        }
    }

    flag_position /= phBit_flags->capacity;
    phBit_flags->bit[flag_position] &= ~(1 << (bit%phBit_flags->capacity)); //clear the bit
    phBit_flags->size++;
    printf("Bit cleared successfully\n");

    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position){

    Bit_flags* phBit_flags = (Bit_flags*)hBit_flags;
    int bit = flag_position;
    int set_bit = flag_position;

    if(flag_position < 0 || flag_position > phBit_flags->capacity){
        bit = -1;
    }
    else{
        flag_position /= phBit_flags->capacity;
        if((phBit_flags->bit[flag_position] >> set_bit) & 1U){
           bit = phBit_flags->bit[flag_position]; 
        }
    }
    return bit;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags){
   Bit_flags* phBit_flags = (Bit_flags*) hBit_flags;
   return phBit_flags->size; //return size
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags){
   Bit_flags* phBit_flags = (Bit_flags*) hBit_flags;
   return phBit_flags->capacity; //return capacity
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags){

    Bit_flags* pphBit_flags = (Bit_flags*) *phBit_flags;

    if(pphBit_flags != NULL){ //check if there is something to free
       free(pphBit_flags->bit);
       free(pphBit_flags);
   }
   pphBit_flags = NULL; //set back to NULL
   printf("Object was freed.\n");
}



