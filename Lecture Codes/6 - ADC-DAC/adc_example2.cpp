#include "mbed.h"
 
// Initialize pins to perform analog input and digital output fucntions
AnalogIn   ain(p15);
DigitalOut dout(p5);
 
int main(void)
{
    while (1) {
        // test the voltage on the initialized analog pin
        //  and if greater than 0.3 * VCC set the digital pin
        //  to a logic 1 otherwise a logic 0
        if(ain > 0.3f) {
            dout = 1;
        } else {
            dout = 0;
        }
        
        // print the percentage and 16 bit normalized values
        printf("percentage: %3.3f%%\n", ain.read()*100.0f);
        printf("normalized: 0x%04X \n", ain.read_u16());
        wait(0.2f);
    }
}