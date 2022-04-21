#include "lab7.h"
#include <assert.h>
void printLinkedList(Node *);
int main(void) {
    int error = 0;
    Node* list = initList(&error);
    for (int i = 0; i < 5; i++) {
        int * j = malloc(sizeof(int));
        *j = i;
        assert(insertAtIndex(list, j, i) != 1);
    }
    printLinkedList(list);
    int *p = malloc(sizeof(int));
    *p = 10;
    insertAtIndex(list, p, 2);
    printLinkedList(list);
    freeList(&list);

}
void printLinkedList(Node * list) {
    Node * head = list->next;
    assert(head != NULL);
    int size = *(int*)list->data;
    assert(size >= 0);
    printf("Size of Linked List: %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("Data: %d\n",*(int*) getAtIndex(list, i));
    }
}