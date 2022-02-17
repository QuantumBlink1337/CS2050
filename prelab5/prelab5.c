#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int empID, jobType;
    float salary;
} Employee;

Employee * readEmployeeArray(FILE * fp);
Employee createEmployee(int empID, int jobType, float salary);

Employee * getEmployeeByID(Employee * array, int empID);

int setEmpSalary(Employee *, int empID, float salary);  
int getEmpSalary(Employee *, int empID, float *salary); 
int setEmpJobType(Employee *, int empID, int job);
int getEmpJobType(Employee *, int empID, int *job);


void * createArray(int size, int data_type_size);
void freeArray(void * ptr);
int getSize(void * array);

int main(void) {
    FILE *fp;
    fp = fopen("employees.txt", "r");
    Employee * array = readEmployeeArray(fp);
    int jobType;
    float salary;
    getEmpJobType(array, 00005, &jobType);
    getEmpSalary(array, 00005, &salary);

    printf("Employee info | Job: %d | Salary %f\n", jobType, salary);
}

Employee * readEmployeeArray(FILE * fp) {
    char buffer[200];
    int size;
    fgets(buffer, 200, fp);
    sscanf(buffer, "%d", &size);
    Employee * array = createArray(size, sizeof(Employee));
    for (int i = 0; i < size && !feof(fp); i++) {
        char buffer[200];
        int tempID;
        int tempJobType;
        float tempSalary;
        fgets(buffer, 200, fp);
        sscanf(buffer, "%d, %d, %f", &tempID, &tempJobType, &tempSalary);
        array[i] = createEmployee(tempID, tempJobType, tempSalary);
    }
    return array;
}





Employee createEmployee(int empID, int jobType, float salary) {
    Employee temp = {empID, jobType, salary};
    return temp;
}
Employee * getEmployeeByID(Employee * array, int empID) {
    if (array == NULL) {
        return NULL;
    }
    for (int i = 0; i < getSize(array); i++) {
        if (array[i].empID == empID) {
            return array + i;
        }
    }
    return NULL;
}
int setEmpSalary(Employee * array, int empID, float salary) {
    Employee * employee;
    if ((employee = getEmployeeByID(array, empID)) == NULL) {
        return 1;
    }
    employee->salary = salary;
    return 0;
}
int getEmpSalary(Employee *array, int empID, float *salary) {
    Employee * employee;
    if ((employee = getEmployeeByID(array, empID)) == NULL || salary == NULL) {
        return 1;
    }
    *salary = employee->salary;
    return 0;
}
int setEmpJobType(Employee *array, int empID, int job) {
    Employee * employee;
    if ((employee = getEmployeeByID(array, empID)) == NULL) {
        return 1;
    }
    employee->jobType = job;
    return 0;
}
int getEmpJobType(Employee *array, int empID, int *job) {
    Employee * employee;
    if ((employee = getEmployeeByID(array, empID)) == NULL || job == NULL) {
        return 1;
    }
    *job = employee->jobType;
    return 0;
}
void * createArray(int size, int data_type_size) {
    int* array = malloc(sizeof(int) + (size*data_type_size));
    array[0] = size;
    array++;
    return (void*) array;
}
void freeArray(void * ptr) {
    free(((int*) ptr-1));
}
int getSize(void * array) {
    return *((int*) array-1);
}