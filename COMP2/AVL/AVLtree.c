// AVL tree (Dynamic Balancing using AVL)
#include<stdio.h>
#include<stdlib.h>
 
 //forward declarations
 typedef struct Node tNode;
// An AVL tree node (we have just added a height attribute to a normal BST)
struct Node
{
    int key; //this could also be the data
    tNode *lChild;
    tNode *rChild;
    int nodeHeight; // recall height of node as number of edges to the farthest leaf.
};

//Function declarations
tNode* insertNodes(tNode* node, int key);
tNode* createNode(int key);
int getHeight(tNode *node);
int getBalancefactor(tNode* node);
int findmax(int x, int y);
tNode *rightRotation(tNode* nodey);
tNode* leftRotation(tNode* nodex);
void inorderTraversal(tNode* root);
void preorderTraversal(tNode* root);
 
/* Driver program*/
int main(int argc, char** argv){
  tNode* root = NULL;
  int key;

 
  root = insertNodes(root, 1);
  root = insertNodes(root, 2);
  root = insertNodes(root, 3);
  root = insertNodes(root, 7);
  root = insertNodes(root, 6);
  root = insertNodes(root, 5);

  printf("Preorder traversal : \n");
  preorderTraversal(root);
  printf("\n");

  printf("Inorder traversal (sorted tree): \n");
  inorderTraversal(root);
  printf("\n");

  return 0;
}


/*
insert key in subtree rootedwith node and returns new root of subtree.
*/
tNode* insertNodes(tNode* node, int key)
{
    /*BST insertion -usual technique , refer to notes */
    if (node == NULL)
        return(createNode(key));
 
    if (key < node->key)
        node->lChild  = insertNodes(node->lChild, key);
    else if (key > node->key)
        node->rChild = insertNodes(node->rChild, key);
    else // No duplicates in a BST
        return node;
    
    /* A update height of the node */
    node->nodeHeight = 1 + findmax(getHeight(node->lChild),getHeight(node->rChild));
 
    /* B. calculate balance factor (hLeft-hRigh)*/
    int balance = getBalancefactor(node);
 
    /*IF Node is unbalance, i.e balance is >1 or <-1, then it could be: */
 
    // 1. LEFT LEFT CASE (In this case, just rotate once on the RIGHT)
    if (balance > 1 && key < node->lChild->key)
        return rightRotation(node);
 
    // 2. RIGHT RIGHT CASE (In this case, just rotate once on the left)
    if (balance < -1 && key > node->rChild->key)
        return leftRotation(node);
 
    // 3. LEFT - RIGHT CASE ()
    if (balance > 1 && key > node->lChild->key)
    {
        node->lChild =  leftRotation(node->lChild); //To make it a LEFT LEFT CASE
        return rightRotation(node);
    }
 
    // 4. RIGHT - LEFT CASE
    if (balance < -1 && key < node->rChild->key)
    {
        node->rChild = rightRotation(node->rChild);//To make it a RIGHT RIGHT CASE
        return leftRotation(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
 
}
/* Create a new node with the given key and NULL lChild and rChild pointers. */
tNode* createNode(int key)
{
    tNode* node = (tNode*) malloc(sizeof(tNode));
    node->key   = key;
    node->lChild   = NULL;
    node->rChild  = NULL;
    node->nodeHeight = 1;  //assume that node is added at leaf
    return(node);
}
// A get method for height of the node.
int getHeight(tNode *node)
{
    if (node == NULL)
        return 0;
    return node->nodeHeight;
}

// Calculates and returns the balance factor
int getBalancefactor(tNode* node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->lChild) - getHeight(node->rChild);
}

// This should show a sorted out tree(recall from last class)
void inorderTraversal(tNode *root)
{
    if(root != NULL)
    {
        inorderTraversal(root->lChild);
        printf("%d ", root->key);
        inorderTraversal(root->rChild);
    }
}
// This should show tree with root first (recall from last class)
void preorderTraversal(tNode *root)
{
    if(root != NULL)
    {
         printf("%d ", root->key);
         preorderTraversal(root->lChild);
         preorderTraversal(root->rChild);
    }
}

 
// Rotate Right
tNode *rightRotation(tNode* nodey)
{
    tNode* nodex = nodey->lChild;
    tNode* T2 = nodex->rChild;
 
    // Rotate RIGHT
    nodex->rChild = nodey;
    nodey->lChild = T2;
 
    // Update heights
    nodey->nodeHeight = findmax(getHeight(nodey->lChild), getHeight(nodey->rChild))+1;
    nodex->nodeHeight = findmax(getHeight(nodex->lChild), getHeight(nodex->rChild))+1;
 
    // Return new root
    return nodex;
}
 
// rotate LEFT subtree rooted with a nodex
tNode* leftRotation(tNode* nodex)
{
    tNode* nodey = nodex->rChild;
    tNode* T2 = nodey->lChild;
 
    // Rotate LEFT
    nodey->lChild = nodex;
    nodex->rChild = T2;
 
    //  Update height of nodes
    nodex->nodeHeight = findmax(getHeight(nodex->lChild), getHeight(nodex->rChild))+1;
    nodey->nodeHeight = findmax(getHeight(nodey->lChild), getHeight(nodey->rChild))+1;
 
    // Return new root
    return nodey;
}

// return the largest value (used for height comparison)
int findmax(int x, int y)
{
    return (x > y)? x : y;
}