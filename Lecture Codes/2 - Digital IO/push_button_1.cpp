//add components

#include "mbed.h"

DigitalOut red_led(p5);

DigitalIn button(p7);

int main()
{
    red_led.write(0);

    while (true)
    {
        if (button==1){
            wait_ms(100);
            red_led.write(1);
        printf("Button value is %d\n", button.read());
        }
        else {
            red_led.write(0);
        printf("Button value is %d\n", button.read());
            }
    wait_ms(500);
    }
}