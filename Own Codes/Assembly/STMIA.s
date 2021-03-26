       ;       Arbitrary pre-assignments to
       ;       show the magic.
       MOV     R1, #0x15
       MOV     R2, #0x12
       MOV     R5, #0x14
       MOV     R6, #0x65
       MOV     R7, #0x45

       ;       Store Multiple Increment After
       ;       A instruction to store multiple
       ;       values from the registers to memory.
       ;
       ;       We need to give a starting point
       ;       for memory to store the values.
       ;
       ;       Usage:
       ;       STMIA <startingpoint>!, {<stored registers>}
       MOV     R0, #0x200
       STMIA   R0!, {R1, R2, R5, R6, R7}
       ;       R0 will be (the_last_address_of_memory + 4)