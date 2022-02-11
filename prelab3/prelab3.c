#include <stdio.h>
#include <stdlib.h>


float * readFloatFileIntoArray(FILE *fp, int *length); 
void freePointer(void * ptr);

int main(void) {
    FILE *fp = NULL;
    fp = fopen("float.txt", "r");
    int length = 0;
    float * floatArray = readFloatFileIntoArray(fp, &length);
    for (int i = 0; i < length; i++) {
        printf("%f\n", floatArray[i]);
    }
    fclose(fp);
    freePointer(floatArray);

}
float * readFloatFileIntoArray(FILE *fp, int *length) {
    char buffer[50];
    int size = 0;
    fgets(buffer, 50, fp);
    sscanf(buffer, "%d", &size);
    *length = size;
    if (fp == NULL) {
        *length = -1;
        return NULL;
    }
    if (size <= 0) {
        return NULL;
    }
    float * floatArray = (float*)malloc(sizeof(float) * size);
    if (floatArray == NULL) {
        *length = -1;
        return NULL;
    }
    int i = 0;
    for (; i<size || !feof(fp); i++) {
        float newFloat = 0.0;
        fgets(buffer, 50, fp);
        sscanf(buffer, "%f", &newFloat);
        floatArray[i] = newFloat;
    }
    printf("i: %d\n", i);
    return floatArray;
}
void freePointer(void * ptr) {
    free(ptr);
    ptr = NULL;
}


