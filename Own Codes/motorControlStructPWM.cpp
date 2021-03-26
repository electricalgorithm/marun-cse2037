#include "mbed.h"

#define WAIT_VAL 20
#define VCC 5

PwmOut output(p21);
AnalogIn speedometer(p15);

int main(){
    
    struct DC_motor {
        float speed;
        char pinNum;
        bool direction;
    };
    
    // Creating a struct and struct pointer.
    struct DC_motor motor_in_pin21;
    struct DC_motor* motor;
    
    // Assigning motor pointer to the struct motor_in_pin21
    motor = &motor_in_pin21; 
    
    // Motor initilization
    motor -> direction = true; // Which is output.
    motor -> pinNum = 21;
    motor -> speed = output.read();
    
    float previousSpeed = speedometer.read();
    while (true) {
        if (speedometer.read() != previousSpeed) {
            // Speed as Volts since it's linear.
            motor -> speed = speedometer;
        }
        
        output.write(motor -> speed);
        printf("Speed: %.2f", motor_in_pin21.speed);
        
        wait_ms(WAIT_VAL);
    }
}