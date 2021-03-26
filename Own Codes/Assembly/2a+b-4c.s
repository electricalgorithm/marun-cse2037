       ;       2*R0 + R1 - 4*R2 = 130
       ;       We will do the upper operation
       ;       without using MUL and SUB

       ;       Declarations
       MOV     R0, #100;
       MOV     R1, #50;
       MOV     R2, #30;

       ;       Process
       ADD     R3, R0, R0;
       ADD     R3, R3, R1;
       MVN     R2, R2;
       ADD     R2, R2, #1;
       ADD     R3, R3, R2;
       ADD     R3, R3, R2;
       ADD     R3, R3, R2;
       ADD     R3, R3, R2;