#include "mbed.h"

int sum(int d,int e);

int main(){
    
    int a = 1;
    int b = 2;
    int c;

    c = sum(a,b);

    printf("a value is %d\n", a);
    printf("b value is %d\n", b);
    printf("c value is %d\n", c);

  //  printf("s value is %d\n", s);
    
    while (1) {
    wait_ms(500);
    }
}

int sum(int s1,int s2){
    int s;
        s= s1+s2;
    
    printf("s value is %d\n", s);
        
    return s;
}