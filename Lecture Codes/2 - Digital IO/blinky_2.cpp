#include "mbed.h"

DigitalOut red_led(p6);

int main() {
    while (1) {
        red_led=!red_led; // toggle voltage value (between 0V and 3.3V) on the pin
        wait_ms(500);
    }
}
