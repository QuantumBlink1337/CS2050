#include "lab6.h"
#include <limits.h>
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
    Returns NULL if malloc fails. 
*/
Node * initList() {
    Node * newList = malloc(sizeof(Node));
    // This seems redundant to me... if newList was null it'd just return NULL anyway...
    if (newList == NULL) {
        return NULL;
    }
    return newList;
}
/*
    Returns 0 if the list was NULL (generally an empty Linked List)
*/
int getSize(Node * list) {
    if (list == NULL) {
        return 0;
    }
    int i;
    for (i = 0; list->next != NULL; i++) {
        list = list->next;
    }
    return i;
}
/*
    Returns 1 if list is NULL, or if allocating a new node failed for whatever reason.
*/
int insertAtHead(Node **list, void *data) {
    if (list == NULL) {
        return 1;
    }
    Node * newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return 1;
    }
    newNode->data = data;
    newNode->next = *list;

    *list = newNode;
    return 0;
}
/*
    Returns NULL if list is NULL or if the list is empty. 
*/
void * removeFromHead(Node **list) {
    if (list == NULL || getSize(*list) <= 0) {
        return NULL;
    }
    Node * dereflist = *list;
    void * Object = dereflist->data;
    *list = dereflist->next;
    free(dereflist);
    return Object;
}
/*
    Does nothing if the double ptr list is NULL.
    Probably unnecessary?
*/
void freeList(Node **list) {
    if (list == NULL) {
        return;
    }
    Node * tmp;
    Node * derefList = *list;
    while (derefList->next != NULL) {
        tmp = derefList;
        derefList = derefList->next;
        free(tmp->data);
        free(tmp);
    }
    free(derefList);
    *list = NULL;
}

/*
    Returns NULL if the list is NULL.
*/
Car * getWithLeastMilesDriven(Node *list) {
    if (list == NULL) {
        return NULL;
    }
    float leastMilesDrivenValue = INT_MAX;
    Car * leastMilesDrivenStruct = NULL;
    int size = getSize(list);
    for (int i = 0; i < size; i++) {
        Car *car = ((Car*)list->data);
        if (getMilesDriven(car) < leastMilesDrivenValue) {
            leastMilesDrivenStruct = car;
            leastMilesDrivenValue = leastMilesDrivenStruct->milesDriven;
        }
        list = list->next;
    }
    return leastMilesDrivenStruct;
}
/*
    Does nothing if array is NULL.
*/
void printCars(Node *array) {
    if (array == NULL) {
        printf("Null Pointer\n");
        return;
    }
    int size = getSize(array);
    for (int i = 0; i < size; i++) {
        Car * car = array->data;
        printf("Index %d | VIN: %d | Miles Driven: %f | Number of Accidents: %d\n", i, getVin(car), getMilesDriven(car), getNumberOfAccidents(car));
        array = array->next;
    }
}