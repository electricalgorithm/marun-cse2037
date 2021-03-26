#include "mbed.h"
 
//https://www.epochconverter.com/ 
//https://www.unixtimestamp.com/index.php
 
int main() {
    set_time(1609912393);  // Set RTC time to Wed, 6 January 2021 8:50
 
    while (true) {
        time_t seconds = time(NULL);
        
        printf("Time as seconds since January 1, 1970 = %d\n", seconds);
        
        printf("Time as a basic string = %s", ctime(&seconds));
 
        char buffer[32];
        strftime(buffer, 32, "%I:%M %p\n", localtime(&seconds));
        printf("Time as a custom formatted string = %s", buffer);
        
        wait(1);
    }
}