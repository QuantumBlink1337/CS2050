#include "alt7.h"
#include <assert.h>

Node * retrieveTail(List list) {
    
}

int insertAtHead(void* data, List list) {
    int error = 0;
    Node * newNode = createNode(data, &error);
    newNode->next = list.head->next;
    if (list.head->next != NULL) {
        list.head->next->prev = newNode;
    }
    if (list.head->Object == NULL) {
        list.tail->next = newNode;
        assert(list.tail->next != NULL);
    }
    list.head->next = newNode;
    return error;
}
int insertAtTail(void* data, List list) {
    int error = 0;
    Node * tail = list.tail->next;
    Node * newNode = createNode(data, &error);
    if (tail == NULL) {
        list.tail->next == newNode;
        return error;
    }
    newNode->prev = tail;
    tail->next = newNode;
    return error; 
}
void * removeHead(List list) {
    Node * head = list.head->next;
    assert (head != NULL);
    void * data = head->Object;
    void * temp = head->next;
    list.head->next = head->next;
    free(temp);
    return data;
}
void * removeTail(List list) {
    Node * nodeBeforeTail;
    Node * head = list.head->next;
    while (head->next != NULL) {
        nodeBeforeTail = head;
        head = head->next;
    }
    void * data = nodeBeforeTail->next->Object;
    free(nodeBeforeTail->next);
    nodeBeforeTail->next = NULL;
    return data;
}


List initList(int * error) {
    Node * node = createNode(NULL, error);
    List list = {node, node};
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
    pointer->prev = NULL;
    *error = 0;
    return pointer;
}
void * getAtIndex(int index, List list) {
    int size = getListLength(list);
    Node * head = list.head->next;
    for (int i = 0; i < size; i++) {
        if (index == i) {
            return head->Object;
        }
        head = head->next;
    }
    return NULL;
}
int getListLength(List list) {
    Node * head = list.head->next;
    int i = 1;
    while (head->next != NULL) {
        i++;
        head = head->next;
    }
    return i;
}

void freeList(List list)
{
    Node * currentNode = list.head;
    for(Node * nextNode; currentNode!=NULL; currentNode = nextNode)
    {
        nextNode = currentNode->next;
        free(currentNode->Object);
        free(currentNode);
    }
}


