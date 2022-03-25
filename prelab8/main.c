#include "prelab8.h"

void printLinkedList(Queue queue);
int main(void) {
    Queue queue = queueInit();
    for (int i = 0; i < 30; i++) {
        int * j = malloc(sizeof(int));
        *j = i;
        assert(enqueue(j, queue) != 1);
    }
    printf("Size: %d\n", getQueueSize(queue));
    printLinkedList(queue);
    for (int i = 0; i < 2; i++) {
        free(dequeue(queue));
    }
    printLinkedList(queue);
    freeQueue(queue);
}
void printLinkedList(Queue queue) {
    int size = getQueueSize(queue);
    QueueInfo * info = queue.info;
    assert(size >= 0);
    printf("Size of Linked List: %d\n", size);
    Node * nextNode;
    Node * currentNode = info->rear->next;
    assert(currentNode != NULL);
    for (int i = 0; i < size && currentNode != NULL; i++, currentNode = nextNode) {
        nextNode = currentNode->next;
        printf("Data: %d\n",*(int*) currentNode->Object);
        
    }
}