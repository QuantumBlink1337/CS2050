#include <stdio.h>
#include <stdlib.h>
/*
    Returns a null pointer if: 
        size is less than 1 
        malloc() failed for some reason
*/
int * createIntArray(size_t size) { 
    if (size < 1) {
        return NULL;
    }
    int * array = malloc(sizeof(size_t) + (sizeof(int) * size));
    if (array == NULL) {
        return NULL;
    }
    array[0] = size; array++;
    return array;
}
/*
    Returns -1 if the given pointer is NULL.
*/
size_t getSize(int *array) {
    return array == NULL ? -1 : (size_t)array[-1];
}
/*
    Does nothing if the given pointer is NULL.
*/
void printArray(int *array) {
    if (array == NULL) {
        return;
    }
     for (int i = 0; i < getSize(array); i++) {
        printf("Element %d: %d | ", i, array[i]);
    }
    printf("\n");
}
/*
    Returns 1 if the given pointer is NULL.
*/
int sumOddIndices(int *array) {
    if (array == NULL) {
        return 1;
    }
    size_t size = getSize(array);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 != 0) {
            sum += array[i];
        }
    }
    return sum;
}
/*
    Frees an integer array.
*/
void freeArray(int *array) {
    free(array-1);
}
