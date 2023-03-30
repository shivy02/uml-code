#ifndef UNIT_TEST_H
#define UNIT_TEST_H

Status test_01__init(char* buffer, int length);
Status test_02__destroy(char* buffer, int length);
Status test_03__push_back(char* buffer, int length);
Status test_04__pop_back(char* buffer, int length);

Status test_05__check_size(char* buffer, int length);
Status test_06__check_capacity(char* buffer, int length);
Status test_07__concat_size(char* buffer, int length);

Status test_08__at_negative_index(char* buffer, int length);
Status test_09__at_greater_than_size(char* buffer, int length);

Status test_10__c_str_null_terminated(char* buffer, int length);
Status test_11__init_c_str_resize(char* buffer, int length);

Status test_12__compare_equal_length_a_z(char* buffer, int length);
Status test_13__compare_equal_length_z_a(char* buffer, int length);
Status test_14__compare_equal_length_A_Z(char* buffer, int length);
Status test_15__compare_equal_length_Z_A(char* buffer, int length);

Status test_16__compare_unequal_length_aardvark_zoo(char* buffer, int length);
Status test_17__compare_unequal_length_zoo_aardvark(char* buffer, int length);
Status test_18__compare_unequal_length_aardvark_Zoo(char* buffer, int length);
Status test_19__compare_unequal_length_zoo_Aardvark(char* buffer, int length);

Status test_20__compare_unequal_length_left_1_short(char* buffer, int length);
Status test_21__compare_unequal_length_right_1_short(char* buffer, int length);

Status test_22__extraction_createFile(char* buffer, int length);
Status test_23__extraction_readFile(char* buffer, int length);
Status test_24__extraction_deleteFile(char* buffer, int length);

#endif
