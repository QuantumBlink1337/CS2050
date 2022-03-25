#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// Returns the largest float that is less than query. If the query is smaller than the members of the array,
// then error becomes 1. 
float findLEQ(const float *array, const float query, int* error, int size) {
    float largestNumber = 0;
    // This is necessary to do, otherwise this function's domain is only 0 to infinity. 
    if (query <= 0) {
        largestNumber = INT_MIN;
    }
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

    return largestNumber;
}
int main(void) {
    float array[] = {1.2, 2.4, 3.0, 3.555, -0.5, 10.2, 5000.2};
    int error = 0;
    float largestNumber = findLEQ(array, 15, &error, sizeof(array)/sizeof(float));
    printf("%f\n%d\n", largestNumber, error);
}