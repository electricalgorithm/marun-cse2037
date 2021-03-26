#include "mbed.h"

DigitalOut led(LED1);

int main() {
    while (1) {
        led = !led;
        
        wait_ms(500);
    }
}
