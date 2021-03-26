//Works on the Nucleo board only
#include "mbed.h"

#define WAIT_TIME_MS 500 

int *mem_loc;

int a=0;

int main() {

    printf("a value is %X\n", a);

    mem_loc = (int *) 0x20000020;

    *(mem_loc) = 0x01234567;
    *(mem_loc+1) = 0x89ABCDEF;

    printf("memory location value is %X\n", mem_loc);
    printf("content of the memory location is %X\n", *mem_loc);
    printf("\n");

    mem_loc++;

    printf("memory location value is %X\n", mem_loc);
    printf("content of the memory location is %X\n", *mem_loc);

    a=*(mem_loc);

    printf("a value is %X\n", a);


    while (1) {
      thread_sleep_for(WAIT_TIME_MS);
    }
}