#include "mbed.h"

DigitalOut led_red(p5);
DigitalOut led_blue(p6);

Timeout TimeoutDelay;
Ticker Ticker1;
Ticker Ticker2;

void toggle_red() {
    led_red = !led_red;
}

void toggle_blue() {
    led_blue = !led_blue;
}

void delay25() {
   toggle_red();
   Ticker1.attach(callback(&toggle_red), 1.0f);
}

int main()
{
    TimeoutDelay.attach(callback(&delay25), 2.5f);
    Ticker2.attach(callback(&toggle_blue), 1.0f);
    
    wait_ms(osWaitForever);
}