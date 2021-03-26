#include "mbed.h"

int main() {

    char a = 0;
    char b,c;

    if (a>0)
//    if (a)
        {
        b=1;
        c=0;
        }
        else
        {
        b=0;
        c=1;
        }


    printf("a value is %d\n", a);
    printf("b value is %d\n", b);
    printf("c value is %d\n", c);

    while (1) {
    wait_ms(500);
    }
}

