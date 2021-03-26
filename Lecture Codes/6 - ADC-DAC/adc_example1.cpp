#include "mbed.h"
 
AnalogIn   ain(p15);
 
int main(void)
{

    float av_float;
    unsigned int av_int;

    while (true) {

        // normalized value
        av_float=ain.read();
        //16-bit value
        av_int=ain.read_u16();

        printf("normalized: %.6f\n", av_float);
        printf("16-bit unsigned: 0x%04X \n", av_int);
        wait_ms(200);
    }
}