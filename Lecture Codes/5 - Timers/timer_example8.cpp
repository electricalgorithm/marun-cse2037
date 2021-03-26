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

    Date.tm_year = 120;
    Date.tm_mon  = 6;
    Date.tm_mday = 31;
    Date.tm_hour = 18;
    Date.tm_min  = 18;
    Date.tm_sec  = 18;
    set_time(mktime(&Date));

    while (true) {
        if(flag == 1){            
            time_t seconds = time(NULL);
            printf("Current Time = %s\r\n", ctime(&seconds));   
            flag = 0;       
        }
        wait_ms(500);
    }
}