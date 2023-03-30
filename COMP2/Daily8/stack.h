#pragma once
#ifndef stack_h
#define stack_h
#include "status.h"
#include <stdbool.h>

struct stack{
    int size;
    int capacity;
    char* data;
};

typedef struct stack Stack;

typedef void* STACK;

bool isLeft(char input);

bool isRight(char input);

bool isMatch(char input, char bracket);

bool test_case_is_valid(STACK pStack, int num);

STACK stack_init_default(void);

void stack_destroy(STACK* phStack);

void clear_keyboard_buffer(void);

Status stack_push(STACK hStack, char value);

Status stack_pop(STACK hStack);

char stack_top(STACK hStack, Status* pStatus);

int stack_size(STACK hStack);

int stack_size(STACK hStack);

bool stack_empty(STACK hStack);

#endif /* stack_h */
