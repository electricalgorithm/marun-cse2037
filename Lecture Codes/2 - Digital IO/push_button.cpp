//add components

#include "mbed.h"

DigitalOut led(LED1);

DigitalIn button(p7);

int main(){
    led = 0;

    while (true){
        if (button==1) {
            wait_ms(100);
            led = 1;
            printf("Button value is %d\n", button.read());
        } else {
            led = 0;
            printf("Button value is %d\n", button.read());
        }
   	
	wait_ms(500);
    }
}
