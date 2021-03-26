#include "mbed.h"


DigitalOut red_led(p5);
DigitalOut blue_led(p6);

Ticker timer1; 

Ticker timer2;

void toggle_red_LED(){
	red_led=!red_led;
}

void toggle_blue_LED(){
	blue_led=!blue_led;
}


int main() {

    timer1.attach(callback(&toggle_red_LED), 2.0f);
    timer2.attach(callback(&toggle_blue_LED), 1.5f);

    wait_ms(osWaitForever);

}