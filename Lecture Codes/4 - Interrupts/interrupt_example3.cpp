#include "mbed.h"

DigitalOut red_led(p5);
DigitalOut blue_led(p6);
InterruptIn button(BUTTON1);


void fall_callback(){
  blue_led = !blue_led;
}


void rise_callback(){
  red_led = !red_led;
}


int main() {

    button.fall(callback(&fall_callback));
    button.rise(callback(&rise_callback));
    
    wait_ms(osWaitForever);

/*
    while (true)
	{
	red_led = !red_led;
    wait_ms(osWaitForever);
    }   
*/

}


    

