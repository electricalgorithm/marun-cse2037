//Listing 3_8_1.cpp is modified to use functions

#include "mbed.h"

char a[5] = {1,2,3,4,5};
char *a_pointer;

void replace(char* pointer);


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

/*
    a_pointer += 1;
    printf("a_pointer value is %d\n", *a_pointer);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&a_pointer);
    printf("\n");


    *a_pointer = 0;
  */

//    replace(a);
    replace(a_pointer);

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

void replace(char* pointer)
{
   pointer += 1;
    printf("a_pointer value is %d\n", *pointer);
    printf("Address pointed by a_pointer is %p\n", (void*)pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&pointer);
    printf("\n");

    *pointer = 0;
}