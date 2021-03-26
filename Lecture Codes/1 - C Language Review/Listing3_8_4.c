#include "mbed.h"

//char a[5] = {1,2,3,4,5};
//char *a_pointer;

//int a[5] = {1,2,3,4,5};
//int *a_pointer;

//float a[5] = {1,2,3,4,5};
//float *a_pointer;

double a[5] = {1,2,3,4,5};
double *a_pointer;


int main() {

    int count;
    
    for(count=0;count<5;count++)
//    printf("array a value at count %d is %d\n", count, a[count]);
    printf("array a value at count %d is %f\n", count, a[count]);
    printf("\n");

    a_pointer = a;

    for(count=0;count<5;count++){
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    a_pointer++;    
    }
    
    while (1) {
    wait_ms(500);
    }
}