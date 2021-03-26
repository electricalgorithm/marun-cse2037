#include "mbed.h"

float a[5] = {1,2,3,4,5};
float *a_pointer;
float b = 0;

int main() {

    int count;
    
    for(count=0;count<5;count++)
     printf("array a value at count %d is %f\n", count, a[count]);
    
    printf("\n");

    for(count=0;count<5;count++){
    a_pointer = a+count;
    b = b + *a_pointer;
    printf("summation of a_pointer values %f\n", b);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("\n");
}



    while (1) {
    wait_ms(500);
    }
}