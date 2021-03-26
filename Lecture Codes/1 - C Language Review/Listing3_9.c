#include "mbed.h"

int main() {

    struct port_str{
        char direction;
        char output;
        char input;
    };

    struct port_str Port1;

    Port1.direction = 0x02;
    Port1.output = 0x04;
    Port1.input = 0x08;

    printf("Port1.direction value is %X\n", Port1.direction);
    printf("Port1.output value is %X\n", Port1.output);
    printf("Port1.input value is %X\n", Port1.input);

    while (1) {
    wait_ms(500);
    }
}



