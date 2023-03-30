/**********************************************************************
Program: Node reversal
Author: Shivam Patel
Date: 3/22
Time spent: 15 min
Purpose: The purpose of this program is to reverse a node and print it.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

Node* reverse(Node* pHead);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//call your function to reverse the list (should work for any list given the head node).
    head = reverse(head);

	//print the reversed list.
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

Node* reverse(Node* pHead){

    Node* prev = NULL;
    Node* current=  pHead;
    Node* next;

     while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
     }
    return prev;

}
