#include <stdio.h>
#include "bit_flags.h"

int main(int argc, char* argv[])
{
    int userInput;
    BIT_FLAGS test;

    printf("How long would you like the bit stream to be? ");
    scanf("%d", &userInput);

    test = bit_flags_init_number_of_bits(userInput);

    printf("Bit flags set: %d %d %d\n", bit_flags_set_flag(test, 3), bit_flags_set_flag(test, 5), bit_flags_set_flag(test, 0));
    printf("Bit flags size: %d\n", bit_flags_get_size(test));
    printf("Bit flags capacity: %d\n", bit_flags_get_capacity(test));
    printf("Bit flags check: %d %d\n\n", bit_flags_check_flag(test, 3), bit_flags_check_flag(test, 0));

    printf("Bit flags clear: %d %d %d\n", bit_flags_unset_flag(test, 3), bit_flags_unset_flag(test, 10), bit_flags_unset_flag(test, 5));
    printf("Bit flags size: %d\n", bit_flags_get_size(test));
    printf("Bit flags capacity: %d\n", bit_flags_get_capacity(test));
    printf("Bit flags check: %d %d\n\n", bit_flags_check_flag(test, 3), bit_flags_check_flag(test, 0));

    bit_flags_destroy(&test);

    return 0;
}