#include "mbed.h"

DigitalOut led(LED1);

InterruptIn button(BUTTON1);

void toggle_led() {
    printf("BUTTON fall invoked\n");
    led = !led;
}

int main() {

    //button.fall(callback(&toggle_led));
    button.rise(callback(&toggle_led));

    wait_ms(osWaitForever);

    /*
    while (true)
    {
    wait_ms(500);
    };    
    */
}
