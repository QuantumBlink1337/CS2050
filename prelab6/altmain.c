#include "altlab6.h"

int main(void) {
    int error = 0;
    List * list = initList(&error);
    
    for (int i = 0; i < 100; i++) {
        int * j = malloc(sizeof(int));
        *j = i;
        list = insertAtTail(j, list, &error);
    }
    int size = getListLength(list);
    printf("Size: %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("Object: %d\n", *((int*)(getAtIndex(i, list))));
    }
    freeList(list);

}
