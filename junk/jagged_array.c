#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateArray(int desiredSize);
int main(void) {
    srand(time(NULL));
    int* sizes = malloc(sizeof(int) * 4);
    for (int i = 0; i < 4; i++) {
        sizes[i] = (rand() % 10 + 1);
    }
    int** megaArray = malloc(sizeof(int*) * 4);
    for (int i = 0; i < 4; i++) {
        int * array = generateArray(sizes[i]);
        megaArray[i] = array;
    }
    for (int i = 0; i < 4; i++) {
        for (int l = 0; l < sizes[i]; l++) {
            printf("Element: %d |",megaArray[i][l]);
        }
        printf("\n");
        free(megaArray[i]);
    }
    free(megaArray);


}
int* generateArray(int desiredSize) {
    int *array = malloc(sizeof(int) * desiredSize);
    for (int i = 0; i < desiredSize; i++) {
        array[i] = 0;
    }
    return array;
}