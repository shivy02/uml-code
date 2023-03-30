/***********************************************************
Author: Shivam Patel
Date: 2/25/2021
Effort: 40min
Purpose: The purpose of this is to get more practice with bitwise operators and shifts.
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);


int main(int argc, char* argv[]){

    unsigned int flag_holder[5] = { 0 };
    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);
    display_flags(flag_holder, 5);
    printf("\n\n");
    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);
    display_flags(flag_holder, 5);
    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position){

    int index = flag_position / 32;
    int bit_position = flag_position % 32;
    int value = 1 << bit_position;
    flag_holder[index] = flag_holder[index] | value;

}


void unset_flag(unsigned int flag_holder[], int flag_position){

    int index = flag_position / 32; 
    int bit_position = flag_position % 32; 
    int value = 1 << bit_position;
    value = ~ value; 
    flag_holder[index] = flag_holder[index] & value;
}


int check_flag(unsigned int flag_holder[], int flag_position){

    int index = flag_position / 32; 
    int bit_position = flag_position % 32; 
    int value = 1 << bit_position; 
    int bit = flag_holder[index] & value; 

    if (bit == 0){
        return 0;
    }
    else {
        return 1;
    }

}


void display_32_flags_as_array(unsigned int flag_holder){

    int i;

    for(i = 0; i < 32; i++){
        if(i % 4 == 0){
            printf(" ");
        }

        printf("%d", check_flag(&flag_holder, i));
    }

    printf("\n");
}


void display_flags(unsigned int flag_holder[], int size){

    int i ;
    for(i = 0; i < size; i++) {
        display_32_flags_as_array(flag_holder[i]);
    }
}
