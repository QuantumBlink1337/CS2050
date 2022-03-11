#include "prelab6.h"

List * initList(int * error) {
    return createNode(NULL, error);
}
List * createNode(void * Object, int * error) {
    List *pointer;
    pointer = malloc(sizeof(List));
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
    List * pointer = createNode(Object, error);
    if (pointer == NULL) {
        *error = 1;
        return NULL;
    }
    pointer->next = list;
    return pointer;
}
void * getAtIndex(int index, List * list) {
    List * head = list;
    for (int i = 0; head->next != NULL; i++) {
        if (i == index) {
            return head->Object;
        }
        head = head->next;
    }
    return NULL;
}
int getListLength(List * list) {
    int i;
    for (i = 0; list->next != NULL; i++) {
        list = list->next;
    }
    return i;
}
List * freeList(List * list) {
    List * tmp;
    while (list->next != NULL) {
        tmp = list;
        list = list->next;
        free(tmp->Object);
        free(tmp);
    }
    free(list);
    return NULL;
}