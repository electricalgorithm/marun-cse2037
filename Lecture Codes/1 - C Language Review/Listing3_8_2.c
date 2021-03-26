#include "mbed.h"

int a[5] = {1,2,3,4,5};
int *a_pointer;

int main() {

    int count;
    
    for(count=0;count<5;count++)
     printf("array a value at count %d is %d\n", count, a[count]);
    
    printf("\n");

    a_pointer = a;
    printf("a_pointer value is %d\n", *a_pointer);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&a_pointer);
    printf("\n");

    a_pointer += 1;
    printf("a_pointer value is %d\n", *a_pointer);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&a_pointer);
    printf("\n");


    *a_pointer = 0;
    printf("a_pointer value is %d\n", *a_pointer);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&a_pointer);
    printf("\n");

    for(count=0;count<5;count++)
     printf("array a value at count %d is %d\n", count, a[count]);

    while (1) {
    wait_ms(500);
    }
}