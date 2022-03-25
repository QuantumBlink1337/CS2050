#include <stdio.h>
#include <stdlib.h>

void * createArray(int size, int data_type_size) {
    int* array = (int*)malloc(sizeof(int) + (size*data_type_size));
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
