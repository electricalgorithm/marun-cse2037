#include "mbed.h"

float a[6] = {2,4,1,3,6,8};
float *a_pointer;
float b = 0;
float c = 1;

int main() {

    int count;
    
    for(count=0;count<6;count++)
     printf("array a value at count %d is %f\n", count, a[count]);
    
    printf("\n");

count = 0;
while(c==1){

    a_pointer = a+count;
    b = b + *a_pointer;
    c = b<15;
    
    printf("summation of a_pointer values %f\n", b);
    printf("summation compare %f\n", c);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("\n");

count++;
}


    while (1) {
    wait_ms(500);
    }
}