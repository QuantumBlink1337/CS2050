#include <stdio.h>
#include <stdlib.h>

typedef struct listStruct {
    void *Object;
    struct listStruct *next;
} List;

List * initList(int * error);
List * createNode(void * Object, int* error);
List * insertAtHead(void * Object, List * list, int* error);
void * getAtIndex(int index, List * list);
int getListLength(List * list);
List * freeList(List * list);