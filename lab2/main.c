#include "lab1.h"

int main() {
	FILE *file = fopen("numbers.txt", "r");

	if(!file) {
		// Unable to open the specified file
		return EXIT_FAILURE;
	}

	int size;

	if(fscanf(file, "%d", &size) != 1) {
		fclose(file);
		// Unable to read the array size from the file
		return EXIT_FAILURE;
	}

	int array[size];

	for(int i = 0; i < size; ++i) {
		fscanf(file, "%d", array + i);
	}
	float result = 0.0;

	printf("Error code: %d\n", avgEven(array, size, &result));
	printf("Result: %f\n", result);

    fclose(file);

    // END STARTER CODE


}
