//Works on the Nucleo-L073RZ board only
#include "mbed.h"

#define WAIT_TIME_MS 500 

DigitalOut led(LED1);


InterruptIn button(BUTTON1); //interrupt source, setup step

// Response to the interrupt
// Interrupt Service Routine (ISR)
// Interrupt callback function
void toggle_led() {
   // printf("Interrupt has occured, we are now serving it.\n");
    led = !led;
    while(1);
}


int main() {
   
    //Interrupt setup has been done.
    
    //associate the hardware part and software part
    //when the button is pressed, execute the function named "toggle_led"
    button.fall(callback(&toggle_led));
   
    //the CPU goes to the deep sleep mode.
    //wait_ms(osWaitForever);
    
    while (1) {
    thread_sleep_for(WAIT_TIME_MS);
    }

}
