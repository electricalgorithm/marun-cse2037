
//works on the board
//select mbed os 5.15

#include "mbed.h"
 
Timer t;
 
int main() {
    t.start();
    printf("Hello World!\n");
    wait_ms(500);
    t.stop();
    printf("The time taken was %d milliseconds\n", t.read_ms());
}


/*

#include "mbed.h"

InterruptIn button(BUTTON1);

DigitalOut led_blue(p6);

Timer Timer1; 

void trigger_rise(){
    Timer1.start();
}

void trigger_fall(){
    Timer1.stop();
    uint32_t elapsed_ms;
    elapsed_ms = Timer1.read_ms();
    printf("Timer value %d \n", elapsed_ms);
    if(elapsed_ms > 3000) led_blue = 1;
    else led_blue = 0;
    Timer1.reset();
}

int main()
{
    button.rise(callback(&trigger_rise));
    button.fall(callback(&trigger_fall));

    while(1) {
        wait(0.2);
    }
}
*/
