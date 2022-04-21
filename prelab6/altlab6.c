#include "altlab6.h"

List * initList(int * error) {
    List * pointer = malloc(sizeof(List));
    pointer->size = 0;
    pointer->head = pointer->tail = createNode(NULL, error);
    return pointer;
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
List * insertAtHead(void * Object, List * list, int* error) {
    Node * newNode = createNode(Object, error);
    if (newNode == NULL) {
        *error = 1;
        return NULL;
    }
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
    return list;
}
List * insertAtTail(void * Object, List * list, int* error) {

    printf("Test\n");
    Node * newNode = createNode(Object, error);
    if (newNode == NULL) {
        *error = 1;
        return NULL;
    }
    list->tail->next = newNode;
    list->tail = newNode;
    list->size++;
    return list;
}
void * getAtIndex(int index, List * list) {
    Node * head = list->head;
    for (int i = 0; head->next != NULL; i++) {
        if (i == index) {
            printf("Trigger\n");
            return head->Object;
        }
        printf("Seg fault test\n Object: %d\n", *((int *)head->Object));
        head = head->next;
    }
    return NULL;
}
int getListLength(List * list) {
    return list->size;
}
List * freeList(List * list) {
    Node * tmp;
    Node * head = list->head;
    while (head->next != NULL) {
        tmp = head;
        head = head->next;
        free(tmp->Object);
        free(tmp);
    }
    free(list);
    return NULL;
}