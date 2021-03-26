#include "mbed.h"

int main()
{
	AnalogIn int_temp(ADC_TEMP); 

	while (true){
		int value = int_temp.read_u16();
		printf("Analog value read %u \n", (unsigned int) value);

//wait_ms yerine thread_sleep_for fonksiyonu kullanmak yeterli
		wait_ms(100);
	}
}
