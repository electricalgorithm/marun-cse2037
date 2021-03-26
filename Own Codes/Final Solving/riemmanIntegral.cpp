#include "mbed.h"

#define 5MIN_SEC 300

AnalogIn source(p20);
Timeout tout;

volatile int cond = 1;
int total = 0;

void timeout_ISR() {
	extern volatile int cond;
	cond = 0;
}

int main() {
	extern volatile int cond;
	tout.attach(callback(&timeout_ISR), 5MIN_SEC);

	while (cond) {
		total += source.read();
		wait_ms(20); // 0.02sec = 20ms
	}
	
	wait_ms(osWaitForever);
}
