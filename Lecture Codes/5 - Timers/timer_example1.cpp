#include "mbed.h"


DigitalOut led(LED1);

Ticker timer_ticker; //interrupt source, setup step

// Response to the interrupt
// Interrupt Service Routine (ISR)
// Interrupt callback function
void toggle_LED(){
	led=!led;
}


int main() {

    //Interrupt setup has been done.
    
    //associate the hardware part and software part
    //when the button is pressed, execute the function named "toggle_led"
    timer_ticker.attach(callback(&toggle_LED), 2.0f);

    //the CPU goes to the deep sleep mode.
    wait_ms(osWaitForever);

}