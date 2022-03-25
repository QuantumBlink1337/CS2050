#include <stdio.h>
#include <stdlib.h>
#include "lab5.h"
/*
    Returns NULL if there's a problem with malloc.
*/
void * createArray(size_t elementSize, int numElements) {
    int * array = NULL;
    if ((array = malloc(sizeof(int) + (numElements * elementSize))) == NULL) {
        return NULL;
    }
    array[0] = numElements; 
    array++;
    return (void*) array;
}
int getSize(void *array) {
    return *((int*) array - 1);
}

/*
    All three of these getter methods will return -1 if car is NULL.
*/
int getVin(Car *car) {
    return car == NULL ? -1 : car->vin;
}
float getMilesDriven(Car *car) {
    return car == NULL ? -1 : car->milesDriven;
}
int getNumberOfAccidents(Car *car) {
    return car == NULL ? -1 : car->numberOfAccidents;
}
/*
    Does nothing if car is NULL. 
*/
void updateMilesDriven(Car *car, float milesToAdd) {
    if (car == NULL) {
        return;
    }
    car->milesDriven += milesToAdd;
}
void incrementNumberOfAccidents(Car *car) {
    if (car == NULL) {
        return;
    }
    car->numberOfAccidents++;
}

/*
    Returns NULL if there's no car struct that matches given VIN param or if the array is NULL.
*/
Car * getCarByVIN(Car *array, int VIN) {
    for (int i = 0; i < getSize(array) && array != NULL; i++) {
        if (array[i].vin == VIN) {
            return array + i;
        }
    }
    return NULL;
}   
/*
    Returns NULL if the car array is NULL.
*/
Car * getWithMostMilesDriven(Car *array) {
    if (array == NULL) {
        return NULL;
    }
    float mostMilesDrivenValue = 0.0;
    Car * mostMilesDrivenStruct = NULL;
    for (int i = 0; i < getSize(array); i++) {
        if (array[i].milesDriven > mostMilesDrivenValue) {
            mostMilesDrivenStruct = array + i;
            mostMilesDrivenValue = mostMilesDrivenStruct->milesDriven;
        }
    }
    return mostMilesDrivenStruct;
}
/*
    Does nothing if array is NULL.
*/
void printCars(Car *array) {
    if (array == NULL) {
        return;
    }
    for (int i = 0; i < getSize(array); i++) {
        Car *car = array + i;
        printf("Index %d | VIN: %d | Miles Driven: %f | Number of Accidents: %d\n", i, getVin(car), getMilesDriven(car), getNumberOfAccidents(car));
    }
}
void freeArray(void * ptr) {
    free(((int*) ptr-1));
}
