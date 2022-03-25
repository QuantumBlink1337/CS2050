#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

int main (void) {
    int * array = createIntArray(20);
    for (int i = 0; i < getSize(array); i++) {
        array[i] = i+5;
    }
    printArray(array);
    printf("Sum: %d\n", sumOddIndices(array));
    freeArray(array);
}
