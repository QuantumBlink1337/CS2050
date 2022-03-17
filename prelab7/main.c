#include "prelab7.h"

int main(void) {
    int error = 0;
    List list = initList(&error);
    printf("Pointer of list before adding: %p\n", list.head);
    for (int i = 0; i < 100; i++) {
        int * j = malloc(sizeof(int));
        *j = 100 - i;
        insertAtHead(j, list);
        //printf("Head\n: %p\n", list.head);
    }

    int size = getListLength(list);
    Node * head = list.head;
    //printf("Head: %p\n", list.head);
    printf("Object: %d\n\n", *((int*)head->Object));
    for (int i = 0; i < size; i++) {
        
        head = head->next;
        
    }
    printf("Size: %d\n", size);
    //printf("Object: %d\n", *((int*)(getAtIndex(20, list))));
    //freeList(list);

}