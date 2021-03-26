#include "mbed.h"

int main() {

    struct port_str{
        char direction;
        char output;
        char input;
    };

    struct port_str Port1;
    struct port_str* Port1_ptr;

    Port1_ptr = &Port1;

    Port1_ptr -> direction = 0x02;
    Port1_ptr -> output = 0x04;
    Port1_ptr -> input = 0x08;

    printf("Port1.direction value is %X\n", Port1.direction);
    printf("Port1.output value is %X\n", Port1.output);
    printf("Port1.input value is %X\n", Port1.input);

    printf("\n");
    printf("Address pointed by Port1_ptr is %p\n", (void*)Port1_ptr);
    printf("Address of Port1_ptr itself is %p\n", (void*)&Port1_ptr);

    //CHECK
    printf("\n");
    printf("Address pointed by Port1_ptr direction is %p\n", (void*)&Port1_ptr->direction);
    printf("Address pointed by Port1_ptr direction is %p\n", (void*)&Port1_ptr->output);
    printf("Address pointed by Port1_ptr direction is %p\n", (void*)&Port1_ptr->input);
        
    while (1) {
    wait_ms(500);
    }
}

