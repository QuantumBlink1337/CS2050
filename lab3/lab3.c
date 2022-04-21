#include "lab3.h"

/*
    Generates a centered array with the middle of the allocated size having an index of 0.
    Returns NULL if the size is not odd or if malloc fails. 
*/
int * createCenteredArray(int size) {
    if (size % 2 == 0) {
        return NULL;
    }
    int * array = malloc(sizeof(int) * size);
    if (array == NULL) {
        return NULL;
    }
    printf("Array created\n");
    int center = (size / 2)+1;
    printf("Center: %d\n", center);
    array += center;
    return array;
}
/*
    Returns 1 for error if the array pointer is null, size is not odd, or if the index specified is not a valid index for the array.
*/
int getAtIndex(int *array, int size, int index) {
    if (array == NULL || size % 2 == 0) {
        return 1;
    }
    int center = (size / 2) + 1;
    int startingIndex = center - size;
    for (int i = startingIndex; i < startingIndex+size; i++) {
        if (i == index) {
            return array[index];
        }
    }
    return 1;
}
/*
    Takes the average of the indexes starting at 0 in the context of a centered array.
*/
float averageUpperHalf(int *array, int size) {
    int center = (size / 2) + 1;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < center; i++) {
        sum += array[i];
        count++;
    }
    return (float) sum / count;
}
/*
    Frees a centered array. 
*/
void freeCenteredArray(int *array, int size) {
    int center = (size / 2) + 1;
    // reset pointer back to original state
    free(array - center);
    array = NULL;
}