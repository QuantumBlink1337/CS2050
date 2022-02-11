#include <stdio.h>
#include <stdlib.h>

int instancesOfIntegerGTE(int* array, int size, int query);


int main(int argc, char *argv[]) {
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    printf("Result: %d", instancesOfIntegerGTE(array, (sizeof(array) / sizeof(array[0])), 10));
}

int instancesOfIntegerGTE(int* array, int size, int query) {
    int occurences = 0;
    for (int i = 0; i < size; i++) {
        if (*(array + i) >= query) {
            occurences++;
        }
    }
    return occurences;
}

