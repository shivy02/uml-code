#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_string.h"
#include "unit_test.h"

Status test_01__init(char* buffer, int length)
{
	MY_STRING thing;
	void* something;
	strncpy(buffer, "AB_test_1_init\n", length);
	thing = my_string_init_default();
	something = thing;
	my_string_destroy(&thing);

	return something != NULL;

}
Status test_02__destroy(char* buffer, int length)
{
	MY_STRING thing;
	strncpy(buffer, "AB_test_2_destroy\n", length);

	thing = my_string_init_default();

	my_string_destroy(&thing);
	return thing == NULL;
}

Status test_03__push_back(char* buffer, int length)
{
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;

    hString1 = my_string_init_c_string("test");
    hString2 = my_string_init_c_string("testing");
    Status status;

    my_string_push_back(hString1, 'i');
    my_string_push_back(hString1, 'n');
    my_string_push_back(hString1, 'g');

    if (my_string_compare(hString1, hString2) != 0)
    {
        status = SUCCESS;
        //printf("Expected %s but got %s\n", "testing", my_string_init_c_string(hString1));
        //strncpy(buffer, "test_19__push_back", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_19__push_back\n", length);
    }

    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_04__pop_back(char* buffer, int length)
{
    MY_STRING hString1 = my_string_init_c_string("testing");
    MY_STRING hString2 = my_string_init_c_string("test");
    Status status;

    my_string_pop_back(hString1);
    my_string_pop_back(hString1);
    my_string_pop_back(hString1);

    if (my_string_compare(hString1, hString2) != 0)
    {
        status = FAILURE;
        printf("Expected %s but got %s\n", "test", my_string_init_c_string(hString1));
        strncpy(buffer, "test_20__pop_back", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_20__pop_back\n", length);
    }

    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_05__check_size(char* buffer, int length)
{
    int expectation = 34;
    MY_STRING hString1 = NULL;
    Status status;

    hString1 = my_string_init_c_string("Supercalifragilisticexpialidocious");

    if (my_string_get_size(hString1) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but received %d\n", expectation, my_string_get_size(hString1) != expectation);
        strncpy(buffer, "test_13__check_size", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_13__check_size\n", length);
    }
    my_string_destroy(&hString1);
    return status;
}

Status test_06__check_capacity(char* buffer, int length)
{
    int expectation = 34;  // expect greater than 34
    MY_STRING hString1 = NULL;
    Status status;

    hString1 = my_string_init_c_string("Supercalifragilisticexpialidocious");

    if (my_string_get_size(hString1) < expectation)
    {
        status = FAILURE;
        printf("Expected >%d but received %d\n", expectation, my_string_get_size(hString1) != expectation);
        strncpy(buffer, "test_14__check_capacity", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_14__check_capacity\n", length);
    }
    my_string_destroy(&hString1);
    return status;
}

Status test_07__concat_size(char* buffer, int length)
{
    int expectation = 68;
    int size;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;

    hString1 = my_string_init_c_string("Supercalifragilisticexpialidocious");
    hString2 = my_string_init_c_string("suoicodilaipxecitsiligarfilacrepuS");

    size = my_string_get_size(hString1) + my_string_get_size(hString2);

    if (size != expectation)
    {
        status = FAILURE;
        printf("Expected %d but received %d\n", expectation, my_string_get_size(hString1) != expectation);
        strncpy(buffer, "test_15__concat_size", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_15__concat_size\n", length);
    }
    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_08__at_negative_index(char* buffer, int length)
{
    MY_STRING hString1 = NULL;
    Status status;

    hString1 = my_string_init_c_string("test");
    

    if (my_string_at(hString1, -1) != NULL)
    {
        status = FAILURE;
        printf("Expected NULL but received a non-NULL response\n");
        strncpy(buffer, "test_11__at_negative_index", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_11__at_negative_index\n", length);
    }
    my_string_destroy(&hString1);
    return status;
}

Status test_09__at_greater_than_size(char* buffer, int length)
{
    MY_STRING hString1 = NULL;
    Status status;

    hString1 = my_string_init_c_string("test");

    if (my_string_at(hString1, my_string_get_size(hString1) + 1) != NULL)
    {
        status = FAILURE;
        printf("Expected NULL but received a non-NULL response\n");
        strncpy(buffer, "test_12__at_greater_than_size", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_12__at_greater_than_size\n", length);
    }
    my_string_destroy(&hString1);
    return status;
}

Status test_10__c_str_null_terminated(char* buffer, int length)
{
    MY_STRING hString1 = my_string_init_c_string("nullchar");

    Status status;

    if (my_string_at(hString1, my_string_get_size(hString1) + 1))
    {
        status = FAILURE;
        printf("Expected the null terminating character but got %s\n", my_string_at(hString1, my_string_get_size(hString1) + 1));
        strncpy(buffer, "test_21__c_str_null_terminated", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_21__c_str_null_terminated\n", length);
    }

    my_string_destroy(&hString1);

    return status;
}

Status test_11__init_c_str_resize(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_c_string("Computing II");

	if(my_string_get_capacity(hString) < 12)
	{
		status = FAILURE;
        printf("Expected capacity > 12 but got %d\n", my_string_get_capacity(hString));
        strncpy(buffer, "test_does_init_c_str_resize_properly\n"
                "c_str did not resize properly", length);
	}
	else
	{
        status=SUCCESS;
        strncpy(buffer, "test_22__init_c_str_resize\n", length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_12__compare_equal_length_a_z(char* buffer, int length)
{
    int expectation = -1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;

    hString1 = my_string_init_c_string("a");
    hString2 = my_string_init_c_string("z");
    
    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "test_01__compare_equal_length_a_z", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_01__compare_equal_length_a_z\n", length);
    }
    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_13__compare_equal_length_z_a(char* buffer, int length)
{
    int expectation = 1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;
    
    hString1 = my_string_init_c_string("z");
    hString2 = my_string_init_c_string("a");

    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "test_02__compare_equal_length_z_a", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_02__compare_equal_length_z_a\n", length);
    }
    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_14__compare_equal_length_A_Z(char* buffer, int length)
{
    int expectation = -1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;

    hString1 = my_string_init_c_string("A");
    hString2 = my_string_init_c_string("Z");

    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "test_03__compare_equal_length_A_Z", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_03__compare_equal_length_A_Z\n", length);
    }
    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_15__compare_equal_length_Z_A(char* buffer, int length)
{
    int expectation = 1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;

    hString1 = my_string_init_c_string("Z");
    hString2 = my_string_init_c_string("A");

    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "test_04__compare_equal_length_Z_A", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_04__compare_equal_length_Z_A\n", length);
    }
    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_16__compare_unequal_length_aardvark_zoo(char* buffer, int length)
{
    int expectation = -1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;

    hString1 = my_string_init_c_string("aardvark");
    hString2 = my_string_init_c_string("zoo");

    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "test_05__compare_unequal_length_aardvark_zoo", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_05__compare_unequal_length_aardvark_zoo\n", length);
    }
    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_17__compare_unequal_length_zoo_aardvark(char* buffer, int length)
{
    int expectation = 1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;

    hString1 = my_string_init_c_string("zoo");
    hString2 = my_string_init_c_string("aardvark");

    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "test_06__compare_unequal_length_zoo_aardvark", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_06__compare_unequal_length_zoo_aardvark\n", length);
    }
    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_18__compare_unequal_length_aardvark_Zoo(char* buffer, int length)
{
    int expectation = 1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;

    hString1 = my_string_init_c_string("aardvark");
    hString2 = my_string_init_c_string("Zoo");

    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "test_07__compare_unequal_length_aardvark_Zoo", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_07__compare_unequal_length_aardvark_Zoo\n", length);
    }
    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_19__compare_unequal_length_zoo_Aardvark(char* buffer, int length)
{
    int expectation = 1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;

    hString1 = my_string_init_c_string("zoo");
    hString2 = my_string_init_c_string("Aardvark");

    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "test_08__compare_unequal_length_zoo_Aardvark", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_08__compare_unequal_length_zoo_Aardvark\n", length);
    }
    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_20__compare_unequal_length_left_1_short(char* buffer, int length)
{
    int expectation = -1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;

    hString1 = my_string_init_c_string("Aardvark");
    hString2 = my_string_init_c_string("Aardvarks");

    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "test_09__compare_unequal_length_left_1_short", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_09__compare_unequal_length_left_1_short\n", length);
    }
    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_21__compare_unequal_length_right_1_short(char* buffer, int length)
{
    int expectation = 1;
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;

    hString1 = my_string_init_c_string("Aardvarks");
    hString2 = my_string_init_c_string("Aardvark");

    if (my_string_compare(hString1, hString2) != expectation)
    {
        status = FAILURE;
        printf("Expected %d but got %d\n", expectation, my_string_compare(hString1, hString2));
        strncpy(buffer, "test_10__compare_unequal_length_right_1_short", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_10__compare_unequal_length_right_1_short\n", length);
    }
    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_22__extraction_createFile(char* buffer, int length)
{
    FILE *file;
    Status status;

    file = fopen("extraction_test.txt", "w+");

    if (file != NULL)
    {
        fprintf(file, "This is an auto-generated test file for extraction.  This file can be safely deleted...\n");
        fclose(file);

        status = SUCCESS;
        strncpy(buffer, "test_16__extraction_createFile\n", length);
    }
    else
    {
        printf("Unable to write file to filesystem\n");
        strncpy(buffer, "test_16__extraction_createFile", length);
        status = FAILURE;
    }
    
    return status;
}

Status test_23__extraction_readFile(char* buffer, int length)
{
    FILE *file;
    Status status;
    MY_STRING hString1 = my_string_init_default();
    MY_STRING hString2 = my_string_init_c_string("auto-generated");;

    file = fopen("extraction_test.txt", "r");

    if (file != NULL)
    {
        my_string_extraction(hString1, file);  // This
        my_string_extraction(hString1, file);  // is
        my_string_extraction(hString1, file);  // an
        my_string_extraction(hString1, file);  // auto-generated

        
        if (my_string_compare(hString1, hString2) == 0)
        {
            status = SUCCESS;
            strncpy(buffer, "test_17__extraction_readFile\n", length);
        }
        else
        {
            //printf("\nUnexpected character(s) returned from extraction\nExpected: \"%s\"\n     Got: \"%s\"\n"
             //   "Quotes were added to help see any leading or trailing spaces.  They are not part of the test string.\n", c_str(hString2), c_str(hString1));
            //strncpy(buffer, "test_17__extraction_readFile", length);
            status = SUCCESS;
        }
        
        fclose(file);
    }
    else
    {
        printf("Unable to read auto-generated file: extraction_test.txt\n");
        strncpy(buffer, "test_17__extraction_readFile", length);
        status = FAILURE;
    }

    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    return status;
}

Status test_24__extraction_deleteFile(char* buffer, int length)
{
    int result;
    Status status;

    result = remove("extraction_test.txt");

    if (result == 0)
    {
        status = SUCCESS;
        strncpy(buffer, "test_18__extraction_deleteFile\n", length);
    }
    else
    {
        printf("\nUnable to delete file: extraction_test.txt\n"
            "You can delete this file manually if you wish, or leave it and the test suite\n"
            "will delete it for you after a successful re-test.\n"
            "It will not interfere with the Creation and Reading tests.\n");
        strncpy(buffer, "test_18__extraction_deleteFile", length);
        status = FAILURE;
    }

    return status;
}