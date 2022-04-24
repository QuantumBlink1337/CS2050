#include "prelab9.h"
#include <time.h>
int main(void) {
    srand(time(NULL));
    int size = 100;
    Employee * employees = malloc(sizeof(Employee) * size);
    int randomSSN;
    int ID;
    for (int i = 0; i < size; i++) {
        Employee employee;
        employee.SSN = rand() % 1000;
        employee.ID = rand() % 30;
        employees[i] = employee;
        if (i == size-1) {
            randomSSN = employee.SSN;
            ID = employee.ID;
        }
    }
    EmpInfo database = createSearchableEmployeeDB(&employees, size);
    printEmployees(database);
    printf("RandomID: %d\nRandomSSN:%d\n", ID, randomSSN);
    printf("\n\n\n");
    printEmployee(findEmpBySSN(randomSSN, database));
    printf("\n\n\n");
    printEmployee(findEmpByID(ID, database));
    printf("\n\n\n");
    printEmployee(findEmpBySSN(10, database));

    freeEmpDatabase(database);
}