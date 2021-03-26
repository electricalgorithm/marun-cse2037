#include "mbed.h"

char a[5] = {1,2,3,4,5};
char b;
char c=3;
char d;

int main() {

    int count;
    
    for(count=0;count<5;count++) printf("array's value at count %d is %d\n", count, a[count]);
    
    printf("\n");

   
   for(count=0;count<5;count++){
       b = a[count];
       d = b + c;
       printf("array's shifted value at count %d is %d\n", count, d);
   }
   
   printf("\n");


    while (1) {
        wait_ms(500);
    }
}

/*

#include "mbed.h"

char a[5] = {1,2,3,4,5};
char c=3;

int main() {
    for(int count=0;count<5;count++) printf("array's value at count %d is %d\n", count, a[count]);
    printf("\n");
    for(int count=0;count<5;count++) printf("array's shifted value at count %d is %d\n", count,  a[count] + c);
    while (1) wait_ms(500);
}

*/