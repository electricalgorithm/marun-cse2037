#include "mbed.h"

/* ### Common Cathode 7 Segment Display Example ###

    Pin Configuration
    D9 ->  MID
    D8 ->  TL
    D7 ->  TM
    D6 ->  TR
    D5 ->  BL
    D4 ->  BM
    D3 ->  BR
    D2 ->  DOT
    
BusOut writes the data vice versa.
MSB is D9 and LSB D2. For using the
dot, make LSB 1.
    
    Numbers as Binaries    
    0 := 0b01111110
    1 := 0b00010010
    2 := 0b10111100
    3 := 0b10110110
    4 := 0b11010010
    5 := 0b11100110
    6 := 0b11101110
    7 := 0b00110010
    8 := 0b11111110
    9 := 0b11110110
*/

// GPIO/Timer Declareations
BusOut disp(D2, D3, D4, D5, D6, D7, D8, D9);
InterruptIn button(USER_BUTTON);
Timer debounceButton;

// Global Variable and Function Declareations
int8_t counter = 0;
uint8_t numbers[10] = {0b01111110, 0b00010010, 0b10111100, 0b10110110,
                       0b11010010, 0b11100110, 0b11101110, 0b00110010,
                       0b11111110, 0b11110110};
void startTiming();
void btn_ISR();
void blinkyNumber(int8_t);

int main() {
    // Assigning an interrupt source for starting the timer.
    button.rise(&startTiming);
    // Assigning an interrupt source to stop the timer and
    // do the pressing action.
    button.fall(&btn_ISR);
    
    while(1) {
        // Counter will be the number which we show in 7 
        // segment display. It's a global 8bit variable.
        counter = 9;
        
        while (counter >= 0) {
            // To understand that why we use a function
            // see function's explaination (comment).
            blinkyNumber(counter);
            counter--;
        }
    }
}

/* To better usage, I have to copy
   counter value to another variable
   so that when the interrupt happens
   there won't be a immidiate change.
   It'll wait for next number. To do
   that, I can use another counter and
   assign it every start of while loop
   or I can use a function because 
   parameters are copied into the memory.
   I have used the function one. */
void blinkyNumber(int8_t c) {
    // Every number change spends 1 second.
    disp.write(numbers[c]);             // Writing only the number.
    wait_ms(250);                       // Delaying for 250ms
    disp.write(numbers[c] + 0b1);       // Writing the number with dot.
    wait_ms(250);                       // Delaying for 250ms.
    disp.write(numbers[c]);             // Writing the number.
    wait_ms(250);                       // Delaying for 250ms.
    disp.write(numbers[c] + 0b1);       // Writing the number with dot.
    wait_ms(250);                       // Delaying for 250ms.
}

// Interrupt Functions
/* Here, I have declared two interrupt
   sources because when we use real
   buttons, there will be bouncing
   actions. In order to prevent it,
   I'm using a timer and count for 150ms,
   if button falls after 150ms, I will
   know that the button hasn't relased
   for 150ms so it's a real button press.
   You can change 150 to anything which
   suits your button's case.
*/
void startTiming() {
    debounceButton.start();
}

void btn_ISR() {
    debounceButton.stop();
    // It's mandatory to change counter as 10
    // because after the function ended, program
    // will decrease it with 1. Expect if it's
    // already in line 62. But it's not possible
    // to do that.
    if (debounceButton.read_ms() > 150) counter = 10;
}