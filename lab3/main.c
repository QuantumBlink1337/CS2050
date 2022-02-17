#include "lab3.h"

int main() {
    int size = 999;
    int * array = createCenteredArray(size);
    int startingIndex = ((size / 2))+1 - size;
    for (int i = startingIndex; i < startingIndex+size; i++) {
        printf("Accessing array\n");
        array[i] = i+50;
        printf("Array at %d: %d\n", i, array[i]);
    }
    int value = getAtIndex(array, size, startingIndex);
    printf("Value: %d\n", value);
    int average = averageUpperHalf(array, size);
    printf("Average: %d\n", average);
    freeCenteredArray(array, size);
}

