#include "prelab8.h"
#include <assert.h>

Node * createNode(void * Object, int * error) {
    Node *pointer;
    pointer = malloc(sizeof(Node));
    if (pointer == NULL) {
        *error = 1;
        return NULL;
    }
    pointer->Object = Object;
    pointer->next = NULL;
    *error = 0;
    return pointer;
}
int getQueueErrorCode(Queue queue) {
    return *(queue.info->error);
}
Queue queueInit() {
    Queue queue;
    int * queueError = malloc(sizeof(int));
    int * size = malloc(sizeof(int));
    QueueInfo * info = malloc(sizeof(QueueInfo));
    if (queueError && size && info) {
        info->rear = NULL;
        info->error = queueError;
        info->size = size;
        queue.info = info;
    }
    else {
        free(queueError);
        free(size);
        free(info);
    }
    return queue;
}
int enqueue(void * Object, Queue queue) {
    int error = 0;
    QueueInfo * info = queue.info;
    Node * newNode = createNode(Object, &error);
    if (error != 0) {
        *(info->error) = 1;
        return 1;
    }
    // sets newNode's next to the head of the list
    if (getQueueSize(queue) == 0) {
        info->rear = newNode;
        newNode->next = info->rear; 
    }
    else {
        newNode->next = info->rear->next;
        info->rear->next = newNode;
        info->rear = newNode;
    }
    *(info->error) = 0;
    int * size = info->size;
    *size += 1;
    return 0;
}
void * dequeue(Queue queue) {
    QueueInfo * info = queue.info;
    if (getQueueSize(queue) == 0) {
        *(info->error) = 1;
        return NULL;
    }
    Node * removedNode = info->rear->next;
    Node * data = removedNode->Object;
    info->rear->next = removedNode->next;
    *(info->size) -= 1;
    *(info->error) = 0;
    free(removedNode);
    return data;
}     
int getQueueSize(Queue queue) {
    return *(queue.info->size);
}
void freeQueue(Queue queue) {
    QueueInfo * info = queue.info;
    while (getQueueSize(queue) > 0) {
        free(dequeue(queue));
    }
    free(info->size);
    free(info->error);
    free(info);
}