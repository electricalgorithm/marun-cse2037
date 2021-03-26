#include "mbed.h"

#define VCC 5  // As voltages
#define SAMPLING_RATE 50  // As miliseconds

PwmOut output(p5);
AnalogIn periodSelector(p20); // Between 0 to 1 second.
AnalogIn peakSelector(p15); // Between Vcc and 0V.

int main() {
    double inc;

    while (1) {
        printf("Period: %.2f\n", periodSelector.read());
        printf("Peak: %.2f\n", peakSelector.read()*VCC);
        printf("Output: %.2f\n", output.read()*VCC);
        
        if (output >= peakSelector) inc = -periodSelector;
        else if (output == 0) inc = periodSelector;
        
        output = output + inc;
        
        wait_ms(SAMPLING_RATE);
    }
}
