#include "mbed.h"
 
AnalogIn   ain(p15);

float ADC_to_voltage(float value){
	float voltage;
	voltage = 5.0 *value;
	return voltage;
}

int main(void)
{

    float av_float;
    unsigned int av_int;
    float voltage;

    while (true) {

        // normalized value
        av_float=ain.read();
        //16-bit value
        av_int=ain.read_u16();
        //voltage value
        voltage = ADC_to_voltage(av_float);
    
        printf("normalized: %.6f\n", av_float);
        printf("16-bit unsigned: 0x%04X \n", av_int);
        printf("ADC voltage: %2.6f \n", voltage);
        wait_ms(200);
    }
}