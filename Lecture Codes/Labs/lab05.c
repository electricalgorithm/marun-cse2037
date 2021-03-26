#include "mbed.h"

float a[6] = {2,4,1,3,6,8};
float *a_pointer;
float b = 0;
char c[6];

int main() {

    int count;
    
    for(count=0;count<6;count++)
     printf("array a value at count %d is %f\n", count, a[count]);
    
    printf("\n");

    for(count=0;count<6;count++){
    a_pointer = a+count;
    b = b + *a_pointer;
    c[count] = b<15;
    
    printf("summation of a_pointer values %f\n", b);
    printf("summation compare %d\n", c[count]);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("\n");
}



    while (1) {
    wait_ms(500);
    }
}