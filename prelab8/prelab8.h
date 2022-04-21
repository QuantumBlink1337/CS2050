#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    void * Object;
    struct Node * next;
}Node;
typedef struct queueInfo {
    Node * rear;
    Node * head;
    int * size;
    int * error;
}QueueInfo;

typedef struct queue {
    QueueInfo * info;
}Queue;


int getQueueErrorCode(Queue);
Queue queueInit();
int enqueue(void *, Queue);
void * dequeue(Queue);
int getQueueSize(Queue);
void freeQueue(Queue);  