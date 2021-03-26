#include "mbed.h"

DigitalOut led(LED1);
InterruptIn button(BUTTON1);

int cnt=0; 
int cond=0;

void toggle_led() {
    extern int cnt;
    extern int cond;
    led = !led;
    cnt++;
    cond = 1;
}

int main() {
    extern int cnt;
    extern int cond;

    button.fall(callback(&toggle_led));
    
    while (1) {
      if (cond==1) {
        printf("count value %d \n", cnt);
        cond=0;
      }
      wait_ms(500);
    }
}
