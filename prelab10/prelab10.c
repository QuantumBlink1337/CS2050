//
// Created by thequ on 4/23/2022.
//
#include <assert.h>
#include "prelab10.h"
Employee * binarySearchEmployee(BinaryTree * tree, int searchedValue, int isSSN) {
    int value;
    if (tree == NULL) {
        return NULL;
    }
    Employee * midEmployee = (Employee *)tree->Object;
    value = isSSN == 1 ? midEmployee->SSN : midEmployee->ID;
    if (value == searchedValue) {
        return midEmployee;
    }
    if (value > searchedValue) {
        return binarySearchEmployee(tree->left, searchedValue, isSSN);
    }
    return binarySearchEmployee(tree->right, searchedValue, isSSN);
}
void inOrder(BinaryTree * tree, void func(void *)) {
    if (tree != NULL) {
        inOrder(tree->left, func);
        func(tree->Object);
        inOrder(tree->right, func);
    }
}
void freeTree(BinaryTree * tree, int freedObject) {
    if (tree != NULL) {
        freeTree(tree->right, freedObject);
        if (freedObject == 1) {
            free(tree->Object);
        }
        freeTree(tree->left, freedObject);
        free(tree);
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
    inOrder(top, (void (*)(void *)) printEmployee);

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
BinaryTree * ssnInsert(BinaryTree * tree, Employee * employee) {
    if (tree == NULL) {
        return newTree(employee);
    }
    if (compareSSN(employee, tree->Object) < 0) {
        tree->left = ssnInsert(tree->left, employee);
    }
    else {
        tree->right = ssnInsert(tree->right, employee);
    }
    return tree;
}
BinaryTree * idInsert(BinaryTree * tree, Employee * employee) {
    if (tree == NULL) {
        return newTree(employee);
    }
    if (compareID(employee, tree->Object) < 0) {
        tree->left = idInsert(tree->left, employee);
    }
    else {
        tree->right = idInsert(tree->right, employee);
    }
    return tree;
}
Employee * findEmpBySSN(int SSN, EmpDatabase database) {
    return binarySearchEmployee(database.info->ssn_top, SSN, 1);
}
Employee * findEmpByID(int ID, EmpDatabase database) {
    return binarySearchEmployee(database.info->id_top, ID, 0);
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
    info->ssn_top = ssnInsert(info->ssn_top, employee);
    info->id_top= idInsert(info->id_top, employee);
    info->size++;
    return database;
}
void freeEmpDatabase(EmpDatabase database) {
    freeTree(database.info->ssn_top, 1);
    freeTree(database.info->id_top, 0);
    free(database.info);
}
int getSize(EmpDatabase database) {
    return database.info->size;
}
int getErrorCode(EmpDatabase database) {
    return database.info->error;
}
