#include "lab0.h"


// Returns the count of how many times int query appears in the given array.

int countOccurrences(int size, int* array, int query) {
    int occurences = 0;
    for (int i = 0; i < size; i++) {
       if (*(array + i) == query) {
           occurences++;
       }
    }
    return occurences;
}
