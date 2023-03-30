#ifndef STACK_H
#define STACK_H

typedef void* STACK
typedef struct STACK
{
   char data;
   Stack *next;
}Stack;

bool test_case_is_valid(STACK pStack,int num);
bool isLeft(char input);
bool isRight(char input);
bool isMatch(char input, char bracket);
STACK stack_init_default(void);
void stack_destroy(STACK* phStack);
Status stack_push(STACK hStack, char value);
Status stack_pop(STACK hStack);
char stack_top(STACK hStack, Status* pStatus);
int stack_size(STACK hStack);
bool stack_empty(STACK hStack);
void clear_keyboard_buffer(void);
#endif

