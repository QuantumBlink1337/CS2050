#include "prelab7.h"

int main(void) {
    int error = 0;
    List list = initList(&error);
    for (int i = 0; i < 100; i++) {
        int * j = malloc(sizeof(int));
        *j = 100 - i;
        insertAtTail(j, list);
    }

    int size = getListLength(list);
    Node * head = list.head;
    for (int i = 0; i < size; i++) {
        printf("Object: %d\n", *(int*)getAtIndex(i, list));
        head = head->next;
        
    }
    freeList(list);

}