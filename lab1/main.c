#include "lab0.h"

int main() {
    srand(time(0));
    int arraySize = 10, query = 5;
    int data[arraySize];

    printf("The array to search:\n[");
    for(int i = 0; i < arraySize; ++i) {
        data[i] = (rand() % 10) + 1;
        printf("%d%s", data[i], (((i + 1) == arraySize) ? "]\n\n" : ", "));
    }

    int result = countOccurrences(arraySize, data, query);

    printf("The number %d occurs in the array %d time%s.\n", query, result, ((result != 1) ? "s" : ""));
}
