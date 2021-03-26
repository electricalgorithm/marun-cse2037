       MOV     R10, #0x200;
       STR     R10, [SP]
       ;       Set the stack pointer 0x200
       ;       It'll be inverse stack.

       ;       Initial Condinition for Looping
       MOV     R0, #0x1

LOOP   
       ;       Store R0 value to stack pointer adress
       STRB    R0, [SP]
       ;       Add 0x1 to R0 register
       ADD     R0, R0, #0x1
       ;       Add 0x1 to stack pointers address
       ADDS    SP, SP, #0x1
       ;       If R0 != 0x20, goto LOOP
       CMP     R0, #0x20
       BNE     LOOP