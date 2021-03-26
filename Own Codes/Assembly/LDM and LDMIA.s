       ;       Arbitrary pre-assignments to
       ;       show the magic.
       MOV     R1, #0x15
       MOV     R2, #0x12
       MOV     R3, #0x14
       MOV     R4, #0x65
       MOV     R5, #0x45
       MOV     R0, #0x200
       STMIA   R0!, {R1, R2, R3, R4, R5}
       ;       Stored some values to memory. Let's delete them.
       ;       The code bellow will fill the R1-R5 with zeros
       ;       Instead of writing "MOV Rx, 0" I did this. You'll
       ;       understand what it does after this line. But for now,
       ;       just know that it clears all the given registers.
       LDMIA   R0!, {R1, R2, R3, R4, R5}


       ;       Load Multiple (Increment After)
       ;       A instruction to get multiple
       ;       values from the memory to registers.
       ;       Increment after means that it will
       ;       assign the (last memory address + 0x4)
       ;       to the register that holds starting point
       ;       after the operation.
       ;
       ;       We need to give a starting point
       ;       for memory to get the values.
       ;
       ;       Usage:
       ;       LDM <startingpoint>, {<stored registers>}
       ;       LDMIA <startingpoint>!, {<stored registers>}
       ;       Note:
       ;       LDM doesn't work in VisUAL2, but you can use LDMIA
       ;       without ! mark on the starting point register.
       MOV     R0, #0x200 ; Starting point for to seek registers.
       LDMIA   R0!, {R8, R9, R10, R11, R12}

