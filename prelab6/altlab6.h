#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct {
    void *Object;
    struct nodeStruct *next;
} Node;
typedef struct listStruct {
    Node * head;
    Node * tail;
    int size;
} List;

List * initList(int * error);
Node * createNode(void * Object, int* error);
List * insertAtHead(void * Object, List * list, int* error);
List * insertAtTail(void * Object, List * list, int * error);
void * getAtIndex(int index, List * list);
int getListLength(List * list);
List * freeList(List * list);