#include "mbed.h"

#define WAIT_TIME 500 //msec

DigitalIn switch1(p5);
DigitalOut led1(p6);


int main()
{
    while (true)
    {
     
     if(switch1.read()==0){
        led1 = !led1;
     }
    wait_ms(WAIT_TIME);
    }
}
