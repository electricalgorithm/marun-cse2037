//works on the board
//mbed os 5.15
#include "mbed.h"

DigitalOut led_green(LED1);
InterruptIn button(BUTTON1);
Ticker Ticker1;

void toggle_green() {
    led_green = !led_green;
    Watchdog::get_instance().kick();
}

void trigger(){
    while(1){}
}

int main()
{
    Watchdog &WDT = Watchdog::get_instance();
    Ticker1.attach(&toggle_green, 1.0f);
    WDT.start(4000);
    button.rise(&trigger);
    
    while(1) {
    }
}
