#include "stack.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool test_case_is_valid(STACK pStack,int num)
{
    char input = '\0';
    char temp;
    Status stat;
    
    printf("Enter case %d: ", num);
    scanf("%c", &input);
    
    while(input != '\n')
    {
        
        if(isLeft(input))
        {
            stack_push(pStack, input);
        }
        
        if(isRight(input))
        {
            if(stack_size(pStack) == 0){
                clear_keyboard_buffer();
                return false;
            }
            
            temp = stack_top(pStack, &stat);
            
            if(isMatch(input, temp))
            {
                stack_pop(pStack);
            }
            else
            {
                clear_keyboard_buffer();
                return false;
            }
        }
        scanf("%c", &input);
    }
    
    return stack_size(pStack) == 0;
}

bool isLeft(char input){
    return input == '{' || input == '[' || input == '(';
}

bool isRight(char input){
    return input == '}' || input == ']' || input == ')';
}

bool isMatch(char input, char bracket){
    
    if(input == '}' && bracket == '{'){
        return true;
    }else if(input == ']' && bracket == '['){
        return true;
    }else if(input == ')' && bracket == '('){
        return true;
    }
    
    return false;
}


STACK stack_init_default(void)
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack != NULL) {
        pStack->capacity = 10;
        pStack->size = 0;
        pStack->data = (char*)malloc(sizeof(char) * pStack->capacity);
        if (pStack->data == NULL) {
            free(pStack);
            return NULL;
        }
    }
    return pStack;
}

void stack_destroy(STACK* phStack)
{
    Stack* pStack = (Stack*)*phStack;
    free(pStack->data);
    free(pStack);
    *phStack = NULL;
}

Status stack_push(STACK hStack, char value)
{
    Stack* pStack = (Stack*)hStack;

    if (pStack->size >= pStack->capacity) {
        char* temp = (char*)malloc(sizeof(char) * pStack->capacity * 2);
        if (temp == NULL) {
            return FAILURE;
        }
        for (int i = 0; i < pStack->size; i++) {
            temp[i] = pStack->data[i];
        }
        free(pStack->data);
        pStack->data = temp;
        pStack->capacity *= 2;
    }
    pStack->data[pStack->size] = value;
    pStack->size++;

    return SUCCESS;
}

Status stack_pop(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;

    if (stack_empty(hStack)) {
        return FAILURE;
    }
    pStack->size--;
    return SUCCESS;
}

char stack_top(STACK hStack, Status* pStatus)
{
    Stack* pStack = (Stack*)hStack;
    if (stack_empty(hStack)) {
        if (pStatus != NULL) {
            *pStatus = FAILURE;
        }
        return '?';
    }
    if (pStatus != NULL) {
        *pStatus = SUCCESS;
    }
    return pStack->data[pStack->size - 1];
}

int stack_size(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;
    return pStack->size;
}

bool stack_empty(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;
    return pStack->size <= 0;
}

void clear_keyboard_buffer(void)
{
    char c;
    int noc;
    noc = scanf("%c", &c);
    while(noc == 1 && c!= '\n')
    {
        noc = scanf("%c", &c);

    }
}
