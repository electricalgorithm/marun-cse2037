#include "mbed.h"

DigitalOut red_led(p5);

int main() {
    while (1) {
        red_led=0; // apply 0V to pin p5; turn off red LED there
        //red_led.write(0); 
        wait_ms(500);

        red_led=1; // apply 3.3V to pin p5; turn on red LED there
        //red_led.write(1); 
        wait_ms(500);
    }
}
