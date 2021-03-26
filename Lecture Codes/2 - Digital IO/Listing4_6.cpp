//add components

#include "mbed.h"

DigitalOut red_led(p5);
DigitalOut blue_led(p6);

DigitalIn button(p7);

int main()
{
    red_led = 0;
    blue_led = 1;

    while (true)
    {
        if (button==1){
            wait_ms(100);
            blue_led = 0;
            red_led = 1;
        }
        else {
                blue_led = 1;
                red_led = 0;
            }
    wait_ms(500);
    }

}
