/*
A C program for 3 tree traversals
Note; breadth first traversal to be covered with Heaps.
*/
#include <stdio.h>
#include <stdlib.h>

/* 
A binary tree node has data (or Key),
 pointer to left child and a pointer to right child 
*/
typedef struct Node tNode;

struct Node
{
     int key;
     tNode* lChild;
     tNode* rChild;
};

tNode* createNode(int key);
tNode* insertNode(tNode* node, int key);
void preorderTraversal(tNode* node);
void postorderTraversal(tNode* node);
void inorderTraversal(tNode* node);


/* Driver program to test above functions*/
int main()
{
     tNode *root  = NULL;

     for (int i =0; i<10;++i){
         int num = rand()%100;
         root = insertNode(root, num);

     } 
 
     printf("\nPreorder Traversal: \n");
     preorderTraversal(root);
 
     printf("\nInorder Traversal:\n");
     inorderTraversal(root);  
 
     printf("\nPostorder Traversal: \n");
     postorderTraversal(root);
    
    printf("\n");
     
     return 0;
}

/* Function to create a new nodes */
tNode* createNode(int key)
{
     tNode* node = (tNode*) malloc(sizeof(tNode));
     node->key = key;
     node->lChild = NULL;
     node->rChild = NULL;
 
     return(node);
}


tNode* insertNode(tNode* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(createNode(key));
 
    if (key < node->key)
        node->lChild  = insertNode(node->lChild, key);
    else if (key > node->key)
        node->rChild = insertNode(node->rChild, key);
    else // No duplicates in Binary Search Trees
        return node;
    
    return node;
}

/* 
Parent - Left Child - Right Child 
*/
void preorderTraversal(tNode* node)
{
     if (node == NULL)
          return;
    
     /* then print the data of parent */
     printf("%d ", node->key);  

     /* go through the left checking nodes */
     preorderTraversal(node->lChild);
 
     /*Go through the right checking nodes. */
     preorderTraversal(node->rChild);
}
 
/* Left Child - Right Child  - Parent */
void postorderTraversal(tNode* node)
{
     if (node == NULL)
        return;
 
     // call left subtree
     postorderTraversal(node->lChild);
 
     // call right subtree
     postorderTraversal(node->rChild);
 
     // Print the Node
     printf("%d ", node->key);
}
 
/* 
Left Child - Parent - Right Child 
*/
void inorderTraversal(tNode* node)
{
     if (node == NULL)
          return;
 
     /* go through the left checking nodes */
     inorderTraversal(node->lChild);
 
     /* then print the data of parent */
     printf("%d ", node->key);  
 
     /*Go through the right checking nodes. */
     inorderTraversal(node->rChild);
}
 
