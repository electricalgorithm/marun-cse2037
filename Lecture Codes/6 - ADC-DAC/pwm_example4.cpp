#include "mbed.h"

PwmOut led(p5);

InterruptIn button(BUTTON1);
int duty_cycle = 0;

void increase_duty_cycle(){
	duty_cycle = duty_cycle + 100;
	if (duty_cycle > 1000) duty_cycle = 0;
	led.pulsewidth_us(duty_cycle);	
}


int main() {

    while(true) {
    button.rise(callback(&increase_duty_cycle));
    led.period_ms(1);
    led.pulsewidth_us(duty_cycle);

    printf("LED is now %.2f\n", led.read());
    wait_ms(200);
    }
}
