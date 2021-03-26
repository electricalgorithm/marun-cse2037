
#include "mbed.h"

#define WAIT_TIME 500 //msec

DigitalOut led1(LED1);

int main()
{
    while (true)
    {
        led1 = !led1;
        wait_ms(WAIT_TIME);
    }
}
