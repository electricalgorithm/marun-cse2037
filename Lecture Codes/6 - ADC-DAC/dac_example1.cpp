#include "mbed.h"

// Initialize a pins to perform analog and digital output fucntions
AnalogOut  aout(p5);
DigitalOut dout(p6);

int main(void)
{
    while (1) {
        // change the voltage on the digital output pin by 0.1 * VCC
        //  and print what the measured voltage should be (assuming VCC = 3.3v)
        for (float i = 0.0f; i < 1.0f; i += 0.1f) {
            aout = i;
            printf("aout = %1.2f volts\n", aout.read() * 3.3f);
            // turn on the led if the voltage is greater than 0.5f * VCC
            dout = (aout > 0.5f) ? 1 : 0;
            wait(1.0f);
        }
    }
}