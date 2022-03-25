#include "lab7.h"
#include <assert.h>

/*
    =============BEGIN CUSTOM FUNCTIONS NOT IN LAB7.H==============
*/


/*
    Helper function not included on lab7.h to generate new Nodes. Returns NULL if malloc fails. 
*/
Node * createNode(void * Object, int * error) {
    Node *pointer;
    pointer = malloc(sizeof(Node));
    if (pointer == NULL) {
        *error = 1;
        return NULL;
    }
    pointer->data = Object;
    pointer->next = NULL;
    *error = 0;
    return pointer;
}
/*
    Helper function not included on lab7.h to retrieve the tail of the Linked List. Returns NULL if the list pointer is NULL.
*/
Node * retrieveTail(Node * list) {
    if (list == NULL) {
        return NULL;
    }
    Node * tail = list;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    return tail;
}
/*
    Helper function not included on lab7.h to insert a given Node at the tail of the Linked List. Returns 1 if retrieveTail fails. Otherwise, 0.
*/
int insertAtTail(Node * list, Node * newNode) {
    Node * tail = retrieveTail(list);
    if (tail == NULL) {
        return 1;
    }
    tail->next = newNode;
    return 0; 
}

/*
    =============END CUSTOM FUNCTIONS NOT IN LAB7.H==============
*/


/*
    Generates a new Linked List ADT. Places a dummy node at the beginning that will store the size of the list for later. 
*/
Node * initList() {
    int error = 0;
    int * size = malloc(sizeof(int));
    Node * dummyNode = createNode(size, &error);
    return error == 1 ? NULL : dummyNode;
}
/*
    Returns -1 if the list is NULL. Accesses the dummy node of the list to retrieve the size. 
*/
int getSize(Node *list) {
    return list == NULL ? -1 : *((int*) list->data);
}
/*
    Inserts a given node at the given index. If the index is equal to the size, inserts at tail inside. Returns 1 if list, data are NULL, if index > 0 or index < size of Linked List. 
    Additionally returns 1 if createNode fails. 
*/
int insertAtIndex(Node *list, void *data, int index) {
    if (list == NULL || data == NULL || index < 0 || index > getSize(list)) {
        return 1;
    }
    int error = 0;
    Node * dummyNode = list;
    Node * newNode = createNode(data, &error);
    if (error == 1) {
        return 1;
    }
    // code for inserting at tail
    if (index == getSize(list)) {
        insertAtTail(list, newNode);
        int * size = (int *) dummyNode->data;
        *size += 1;
        return 0;
    }
    Node * selectedNode = list;
    for (int i = 0; i < index-1; i++) {
        selectedNode = selectedNode->next;
    }
    Node * nodeInMiddle = selectedNode->next;
    selectedNode->next = newNode;
    newNode->next = nodeInMiddle;
    int * size = (int *) dummyNode->data;
    *size += 1;
    return 0;

}
/*
    Retrieves the data pointer of a Node at the given index. Returns NULL if the index given does not correspond to anything in the List. 
*/
void * getAtIndex(Node *list, int index) {
    Node * head = list->next;
    for (int i = 0; head != NULL; i++) {
        if (i == index) {
            return head->data;
        }
        head = head->next;
    }
    return NULL;
}
/*
    Removes the Node at the given index and returns its data pointer. Frees the found Node.
    NOTE: User is responsible for freeing the data pointer returned. 
*/
void * removeAtIndex(Node *list, int index) {
    if (list == NULL || index < 0 || index > getSize(list) || getSize(list) == 0) {
        return NULL;
    }
    Node * dummyNode = list;
    Node * selectedNode = list->next;
    for (int i = 0; i < index-1; i++) {
        selectedNode = selectedNode->next;
    }
    void * data = selectedNode->next->data;
    Node * deletedNode = selectedNode->next;
    selectedNode->next = deletedNode->next;
    free(deletedNode);
    int * size = (int*)dummyNode->data;
    *size -= 1;
    return data;
}
/*
    Removes the tail of the Linked List and returns its data pointer. Frees the tail. 
    NOTE: User is responsible for freeing the data pointer returned. 
    Returns NULL if the given Linked List is NULL.
*/
void * removeAtTail(Node *list) {
    if (getSize(list) == 0) {
        return NULL;
    }
    Node * nodeBeforeTail;
    Node * head = list->next;
    Node * dummyNode = list;
    while (head->next != NULL) {
        nodeBeforeTail = head;
        head = head->next;
    }
    void * data = nodeBeforeTail->next->data;
    free(nodeBeforeTail->next);
    nodeBeforeTail->next = NULL;
    int * size = (int*)dummyNode->data;
    *size -= 1;
    return data;
}
/*
    Frees the given Linked List including all data objects. 
    Sets the given Node pointer to NULL. 
*/
void freeList(Node **list) {
    Node * currentNode = *list;
    for(Node * nextNode; currentNode!=NULL; currentNode = nextNode)
    {
        nextNode = currentNode->next;
        free(currentNode->data);
        free(currentNode);
    }
    *list = NULL;
}