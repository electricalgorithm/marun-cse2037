#include "mbed.h"

int a = 1;

int main() {
    
    int b = 2;
    int c;

    c = a+b;

    printf("a value is %d\n", a);
    printf("b value is %d\n", b);
    printf("c value is %d\n", c);

    while (1) {
    wait_ms(500);
    }
}
