#include "mbed.h"
 
Timeout flipper;
DigitalOut led(p5);

void flip() {
    led = !led;
}
 
int main() {
    led = 1;
    flipper.attach(callback(&flip), 2.5f);

    // spin in a main loop. flipper will interrupt it to call flip
    while(1) {
        wait(0.2);
    }



/*
#include "mbed.h"

DigitalOut led(LED1);

InterruptIn btn(BUTTON1);

Timeout t2;

void turn_led_off() {
    led = 0;
}


void turn_led_on() {
    printf("Timeout fired\n");
    led = 1;
}

int main() {

    t2.attach(callback(&turn_led_on), 2.5f);

    btn.fall(callback(&toggle_led2));

    wait_ms(osWaitForever);
}
*/