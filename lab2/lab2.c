#include "lab2.h"

// Sets *size to -1 if a problem was detected during function (e.g null pointers, invalid size, etc)
// Returns NULL if problem was detected
int * createIntArrayFromFile(FILE *file, int *size) {
    if (file == NULL) {
        *size = -1;
        return NULL;
    }
    char buffer[50];
    int length = 0;
    // Went with fgets because this seemed like a safer solution. Fscanf can break and cause the file pointer to get stuck :(
    fgets(buffer, 50, file);
    sscanf(buffer, "%d", &length);
    if (length <= 0) {
        *size = -1;
        return NULL;
    }
    *size = length;
    int* array = (int*) malloc((sizeof(int) * length));
    if (array == NULL) {
        *size = -1;
        return NULL;
    }
    for (int i = 0; i<length; i++) {
        int newInt = 0;
        fgets(buffer, 50, file);
        sscanf(buffer, "%d", &newInt);
        array[i] = newInt;
    }
    return array;
}
// Returns -1 in the event of failure (bad pointers, invalid size)
int lastAddressOf(int *array, int size, int **result, int element) {
    if (array == NULL || size <= 0 || result == NULL) {
        return -1;
    }
    int foundElement = 0;
    for (int i = 0; i<size; i++) {
        if (array[i] == element) {
            foundElement = 1;
            *result = array+i;
        }
    }
    return foundElement;
}
// Frees an integer array.
void freeArray(int *array) {
    free(array);
}
