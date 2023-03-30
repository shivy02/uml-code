#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
   int data;
   Node* next;
};

void createList(int x);

int main(void) {

createList(5);

}

void createList (int x) {
     Node *list = (Node*)malloc(sizeof(Node));
     list->data = x;
     printf("%d, ", list->data);
     if(x == 1){
          list->next = NULL;
          return;
     }
    list = list->next;
    
    createList(x-1);

}