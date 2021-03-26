#include "mbed.h"

//unsigned character examples
//unsigned char a=3;
//unsigned char a=257;
//unsigned char a=-1;

//representing a hexadecimal number
//unsigned char a=0x1F;

//signed character examples
//signed char a=127;
//signed char a=128;
//signed char a=-1;

//integer examples
//int a=257;
//int a=265.35;

//float examples
//float a=257;
float a=265.35;

int main() {
    
    //printf("a value is %d\n", a);
    //printf("a value is %x\n", a);
    //printf("a value is %X\n", a);
    printf("a value is %f\n", a);
    
    while (1) {
    wait_ms(500);
    }
}
