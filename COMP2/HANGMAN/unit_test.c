#include <stdio.h>

#include "my_string.h"
#include "unit_test.h"


int main(int argc, char* argv[])
{
    int i = 0;
    int success_count = 0;
    int failure_count = 0;
    int number_of_functions = 0;
    char buffer[500];

    Status (*tests[])(char*, int) =
    {
        test_01__init,
		test_02__destroy,
		test_03__push_back,
		test_04__pop_back,

		test_05__check_size,
		test_06__check_capacity,
		test_07__concat_size,

		test_08__at_negative_index,
		test_09__at_greater_than_size,

		test_10__c_str_null_terminated,
		test_11__init_c_str_resize,

		test_12__compare_equal_length_a_z,
		test_13__compare_equal_length_z_a,
		test_14__compare_equal_length_A_Z,
		test_15__compare_equal_length_Z_A,

		test_16__compare_unequal_length_aardvark_zoo,
		test_17__compare_unequal_length_zoo_aardvark,
		test_18__compare_unequal_length_aardvark_Zoo,
		test_19__compare_unequal_length_zoo_Aardvark,

		test_20__compare_unequal_length_left_1_short,
		test_21__compare_unequal_length_right_1_short,

		test_22__extraction_createFile,
		test_23__extraction_readFile,
		test_24__extraction_deleteFile,
    };

    number_of_functions = sizeof(tests) / sizeof(tests[0]);
   
    for(i = 0; i < number_of_functions; i++)
    {
        if (tests[i](buffer, 500) == FAILURE)
        {
            printf("FAILED: Test %d\n", i);
            printf("\t%s\n", buffer);
            failure_count++;
        }
        else
        {
            printf("PASS: Test %d PASS\n", i);
            printf("\t%s\n", buffer);
            success_count++;
        }
    }
    
    printf("Total number of tests: %d\n", number_of_functions);
    printf("%d/%d Pass, %d/%d Failure\n", 
        success_count,
        number_of_functions, 
        failure_count, 
        number_of_functions);



    printf("\n\n\nPress ENTER to continue...");
    
    
    return 0;
}