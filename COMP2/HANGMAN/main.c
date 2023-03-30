#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
int main(int argc, char* argv[])
{

    MY_STRING word1 = NULL;
    word1 = my_string_init_c_string("The");
    MY_STRING key1 = NULL;
    key1 = my_string_init_c_string("---");

    MY_STRING word2 = NULL;
    word2 = my_string_init_c_string("Truck");
    MY_STRING key2 = NULL;
    key2 = my_string_init_c_string("-----");

    MY_STRING word3 = NULL;
    word3 = my_string_init_c_string("happy");
    MY_STRING key3 = NULL;
    key3 = my_string_init_c_string("--ppy");

    MY_STRING word4 = NULL;
    word4 = my_string_init_c_string("awesome");
    MY_STRING key4 = NULL;
    key4 = my_string_init_c_string("--e---e");
    

    char guess1 = 'T';
    char guess2 = 'r';
    char guess3 = 'h';
    char guess4 = 'z';

    MY_STRING new_key1 = NULL;
    new_key1 = my_string_init_c_string("---");

    MY_STRING new_key2 = NULL;
    new_key2 = my_string_init_c_string("-----");

    MY_STRING new_key3 = NULL;
    new_key3 = my_string_init_c_string("-----");

    MY_STRING new_key4 = NULL;
    new_key4 = my_string_init_c_string("-------");

    
    printf("\n\n");
    get_word_key_value(key1, new_key1, word1, guess1);
    printf("\n\n");
    get_word_key_value(key2, new_key2, word2, guess2);
    printf("\n\n");
    get_word_key_value(key3, new_key3, word3, guess3);
    printf("\n\n");
    get_word_key_value(key4, new_key4, word4, guess4);
    printf("\n\n");

    my_string_destroy(&word1);
    my_string_destroy(&word2);
    my_string_destroy(&word3);
    my_string_destroy(&word4);
    my_string_destroy(&key1);
    my_string_destroy(&key2);
    my_string_destroy(&key3);
    my_string_destroy(&key4);
    my_string_destroy(&new_key1);
    my_string_destroy(&new_key2);
    my_string_destroy(&new_key3);
    my_string_destroy(&new_key4);


    return 0;

}