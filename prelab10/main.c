//
// Created by thequ on 4/23/2022.
//
#include "prelab10.h"
#include <time.h>
int main(void) {
    srand(time(NULL));
    int size = 500;
    int randomSSN;
    int ID;
    EmpDatabase database = createSearchableEmployeeDB();
    Employee ** employeeList = malloc(sizeof(Employee*) * size);
    for (int i = 0; i < size; i++) {
        Employee * employee = malloc(sizeof(Employee));
        employee->SSN = rand() % 10000;
        employee->ID = rand() % 100000;
        employeeList[i] = employee;
        insertEmployee(employee, database);
        if (i == size-1) {
            randomSSN = employee->SSN;
            ID = employee->ID;
        }
    }
    printEmployees(database, 1);
    printf("\n\n\n");
    printEmployees(database, 0);
    printf("RandomID: %d\nRandomSSN:%d\n", ID, randomSSN);
    printf("\n\n\n");
    printEmployee(findEmpBySSN(randomSSN, database));
    printEmployee(findEmpByID(ID, database));

    freeEmpDatabase(database);
    for (int i = 0; i < size; i++) {
        free(employeeList[i]);
    }
    free(employeeList);
}