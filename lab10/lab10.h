#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct BST BST;

// O(1)
BST * initBST();
// O(log(n))
int insertBST(BST *tree, int data);
// O(log(n))
int BSTContains(BST *tree, int data);
// O(n)
void freeTree(BST *tree);
// O(n)
void printInOrder(BST *tree);

// O(log(n))
int getMin(BST *tree);
