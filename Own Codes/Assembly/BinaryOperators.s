       ;       This program is an example
       ;       for binary operations.
       MOV     R0, #0b1010
       MOV     R1, #0b0110

       ORR     R2, R0, R1; OR, R2 := 1110
       EOR     R3, R0, R1; XOR, R3 := 1100
       AND     R4, R0, R1; AND, R4 := 0010

       ;       Odd/Even Test
       ;       Look for last bit. 0: Odd, 1: Even.
       MOV     R5, #5;
       ADD     R5, R5, #1;

       ;       Dividible by 8
       ;       Look for last bit. 0: not, 1: dividable.
       MOV     R6, #64
       ADD     R6, R6, #0b111;

       ;       How to do EOR by yourself
       MOV     R7, #0b1010
       MOV     R8, #0b1000
       MVN     R8, R8;
       AND     R9, R7, R8;
       MVN     R9, R9;

       EOR     R10, R7, R8; To check if it's okey.