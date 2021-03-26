#include "mbed.h"

int a = 17;
int b = 2;
float c, d, e;

int main() {

    c = a/b;
    d = (float) a / (float) b;
    e =  a / (float) b;

    printf("a value is %d\n", a);
    printf("b value is %d\n", b);
    printf("\n");
    
    printf("c value is %f\n", c);
    printf("d value is %f\n", d);
    printf("e value is %f\n", e);

    while (1) {
    wait_ms(500);
    }
}
