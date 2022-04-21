#include <stdio.h>
#include <stdlib.h>
typedef struct Employee {
    int SSN;
    int ID;
}Employee;

typedef struct EmpDatabase {
    Employee * array;
    int size;
    int error;
}EmpDatabase;


EmpDatabase createSearchableEmployeeDB(Employee **, int);
Employee * findEmpBySSN(int, EmpDatabase);
Employee * findEmpByID(int, EmpDatabase);
void printEmployees(EmpDatabase);
void printEmployee(Employee*);
void freeEmpDatabase(EmpDatabase);
int getErrorCode(EmpDatabase);