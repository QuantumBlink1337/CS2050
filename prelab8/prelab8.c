#include "prelab8.h"
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
    return queue.error;
}
Queue queueInit() {
    Queue queue;
    int error = 0;
    Node * dummyNode = createNode(NULL, &error);
    queue.error = error;
    queue.rear->next = dummyNode;
    return queue;
}
int enqueue(void * Object, Queue queue) {
    int error = 0;
    Node * newNode = createNode(Object, &error);
    if (error != 0) {
        queue.error = 1;
        return 1;
    }
    
    queue.rear->next->next = newNode;


}
void * dequeue(Queue queue) {
    

}
int getQueueSize(Queue);
void freeQueue(Queue);  