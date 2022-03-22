#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    void * Object;
    Node * next;
}Node;
typedef struct queue {
    Node * front,  * rear;
    int size;
    int error;
}Queue;



int getQueueErrorCode(Queue);
Queue queueInit();
int enqueue(void *, Queue);
void * dequeue(Queue);
int getQueueSize(Queue);
void freeQueue(Queue);  