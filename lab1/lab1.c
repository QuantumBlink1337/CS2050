#include "lab1.h"
// REQUIRED FUNCTION IMPLEMENTATIONS
int avgEven(int * array, int size, float * result) {
    // Checks to see if any required conditions at the beginning of the function are unusable.
    if (size <= 0 || array == NULL || result == NULL) {
        return 0;
    }
    int evenSum = 0;
    int foundEvenNumbers = 0;
    // Checks each element of the array for evenness and if so, sums it.
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            evenSum += array[i];
            foundEvenNumbers++;
        }
    }
    // If we didn't find any even numbers, then we need to return 0 to prevent unnecessary modification to the result pointer.
    // Luckily, modifying it at this stage would only modify it to nan, but this would be unnecessary. 
    if (foundEvenNumbers == 0) {
        return 0;
    }
    // Need to cast at least one member to a float otherwise we'd truncate our average result.
    *result = (float) evenSum / foundEvenNumbers;
    // No errors at this point. Return default value
    return foundEvenNumbers;

}
