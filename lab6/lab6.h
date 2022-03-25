#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
	void *data;
	Node *next;
};

Node * initList();
int getSize(Node *list);
int insertAtHead(Node **list, void *data);
void * removeFromHead(Node **list);
void freeList(Node **list);

typedef struct {
	int vin;
	float milesDriven;
	int numberOfAccidents;
} Car;

Car * getWithLeastMilesDriven(Node *list);
void printCars(Node *list);
