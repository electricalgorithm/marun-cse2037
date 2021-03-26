#include "mbed.h"

#define WAIT_MSEC 20PwnOut LED(p20);

InterruptIn enter_Sensor(p10);
InterruptIn enter_Sensor(p10);

int totalNumberofCustomers = 0;
float brightness = 0;
// This ISR will be add 1 to
// the totalNumberofCustomers.


void enter_ISR() {
	extern int totalNumberofCustomers;
	totalNumberofCustomers += 1;
}

// This ISR will be suvsbtroct 1 from
// the totalNumberofCustomers.
void exit_ISR() {
	extern int totalNumberofCustomers;
	totalNumberofCustomers -= 1;
}


int main() {
	enter_Sensor.fall(callback(&enter_ISR));
	exit_Sensor.fall(callback(&enter_ISR));
	
	while(true) {
		extern int totalNumberofCustomers;
		extern float brightness;
		if !(totalNumberofCustomers) brightness = 0;
		else {
			// Because we want 20 people for
			// most bright state, the step
			// should be 1/20 = 0.05
			// This will be the incremant for
			// duty cycle at every person enters.
			// LED is a PwnOut pin.
			brightness = totalNumberofCustomers * 0.05f;
		}

	LED = brightness;
	wait_ms(WAIT_MSEC);
}
