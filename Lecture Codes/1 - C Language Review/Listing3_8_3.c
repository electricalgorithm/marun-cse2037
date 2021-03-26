#include "mbed.h"

float a[5] = {1,2,3,4,5};
float *a_pointer;

int main() {

    int count;
    
    for(count=0;count<5;count++)
     printf("array a value at count %d is %f\n", count, a[count]);
    
    printf("\n");

    a_pointer = a;
    printf("a_pointer value is %f\n", *a_pointer);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&a_pointer);
    printf("\n");

    a_pointer += 1;
    printf("a_pointer value is %f\n", *a_pointer);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&a_pointer);
    printf("\n");


    *a_pointer = 0;
    printf("a_pointer value is %f\n", *a_pointer);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&a_pointer);
    printf("\n");

    for(count=0;count<5;count++)
     printf("array a value at count %d is %f\n", count, a[count]);

    while (1) {
    wait_ms(500);
    }
}