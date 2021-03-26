//Listing 3_7.cpp is modified to use functions

#include "mbed.h"

void replace(int *pointer);

//Global variables
/*
int a = 3;
int *a_pointer;
*/

int main() {

//Local variables

int a = 3;
int *a_pointer;


    printf("a value is %d\n", a);
    printf("\n");

    a_pointer = &a;

    printf("a_pointer value is %d\n", *a_pointer);
    printf("a value is %d\n", a);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&a_pointer);
    printf("\n");
    

    //replace(a_pointer);
    replace(&a);
    //*a_pointer = 5;

    printf("a_pointer value is %d\n", *a_pointer);
    printf("a value is %d\n", a);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&a_pointer);

    while (1) {
    wait_ms(500);
    }
}

void replace(int *pointer)
{
    *pointer = 5;
}