#include <stdio.h>
#include <stdlib.h>
typedef struct Employee {
    int SSN;
    int ID;
}Employee;

typedef struct EmpInfo {
    Employee * array;
    int size;
    int error;
}EmpInfo;


EmpInfo createSearchableEmployeeDB(Employee **, int);
Employee * findEmpBySSN(int, EmpInfo);
Employee * findEmpByID(int, EmpInfo);
void printEmployees(EmpInfo);
void printEmployee(Employee*);
void freeEmpDatabase(EmpInfo);
int getErrorCode(EmpInfo);