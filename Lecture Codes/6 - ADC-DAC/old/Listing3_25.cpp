#include "mbed.h"

AnalogOut dac(PA_4);

int main()
{
	float DAC_voltage = 0;

    while(true){
		dac.write(DAC_voltage/3.3);	
		DAC_voltage = DAC_voltage + 0.01;
		if(DAC_voltage > 3.3)DAC_voltage = 0;			
		wait_ms(10);		
	}
}
