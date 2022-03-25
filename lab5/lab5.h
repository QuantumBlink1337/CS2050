#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int vin;
	float milesDriven;
	int numberOfAccidents;
} Car;

void * createArray(size_t elementSize, int numElements);
int getSize(void *array);

int getVin(Car *car);
float getMilesDriven(Car *car);
int getNumberOfAccidents(Car *car);

void updateMilesDriven(Car *car, float milesToAdd);
void incrementNumberOfAccidents(Car *car);

Car * getCarByVIN(Car *array, int VIN);

Car * getWithMostMilesDriven(Car *array);

void printCars(Car *array);
void freeArray(void *array);
