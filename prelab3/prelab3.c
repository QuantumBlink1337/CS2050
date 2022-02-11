 #include <stdio.h>
 #include <stdlib.h>

 double * createDoubleArray(const int startingIndex, const int endingIndex, int* error);
 void freeArray(void ** ptr);

 int main(void) {
     int error = 0;
     double * array = createDoubleArray(1900, 2000, &error);
     for (int i = 1900; i <= 2000; i++){
         array[i] = 0+i;
         printf("%f\n", array[i]);
     }
     freeArray((void**)&array);
 }
double * createDoubleArray(const int sIndex, const int eIndex, int* error) {
    int size = eIndex - sIndex;
    if (size < 0) {
        *error = 1;
        return NULL;
    }
    double * array = malloc(sizeof(double) * size);
    if (array == NULL) {
        *error = 1;
        return NULL;
    }
    array-= sIndex;
    *error = 0;
    return array;

}
void freeArray(void ** ptr) {
    free(*ptr);
}
