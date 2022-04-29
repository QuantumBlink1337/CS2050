#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#include "lab10.h"
#include <time.h>

int main() {
    srand(time(NULL));
    int size = 10000;
    int copiedValue = 0;
    clock_t time;
    double timeInSeconds;
    BST * binarySearchTree = initBST();
    for (int i = 0; i < size; i++) {
        int value = (i % 2 == 0) ? -i * rand() % 1000 : i * rand() % 1000;
        insertBST(binarySearchTree, value);
        if (i == size-1) {
            copiedValue = value;
        }
    }
    time = clock();
    printInOrder(binarySearchTree);
    time = clock() - time;
    timeInSeconds = ((double)time / CLOCKS_PER_SEC);
    printf("Time taken to print all elements: %f\n",timeInSeconds);
    printf("\n\n\n");
    printf("Value to test: %d\n", copiedValue);
    printf("\n\n\n");
    printf("Minimum value: %d\n", getMin(binarySearchTree));
    time = clock();
    printf("Binary search test with known value: %d\n", BSTContains(binarySearchTree, copiedValue));
    time = clock()-time;
    timeInSeconds = ((double)time / CLOCKS_PER_SEC);
    printf("Time taken to search for element %d in BST: %f\n", copiedValue, timeInSeconds);
    time = clock();
    printf("Binary search test with unknown value: %d\n", BSTContains(binarySearchTree, 3));
    time = clock() - time;
    timeInSeconds = ((double)time / CLOCKS_PER_SEC);
    printf("Time taken to search for element not known to be in tree: %d in BST: %f\n", 3, timeInSeconds);

    freeTree(binarySearchTree);
}



#pragma clang diagnostic pop