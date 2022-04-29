//
// Created by thequ on 4/23/2022.
//
#include "prelab10.h"
void * binarySearch(BinaryTree * tree, int searchedValue, int func(void * Object)) {
    int value;
    if (tree == NULL) {
        return NULL;
    }
    void * Object= tree->Object;
    value = func(Object);
    if (value == searchedValue) {
        return Object;
    }
    if (value > searchedValue) {
        return binarySearch(tree->left, searchedValue, func);
    }
    return binarySearch(tree->right, searchedValue, func);
}
int SSNunpackage(void * Object) {
    Employee * employee = Object;
    return employee->SSN;
}
int IDunpackage(void * Object) {
    Employee * employee = Object;
    return employee->ID;
}
void inOrder(BinaryTree * tree, void func(void *), int performOnObject) {
    if (tree != NULL) {
        inOrder(tree->left, func, performOnObject);
        if (performOnObject == 1) {
            func(tree->Object);
        }
        else {
            func(tree);
        }
        inOrder(tree->right, func, performOnObject);
    }
}
void postOrder(BinaryTree * tree, void func(void *), int performOnObject) {
    if (tree != NULL) {
        postOrder(tree->right, func, performOnObject);
        postOrder(tree->left, func, performOnObject);
        if (performOnObject == 1) {
            func(tree->Object);
        }
        else {
            func(tree);
        }
    }
}
void printEmployee(Employee* employee) {
    if (employee == NULL) {
        printf("Invalid employee");
        return;
    }
    printf("SSD: %3d | ID: %d\n", employee->SSN, employee->ID);
}
void printEmployees(EmpDatabase database, int isSortedInSSN) {

    BinaryTree * top = (isSortedInSSN == 1) ? database.info->ssn_top : database.info->id_top;
    if (top == NULL) {
        return;
    }
    inOrder(top, (void (*)(void *)) printEmployee, 1);

}
int compareSSN(const void *a, const void *b) {
    Employee * one = (Employee*) a;
    Employee * two = (Employee*) b;
    return (one->SSN - two->SSN);
}
int compareID(const void *a, const void *b) {
    Employee * one = (Employee*) a;
    Employee * two = (Employee*) b;
    return (one->ID - two->ID);
}
BinaryTree * newTree(void * Object) {
    BinaryTree * new_tree = malloc(sizeof(BinaryTree));
    new_tree->Object = Object;
    new_tree->left = NULL;
    new_tree->right = NULL;
    return new_tree;
}
EmpDatabase createSearchableEmployeeDB() {
    EmpDatabase database;
    EmpInfo * info = malloc(sizeof(EmpInfo));
    info->ssn_top = NULL;
    info->id_top= NULL;
    info->size = 0;
    info->error = 0;
    database.info = info;
    return database;
}
BinaryTree * insert(BinaryTree * tree, void * Object, int compare(const void *, const void *)) {
    if (tree == NULL) {
        return newTree(Object);
    }
    if (compare(Object, tree->Object) < 0) {
        tree->left = insert(tree->left, Object, compare);
    }
    else {
        tree->right = insert(tree->right, Object, compare);
    }
    return tree;
}


Employee * findEmpBySSN(int SSN, EmpDatabase database) {
    return binarySearch(database.info->ssn_top, SSN, SSNunpackage);
}
Employee * findEmpByID(int ID, EmpDatabase database) {
    return binarySearch(database.info->id_top, ID, IDunpackage);
}
EmpDatabase insertEmployee(Employee * employee, EmpDatabase database) {
    EmpInfo * info;
    if ((info = database.info) == NULL) {
        return database;
    }
    if (employee == NULL) {
        info->error = 1;
        return database;
    }
    info->ssn_top = insert(info->ssn_top, employee,  compareSSN);
    info->id_top= insert(info->id_top, employee, compareID);
    info->size++;
    return database;
}
void freeEmpDatabase(EmpDatabase database) {
    postOrder(database.info->ssn_top, free, 0);
    postOrder(database.info->id_top, free, 0);
    free(database.info);
}
int getSize(EmpDatabase database) {
    return database.info->size;
}
int getErrorCode(EmpDatabase database) {
    return database.info->error;
}
