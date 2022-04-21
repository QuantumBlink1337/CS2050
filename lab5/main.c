#include <stdio.h>
#include <stdlib.h>
#include "lab5.h"
Car createCar(float VIN, int milesDriven, int numOfAccidents);
int main(void) {
    Car * array = createArray(sizeof(Car), 10);
    for (int i = 0; i < getSize(array); i++) {
        array[i] = createCar(((i+10000)), ((i*i*i)+25000)/4, i);
        printf("GET VIN TEST: %d\n", getVin(array + i));
        printf("GET MILES DRIVEN TEST: %f\n", getMilesDriven(array + i));
        printf("GET ACCIDENTS: %d\n", getNumberOfAccidents(array + i));
    }
    printCars(array);
    printf("Car VIN %d\n", getCarByVIN(array, 10000)->vin);
    printf("Car with most miles VIN: %d\n", getWithMostMilesDriven(array)->vin);
    printf("-------MODIFYING TESTS-------\n");
    for (int i = 0; i < getSize(array); i++) {
        Car* car = array + i;
        updateMilesDriven(car, i+1000);
        printf("NEW MILES: %f\n", getMilesDriven(car));
        incrementNumberOfAccidents(car);
        printf("NEW ACCIDENTS: %d\n", getNumberOfAccidents(car));
    }
    printCars(array);
    freeArray(array);
}
Car createCar(float VIN, int milesDriven, int numOfAccidents) {
    Car car = {VIN, milesDriven, numOfAccidents};
    return car;
}