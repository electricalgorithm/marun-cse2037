#include "mbed.h"

int main() {

    char a = 0x02;
//    char b = 0xAF;
    char b = 0x0F;
    char c,d,e,f;

    c = a|b;
    d = a&b;
    e = a^b;
    f = ~a;

    printf("a value is %X\n", a);
    printf("b value is %X\n", b);
    printf("c value is %X\n", c);
    printf("d value is %X\n", d);
    printf("e value is %X\n", e);
    printf("f value is %X\n", f);

    while (1) {
    wait_ms(500);
    }
}

