#include "lab6.h"

Car createCar(float VIN, int milesDriven, int numOfAccidents);
int main(void) {
    Node * list = initList();
    for (int i = 0; i < 5; i++) {
        Car * car = malloc(sizeof(Car));
        *car = createCar(i, i, i);
        insertAtHead(&list, car);
    }
    printCars(list);
    //int size = getSize(list);
    // for (int i = 0; i < size; i++) {
    //     void * data = removeFromHead(&list);
    //     Car * car = (Car *)data;
    //     printf("VIN: %d\n", car->vin);
    //     free(data);
    // }
    printf("Least miles VIN: %d\n", getWithLeastMilesDriven(list)->vin);
    freeList(&list);
}
Car createCar(float VIN, int milesDriven, int numOfAccidents) {
    Car car = {VIN, milesDriven, numOfAccidents};
    return car;
}