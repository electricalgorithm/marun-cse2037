#include "mbed.h"

AnalogIn position(p15);
PwmOut led(p5);

int main() {

    while(1) {
                
     led=position;

        printf("LED is now %.2f\n", led.read());
        wait(0.2);
    }
}