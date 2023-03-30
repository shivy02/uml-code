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

void my_string_destroy(Item* item_handle)
{
    My_string* temp = (My_string*)*item_handle;

    if (temp != NULL)
    {
        free(temp->data);
        free(temp);
    }

    *item_handle = NULL;
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
  
    My_string* pString1 = (My_string*)hLeft_string;
    My_string* pString2 = (My_string*)hRight_string;

    int i = 0;
    int retVal = 0;
    int maxSize = (pString1->size > pString2->size) ? pString1->size : pString2->size;

    while (i < maxSize)
    {
        if (i > pString2->size) return 1;
        if (i > pString1->size) return -1;

        if (pString1->data[i] < pString2->data[i]) retVal = -1;
        else if (pString1->data[i] > pString2->data[i]) retVal = 1;

        if (retVal != 0) break;

        i++;
    }

    return retVal;

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

Status my_string_push_back(MY_STRING hMy_string, char item){

  My_string* pMy_string = (My_string*)hMy_string;
  int* temp;
  int i;

  if (pMy_string->size >= pMy_string->capacity){
    
    temp = (int*)malloc(sizeof(int) * 2 * pMy_string->capacity);

      if (temp == NULL){
        return FAILURE;
      }

      for (i = 0; i < pMy_string->size; i++){
        temp[i] = pMy_string->data[i];
      }

    free(pMy_string->data);
    pMy_string->data = temp;
    pMy_string->capacity *= 2;

  }

  pMy_string->data[pMy_string->size] = item;
  pMy_string->size++;

  return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string){

My_string* pMy_string = (My_string*)hMy_string;

if (pMy_string->size <= 0){
  return FAILURE;
}

pMy_string->size--;
return SUCCESS;

}

char* my_string_at(MY_STRING hMy_string, int index)
{
    My_string* pString = (My_string*)hMy_string;

    if (pString != NULL && index < pString->size && index >= 0)
        return &(pString->data[index]);

    return NULL;
}

char* my_string_c_str(MY_STRING hMy_string){

My_string* pMy_string = (My_string*)hMy_string;
char* temp;
int i;

if (pMy_string->data[pMy_string->size] != '\0'){
  temp = (char*)malloc(sizeof(char) * 2 * pMy_string->capacity);

  if (temp == NULL){
    return NULL;
  }

  for (i = 0; i < pMy_string->size; i++){
    temp[i] = pMy_string->data[i];
  }

  temp[i] = '\0';
  free(pMy_string->data);
  pMy_string->data = temp;
  pMy_string->capacity = pMy_string->size + 1;
}

return pMy_string->data;

}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend){

  My_string* pResult = (My_string*)hResult;
  My_string* pAppend = (My_string*)hAppend;
  char* temp;
  int i, size, capacity;

  if (pAppend->size == 0){
    return FAILURE;
  }

  else if (pResult->size == 0){

    for (i = 0; i < pAppend->size; i++){
      pResult->data[i] = pAppend->data[i];
    }

    pResult->size = pAppend->size;
    pResult->capacity = pResult->size + 1;

  }

  else{

    size = pResult->size + pAppend->size;
    capacity = size + 1;
    temp = (char*)malloc(sizeof(char) * capacity);

    if (temp == NULL){
    return FAILURE;
    }

    for (i = 0; i < pResult->size; i++){
      temp[i] = pResult->data[i];
    }

    for (i = 0; i < pAppend->size; i++){
    temp[pResult->size + i] = pAppend->data[i];
    }

    temp[pResult->size + i] = '\0';
    free(pResult->data);
    pResult->data = temp;
    pResult->capacity = capacity;
    pResult->size = size;
    }

  return SUCCESS;

}

Boolean my_string_empty(MY_STRING hMy_string){

  My_string* pMy_string = (My_string*)hMy_string;

  if (pMy_string->size == 0){
    return TRUE;
  }

  return FALSE;

}

char* c_str(MY_STRING hMy_string)
{
    My_string* pString = (My_string*)hMy_string;
    char* temp;
    int i;

    if (pString->capacity <= pString->size) // Not even big enough for NULL terminator so resize
    {
        pString->capacity *= 2;
        temp = (char*)malloc(sizeof(char) * pString->capacity);

        if (temp == NULL)
        {
            pString->capacity /= 2;
            return NULL;
        }

        for (i = 0; i < pString->size; i++)
        {
            temp[i] = pString->data[i];
        }

        free(pString->data);
        pString->data = temp;
    }

    //Simply make sure the string has a NULL terminator before showing it as a c-string.
    pString->data[pString->size] = '\0';

    return pString->data;
}

Status my_string_assignment(Item* left, Item right){

 int i;
    My_string* pLeft = (My_string*)*left;
    My_string* pRight = (My_string*)right;

    //if (pLeft == NULL) pLeft = my_string_init_default();
    if (pLeft == NULL) pLeft = (My_string*)my_string_init_default();
    if (pLeft == NULL) return FAILURE;
    if (pRight == NULL) return FAILURE;

    if (my_string_get_capacity((MY_STRING)pLeft) < pRight->size) //make sure we have room
    {
        free(pLeft->data);
        pLeft->capacity = pRight->size;
        pLeft->data = (char*)malloc(sizeof(char) * pLeft->capacity);
    }

    pLeft->size = pRight->size;  //adjust size

    for (i = 0; i < pLeft->size; i++) //copy data
        pLeft->data[i] = pRight->data[i];
        
    *left = pLeft;

    return SUCCESS;

}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
    My_string* pcurrent_word_family = (My_string*)current_word_family;
    My_string* pnew_key = (My_string*)new_key;
    My_string* pword = (My_string*)word;
    int i;

    i = 0;
    while (i < pword->size) {
        my_string_push_back(new_key, pcurrent_word_family->data[i]);
        i++;
    }

    i = 0;
    while (i < pword->size) {
        if (pword->data[i] == toupper(guess) || pword->data[i] == tolower(guess))
        {
            pnew_key->data[i] = tolower(pword->data[i]);
        }
        i++;
    }

    printf("Old Key: ");
    i = 0;
    while (i < pcurrent_word_family->size) {
        printf("%c", pcurrent_word_family->data[i]);
        i++;
    }
    printf ("\nGuess: %c", guess);
    printf("\nNew Key: ");
    i = 0;
    while (i < pnew_key->size) {
        printf("%c", pnew_key->data[i]);
        i++;
    }

    printf("\n");

    return SUCCESS;
}