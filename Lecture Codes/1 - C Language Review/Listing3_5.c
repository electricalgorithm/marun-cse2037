#include "mbed.h"

int main() {

    int a = 4294967295;
    int b;
    unsigned int c = 0xFFFFFFFF;
    unsigned char d = 0x00;
    int e = 10;
    float f = +10.1;
    float g = -10.1;
    int h = 0;
    float i = 0.0;

    a += 1;
    b = 17/2;
    c += 0x0001;
    d -= 0x01;
    e /= 0;
    f /= 0;
    g /= 0;
    h /= h;
    i /= i;


    printf("a value is %d\n", a);
    printf("b value is %d\n", b);
    printf("c value is %d\n", c);
    printf("\n");

    printf("d value is %d\n", d);
    printf("e value is %d\n", e);
    printf("\n");
    
    printf("f value is %f\n", f);
    printf("g value is %f\n", g);
    printf("h value is %d\n", h);
    printf("i value is %f\n", i);

    while (1) {
    wait_ms(500);
    }
}
