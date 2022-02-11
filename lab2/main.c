#include "lab2.h"

int main() {
    FILE *fp;
    int size = 0;
    fp = fopen("numbers.txt", "r");
    int *array = createIntArrayFromFile(fp, &size);
    fclose(fp);
    // for (int i = 0; i < size; i++) {
    //     printf("%d: %d\n", (i+1), array[i]);
    // }
    int* result = NULL;
    printf("Last address success: %d\n" , lastAddressOf(array, size, &result, 74));
    printf("Last address: %p\n", result);

    freeArray(array);
}

