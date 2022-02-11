#include <stdio.h>
#include <stdlib.h>
void * createArray(int size, int data_type_size);
void freeArray(void * ptr);
int getSize(void * array);


int main(void) {
    double* array = NULL;
    array = createArray(18, sizeof(double));
    for (int i = 0; i < getSize(array); i++) {
        array[i] = (0.0) + i;
        printf("Element: %f\n", array[i]);
    }
    freeArray(array);
}
void * createArray(int size, int data_type_size) {
    int* array = malloc(sizeof(int) + (size*data_type_size));
    array[0] = size;
    array++;
    return (void*) array;
}
void freeArray(void * ptr) {
    free(((int*) ptr-1));
}
int getSize(void * array) {
    return *((int*) array-1);
}
