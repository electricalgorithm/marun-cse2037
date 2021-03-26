//add components
#include "mbed.h"

DigitalOut yellow_led(p5);

int main()
{
    while (true)
    {
        //yellow_led = 0;
        yellow_led.write(0);

         wait_ms(500);
        
        //yellow_led = 1;
        yellow_led.write(1);

         wait_ms(500);

//Alternatively
/*
        yellow_led = !yellow_led;
         wait_ms(500);
*/

    }
}
