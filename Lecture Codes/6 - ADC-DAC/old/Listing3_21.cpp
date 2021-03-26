#include "mbed.h"
PwmOut pwm(LED1);
InterruptIn button1(BUTTON1);
int duty_cycle = 0;

void increase_duty_cycle(){
	duty_cycle = duty_cycle + 100;
	if (duty_cycle > 1000)duty_cycle = 0;
	pwm.pulsewidth_us(duty_cycle);	
}

int main()
{
	__enable_irq(); 
    button1.rise(&increase_duty_cycle);
    pwm.period_ms(1);
    pwm.pulsewidth_us(duty_cycle);

	while(true);
}
