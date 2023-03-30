#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct MY_STRING{

  int size;
  int capacity;
  char* data;
  
}My_string;

MY_STRING my_string_init_default(void){

  My_string* string = (My_string*)malloc(sizeof(My_string));

  if(string == NULL){
  printf("NULL");
  return NULL;
  }

  string->size = 0;
  string->capacity = 7;
  string->data = (char*)malloc(sizeof(char) * string->capacity);

  if(string->data == NULL){
    free(string);
    exit(1);
  }
  
  return string;
}

void my_string_destroy(MY_STRING* phMy_string){

  My_string* my_string = (My_string*)*phMy_string;
  free(my_string->data);
  free(my_string);
  *phMy_string = NULL;

}

MY_STRING my_string_init_c_string(const char* c_string){

  int i = 0;
  while(c_string[i] != '\0'){
    i++;
  }
  int length = i;

  My_string* myString = (My_string*)malloc(sizeof(My_string));
  myString->data = (char*)malloc((sizeof(char) * length) + 1);

  myString->size = length;
  myString->capacity = length + 1;
  
  for(i = 0; i<length; i++){
    myString->data[i] = c_string[i];
  }
  //malloc for my string object
  //get and set the size
  //set the capacity to one greater
  
  return myString;
}

int my_string_get_capacity(MY_STRING hMy_string){
  
  My_string* pMy_string = (My_string*)hMy_string;
  return pMy_string->capacity;

}

int my_string_get_size(MY_STRING hMy_string){

  My_string* pMy_string = (My_string*)hMy_string;
  return pMy_string->size;

}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){
  
  My_string* pLeft_string = (My_string*)hLeft_string;
  My_string* pRight_string = (My_string*)hRight_string;
  int check = 0;
  if(pLeft_string->size < pRight_string->size){
    return -1;
  }
  else if(pRight_string->size < pLeft_string->size){
    return 1;
  }
  else if(pLeft_string->size == pRight_string->size){
    for(int i = 0; i <= pLeft_string->size; i++){
      if(pLeft_string->data[i] == pRight_string->data[i]){
        check++;
      }
      if(check == pLeft_string->size){
	return 0;
      }
    }
  }
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp){

  My_string* pString = (My_string*)hMy_string;
  char c;
  char* temp;
  int i = 0, j = 0;
  pString->size = 0;
  c = fgetc(fp);
  while (c != EOF && c != ' ' && c != '\n'){
    if (pString->size >= pString->capacity){
      temp = malloc(sizeof(char) * 2 * pString->capacity);
      if (temp == NULL){
	return FAILURE;
      }

      for (j = 0; j < pString->size; j++){
	temp[j] = pString->data[j];
      }

      free(pString->data);
      pString->data = temp;
      pString->capacity *= 2;

    }

    pString->data[i] = c;
    i++;
    pString->size++;
    c = fgetc(fp);
  }

  if (c == ' '){
    if (i != 0){
      ungetc(c, fp);
    }
  }

  if (pString->size == 0){
    return FAILURE;
  }

  return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp){

  My_string* pString = (My_string*)hMy_string;
  int i = 0;

  if (pString->size == 0){
    return FAILURE;
  }

  while (i < pString->size){
    fputc(pString->data[i], fp);
    i++;
  }

  return SUCCESS;

}
