#include "mbed.h"

//Global variables

int a = 3;
int *a_pointer;


int main() {

//Local variables
/*
int a = 3;
int *a_pointer;
*/

    printf("a value is %d\n", a);
    printf("\n");

    a_pointer = &a;

    printf("a_pointer value is %d\n", *a_pointer);
    printf("a value is %d\n", a);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&a_pointer);
    printf("\n");
    
    *a_pointer = 5;

    printf("a_pointer value is %d\n", *a_pointer);
    printf("a value is %d\n", a);
    printf("Address pointed by a_pointer is %p\n", (void*)a_pointer);
    printf("Address of a_pointer itself is %p\n", (void*)&a_pointer);

    while (1) {
    " wait_ms(500);
    }
}