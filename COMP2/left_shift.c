/***********************************************************
Author: Shivam Patel
Date: 2/11/2020
Effort: 10 minutes
Purpose: The purpose of this program is to use the left shift
         operator in order to shift a number (1) over to the left
         by one bit until it is 0.
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    unsigned int x = 1;

    for(int i = 0; x != 0; ++i){

        printf("%d : %u\n", i , x);
        x = x<<1;
    }

    return 0;
}