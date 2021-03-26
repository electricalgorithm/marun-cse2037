#include "mbed.h"

Ticker timer_ticker;
AnalogIn analog(PA_6);
int interrupt_cnt = 0;
int print_flag = 0;
int buffer[20];

float convert_ADCvalue_to_voltage(int value){
	float voltage;
	voltage = 3.3 * ((float)value) / 65535;
	return voltage;
}

void get_ADC(){
    print_flag = 1;
}

int main()
{
	int ADC_value;
	float ADC_voltage;
	float average;
	int i;
	float sum = 0;	
	DigitalOut led2(LED2);
	timer_ticker.attach(&get_ADC, 0.1);

	while(true){
		if(print_flag == 1){
            if(interrupt_cnt<20){
	            buffer[interrupt_cnt] = analog.read_u16();
	            interrupt_cnt++;
            }
            else{
                timer_ticker.detach();
                for(i=0;i<20;i++){
                    ADC_voltage = convert_ADCvalue_to_voltage(buffer[i]);						
                    sum = sum + ADC_voltage;					
                    printf("ADC voltage is %6.4f \n",ADC_voltage);
                }
                printf("Printing is done ! \n");	
                average = sum / 20;
                if(average > 1.5)led2 = 1;
                else led2 = 0;
            }
			print_flag = 0;
		}
	}
}
