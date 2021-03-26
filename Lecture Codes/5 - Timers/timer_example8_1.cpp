#include "mbed.h"

InterruptIn button(BUTTON1);

tm Date;
uint8_t flag = 0;

void trigger(){
    flag = 1;
}

int main()
{
    button.rise(callback(&trigger));   

   set_time(1609921866);  // Set RTC time to Wed, 6 January 2021 11:30

    while (true) {
        if(flag == 1){            
            time_t seconds = time(NULL);
            printf("Current Time = %s\r\n", ctime(&seconds));   
            flag = 0;       
        }
        wait_ms(500);
    }
}