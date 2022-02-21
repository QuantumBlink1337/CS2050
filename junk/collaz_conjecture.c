#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int ifOdd(int value);
int ifEven(int value);


int main (void) {
    int value = 1;
    while (value > 0) {
        printf("Value: %d\n", value);
        if (value % 2 != 0) {
            value = ifOdd(value);
        }
        else {
            value = ifEven(value);
        }
        sleep(2);
    }
}
int ifOdd(int value) {
    return (value * 3) + 1;
}
int ifEven(int value) {
    return value / 2;
}