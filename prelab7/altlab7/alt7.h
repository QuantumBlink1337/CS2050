#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    void *Object;
    struct Node *next;
    struct Node *prev;
} Node;
typedef struct{ 
         Node *head; Node *tail;
} List; 
int insertAtHead(void*, List); 
int insertAtTail(void*, List);

void * removeHead(List);
void * removeTail(List);

List initList(int * error);
Node * createNode(void * Object, int* error);
void * getAtIndex(int index, List list);
int getListLength(List list);
void freeList(List list);