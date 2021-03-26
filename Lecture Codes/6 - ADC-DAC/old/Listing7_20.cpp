#include "mbed.h"

#define PI 3.14159265358979323846

Ticker timer_ticker;
AnalogOut dac(PA_4);

float sine_voltages[128];
int DAC_flag = 0;

void set_DAC(){
    DAC_flag = 1;
}

int main()
{
    int i;
	timer_ticker.attach(&set_DAC, 0.125);
	for(i=0;i<128;i++){
		sine_voltages[i] = 1.65 + 1.65 * sin(2 * PI * i / 128);
	}
	i = 0;

	while(true){
		if(DAC_flag == 1){			
			dac.write(sine_voltages[i]/3.3);
			i++;
			if(i==128)i=0;
			DAC_flag = 0;
		}
	}
}
