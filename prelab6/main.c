#include "prelab6.h"

int main(void) {
    int error = 0;
    List * list = initList(&error);
    
    for (int i = 0; i < 100; i++) {
        int * j = malloc(sizeof(int));
        *j = 100 - i;
        list = insertAtHead(j, list, &error);
    }
    int size = getListLength(list);
    printf("Size: %d\n", size);
    printf("Object: %d\n", *((int*)(getAtIndex(20, list))));
    freeList(list);

}