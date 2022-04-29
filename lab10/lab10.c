#include "lab10.h"

// suggested implementation
typedef struct BinaryTree BinaryTree;

struct BinaryTree {
	int data;
	BinaryTree *left;
	BinaryTree *right;
};

typedef struct BST{
	BinaryTree *root;
	int size;
}BST;


/*
 * Determines the smallest value of a BST. Returns minimum value, or -1 if there was some error.
 */
int recursiveMinimum(BinaryTree * root) { // NOLINT(misc-no-recursion)
    if (root != NULL) {
        if (root->left == NULL) {
            return root->data;
        }
        return recursiveMinimum(root->left);
    }
    return -1;
}
/*
 * Binary Search implemented with a BST. Returns 0 if the value doesn't exist, or 1 if it does.
 */
int binarySearch(BinaryTree * tree, int searchedValue) { // NOLINT(misc-no-recursion)
    int value;
    if (tree == NULL) {
        return 0;
    }

    value = tree->data;
    if (value == searchedValue) {
        return 1;
    }
    if (value > searchedValue) {
        return binarySearch(tree->left, searchedValue);
    }
    return binarySearch(tree->right, searchedValue);
}
/*
 * In order traversal of a binary tree. Takes a function pointer that returns nothing.
 * Used by: printInOrder
 */
void inOrder(BinaryTree * tree, void func(BinaryTree *)) { // NOLINT(misc-no-recursion)
    if (tree != NULL) {
        inOrder(tree->left, func);
        func(tree);
        inOrder(tree->right, func);
    }
}
/*
 * Post order traversal of a binary tree. Takes a function pointer that returns nothing.
 * Used by freeBST.
 */
void postOrder(BinaryTree * tree, void func(void *)) { // NOLINT(misc-no-recursion)
    if (tree != NULL) {
        postOrder(tree->right, func);
        postOrder(tree->left, func);
        func(tree);
    }
}
/*
 * Prints an integer from a binary tree node. Used in printInOrder.
 */
void printInteger(BinaryTree * binaryTree) {
    if (binaryTree == NULL) {
        return;
    }
    printf("%d\n", binaryTree->data);
}
/*
 * Generates and returns a new Binary Tree node. Returns NULL if malloc fails, otherwise returns the new tree.
 */
BinaryTree * newTree(int data) {
    BinaryTree * new_tree = malloc(sizeof(BinaryTree));
    if (new_tree == NULL) {
        return NULL;
    }
    new_tree->data = data;
    new_tree->left = NULL;
    new_tree->right = NULL;
    return new_tree;
}
/*
 * Generic recursive insertion for a BST. Returns the binary tree node and sets an error pointer.
 * Takes a comparison function that uses two integers. Sets error to 1 if:
 *      newTree returns NULL
 *      insertedData is already in the BST
 */
BinaryTree * insert(BinaryTree * tree, int insertedData, int compare(int, int), int * error) { // NOLINT(misc-no-recursion)
    if (tree == NULL) {
        BinaryTree * new_tree = newTree(insertedData);
        if (new_tree == NULL) {
            *error = 1;
            return tree;
        }
        *error = 0;
        return new_tree;
    }
    if (compare(insertedData, tree->data) < 0) {
        tree->left = insert(tree->left, insertedData, compare, error);
    }
    else if (compare(insertedData, tree->data) == 0) {
        *error = 1;
        return tree;
    }
    else {
        tree->right = insert(tree->right, insertedData, compare, error);
    }
    return tree;
}
/*
 * Integer comparison function. Returns sum of comparison.
 */
int compareIntegers(int a, int b) {
    // avoids integer overflow
    return (a > b) - (a < b);
}
/*
 * =====================Required header functions================
 */





/*
 * Generates a new binary tree. Returns new tree if possible, otherwise NULL if malloc fails.
 */
BST * initBST() {
    BST * binarySearchTree = malloc(sizeof(BST));
    if (binarySearchTree == NULL) {
        return NULL;
    }
    binarySearchTree->size = 0;
    binarySearchTree->root = NULL;
    return binarySearchTree;
}
/*
 * Insertion for BST. Uses generic insert. If error is 0, increases size then returns 0. Otherwise, returns 1 (nothing happened to the BST)
 */
int insertBST(BST *tree, int data) {
    int error = 0;
    tree->root = insert(tree->root, data, compareIntegers, &error);
    if (error == 0) {
        tree->size++;
        return 0;
    }
    return 1;
}
/*
 * Returns the result of binary search.
 */
int BSTContains(BST * tree, int data) {
    return binarySearch(tree->root, data);
}
/*
 * Frees a given BST. Utilizes postOrder traversal function.
 */
void freeTree(BST *tree) {
    postOrder(tree->root, free);
    free(tree);
}
/*
 * Returns the result of recursiveMinimum.
 */
int getMin(BST * tree) {
    return recursiveMinimum(tree->root);
}
/*
 * Uses inOrder traversal to print an integer.
 */
void printInOrder(BST * tree) {
    inOrder(tree->root, printInteger);
}