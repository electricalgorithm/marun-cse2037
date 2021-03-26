#include "mbed.h"

DigitalOut red_led(p5);
DigitalOut blue_led(p6);
InterruptIn button(BUTTON1);

void ISR_callback(){
blue_led = !blue_led;
}


int main() {

    button.fall(callback(&ISR_callback));

//    wait_ms(osWaitForever);

    while (true) {
      red_led = !red_led;
      wait_ms(osWaitForever);
    }

}


    
