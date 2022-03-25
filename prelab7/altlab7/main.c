#include "alt7.h"
#include <assert.h>

int main(void) {
    int error = 0;
    List list = initList(&error);
    for (int i = 0; i < 50; i++) {
        int * j = malloc(sizeof(int));
        *j = i;
        insertAtTail(j, list);
    }

    //int size = getListLength(list);
    Node * head = list.head->next;
    Node * tail = list.tail->next;
    assert(tail != NULL);
    for (int i = 0; i < 20; i++) {
        printf("Object: %d\n", *(int*)getAtIndex(i, list));
        //head = head->next;
        
    }
    head = head->next;
    printf("Prev: %p\nPrev Object: %d\n", head->prev, *(int*)head->prev->Object);
    printf("Tail: %p\nTail Object: %d\n", tail, *(int*)tail->Object);

    freeList(list);

}