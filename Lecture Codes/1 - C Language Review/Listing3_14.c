#include "mbed.h"
#include "math.h"

#define M 20
#define PI 3.1415

float sine_arr[M];

int main() {

    int count;

    for(count=0;count<M;count++)
        sine_arr[count]=sin(2*PI*count/M);

    for(count=0;count<M;count++)
     printf("sine array value at count %d is %f\n", count, sine_arr[count]);

    while (1) {
    wait_ms(500);
    }
}



