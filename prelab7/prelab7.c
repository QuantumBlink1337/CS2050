#include "prelab7.h"

Node * retriveTail(List list) {
    Node * tail;
    Node * head = list.head;
    while (head->next != NULL) {
        tail = head;
        head = head->next;
    }
    return tail; 
}

int insertAtHead(void* data, List list) {
    int error = 0;
    Node * newNode = createNode(data, &error);
    newNode->next = ;
    list.head.next = newNode;
    printf("Pointer: %p\n", list.head);
    return error;
}
int insertAtTail(void* data, List list) {
    int error = 0;
    Node * tail = retriveTail(list);
    tail->next = createNode(data, &error);
    return error; 

}
void * removeHead(List list) {
    Node * head = list.head;
    Node * tmp = head;
    void * data = head->Object;
    head = head->next;
    free(tmp);
    return data;
}
void * removeTail(List list) {
    Node * nodeBeforeTail;
    Node * head = list.head;
    while (head->next->next != NULL) {
        nodeBeforeTail = head;
        head = head->next;
    }
    void * data = nodeBeforeTail->next->Object;
    free(nodeBeforeTail->next);
    nodeBeforeTail->next = NULL;
    return data;
}


List initList(int * error) {
    int * q = malloc(sizeof(int));
    *q = -1;
    // I use an integer here solely to prove its a dummy node 
    List list = {createNode(q, error)};
    return list;
}
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
void * getAtIndex(int index, List list) {
    int size = getListLength(list);
    Node * head = list.head;
    for (int i = 0; i < size; i++) {
        if (index == i) {
            return head->Object;
        }
        printf("triggered\n");
        head = head->next;
    }
    return NULL;
}
int getListLength(List list) {
    Node * head = list.head;
    int i = 0;
    while (head->next != NULL) {
        printf("Test\n");
        i++;
        head = head->next;
    }
    return i;
}
void freeList(List list) {
    Node * tmp;
    Node * node = list.head;
    while (node->next != NULL) {
        tmp = node;
        node = node->next;
        free(tmp->Object);
        free(tmp);
    }
    free(node);
}


