#include "mbed.h"

DigitalOut led1(p5);
DigitalOut led2(p6);

InterruptIn btn(BUTTON1);

Timeout timer_interrupt;

char value=0;

void button_ISR() {
    extern char;
    led1 = !led1;
    value=1;
}


void turn_led_on() {
    printf("Timeout fired\n");
    led2 = 1;
}

int main() {
    btn.fall(callback(&button_ISR));
    
    while (true) {
        printf("value %d \n", value);
    if (value==1) {
        timer_interrupt.attach(callback(&turn_led_on), 2.5f);
        value=0;
    }
    
    wait_ms(500);
    }
}
