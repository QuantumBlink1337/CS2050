#include "prelab9.h"

int binarySearchEmployee(Employee employees[], int min, int max, int searchedValue, int isSSN) {
    if (max >= min) {
        int midPoint = min + (max - min) / 2;
        int value;
        if (isSSN == 1) {
            value = employees[midPoint].SSN;
        }
        else {
            value = employees[midPoint].ID;
        }
            if (value == searchedValue) {
                return midPoint;
            }
            if (value > searchedValue) {
                return binarySearchEmployee(employees, min, midPoint - 1, searchedValue, isSSN);
            }
            return binarySearchEmployee(employees, midPoint+1 ,max, searchedValue, isSSN);
    }
    return -1;
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
EmpDatabase createSearchableEmployeeDB(Employee ** employees, int size) {
    EmpDatabase database;
    database.array = *employees;
    database.size = size;
    database.error = 0;
    return database;
}
Employee * findEmpBySSN(int SSN, EmpDatabase database) {
    qsort(database.array, database.size, sizeof(Employee), compareSSN);
    printEmployees(database);
    int index = binarySearchEmployee(database.array, 0, database.size, SSN, 1);
    if (index == -1) {
        database.error = 1;
        return NULL;
    }
    database.error = 0;
    return &database.array[index];
}
Employee * findEmpByID(int ID, EmpDatabase database) {
    qsort(database.array, database.size, sizeof(Employee), compareID);
    printEmployees(database);
    int index = binarySearchEmployee(database.array, 0, database.size, ID, 0);
    if (index == -1) {
        database.error = 1;
        return NULL;
    }
    database.error = 0;
    return &database.array[index];
}

void printEmployees(EmpDatabase database) {
    for (int i = 0; i < database.size; i++) {
        printf("SSD: %d | ID: %d\n", database.array[i].SSN, database.array[i].ID);
    }
}
void printEmployee(Employee* employee) {
    if (employee == NULL) {
        printf("Invalid employee");
        return;
    }
    printf("SSD: %d | ID: %d\n", employee->SSN, employee->ID);
}


void freeEmpDatabase(EmpDatabase d) {
    free(d.array);
}
int getErrorCode(EmpDatabase d) {
    return d.error;
}