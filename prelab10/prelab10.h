//
// Created by thequ on 4/23/2022.
//

#ifndef CS2050_PRELAB10_H
#define CS2050_PRELAB10_H

#endif //CS2050_PRELAB10_H

#include <stdio.h>
#include <stdlib.h>
typedef struct BinaryTree {
    void * Object;
    struct BinaryTree * left;
    struct BinaryTree * right;
}BinaryTree;
typedef struct Employee {
    int SSN;
    int ID;
}Employee;

typedef struct EmpInfo {
    BinaryTree * ssn_top;
    BinaryTree * id_top;
    int size;
    int error;
}EmpInfo;
typedef struct EmpDatabase {
    EmpInfo * info;
}EmpDatabase;


EmpDatabase createSearchableEmployeeDB();
EmpDatabase insertEmployee(Employee *, EmpDatabase);
Employee * findEmpBySSN(int, EmpDatabase);
Employee * findEmpByID(int, EmpDatabase);
void printEmployees(EmpDatabase, int);
void printEmployee(Employee*);
void freeEmpDatabase(EmpDatabase);
int getErrorCode(EmpDatabase);