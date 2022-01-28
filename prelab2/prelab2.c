#include <stdio.h>
#include <stdlib.h>


// Returns the largest float that is less than query. If the query is smaller than the members of the array,
// then error becomes 1. 
float findLEQ(const float *array, const float query, int* error, int size) {
    float largestNumber = 0.0;
    for (int i =0; i < size; i++) {
        if (query > array[i] && array[i] > largestNumber) {
            largestNumber = array[i];
        }
        else {
            *error = 1;
        }
    }

    if (query > largestNumber) {
        *error = 0;
    }
        printf("%ld\n", sizeof(array));

    return largestNumber;
}
int main(void) {
    float array[] = {1.2, 2.4, 3.0, 3.555, -0.5, 10.2, 5000.2};
    printf("%ld\n", sizeof(array));
    int error = 0;
    float largestNumber = findLEQ(array, 5000.3, &error, sizeof(array)/sizeof(float));
    printf("%f\n%d\n", largestNumber, error);
}