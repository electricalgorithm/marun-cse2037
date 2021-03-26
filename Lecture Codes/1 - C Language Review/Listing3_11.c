#include "mbed.h"

#define CONST 4
//#define CONST 4.2

int a;
float b;

int main() {

    a = 2*CONST;
    b = 2*CONST;

    printf("a value is %d\n", a);
    printf("b value is %f\n", b);
    
    printf("\n");

    while (1) {
    wait_ms(500);
    }
}