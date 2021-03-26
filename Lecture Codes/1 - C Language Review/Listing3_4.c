#include "mbed.h"

char a = 1.2;

char b = -1;

char c1 = 257;
char c2 = -257;

float d = 427.37;

double e = 430.57;

int main() {

    printf("a value is %d\n", a);
    printf("\n");
    
    printf("b value is %d\n", b);
    printf("\n");
    
    printf("c1 value is %d\n", c1);
    printf("c2 value is %d\n", c2);
    printf("\n");
    
    printf("d value is %f\n", d);
    printf("\n");
    
    printf("e value is %f\n", e);
    printf("\n");

    while (1) {
    wait_ms(500);
    }
}
