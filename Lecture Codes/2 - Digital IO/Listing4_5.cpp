#include "mbed.h"

DigitalOut green_led(LED1);

int main()
{
    while (true)
    {
        green_led = 0;

         wait_ms(500);
        
        green_led = 1;

         wait_ms(500);

//Alternatively
/*
        green_led = !green_led;
         wait_ms(500);
*/

    }
}
