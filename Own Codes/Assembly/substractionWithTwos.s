       MOV     R0, #0b10001; First number
       MOV     R1, #0b01000; Second number

       ;       Substraction with using two's compliment
       MVN     R2, R1; Getting one's compliment
       ADD     R2, R2, #1; Getting two's compliment

       ;       Substraction happens below
       ADD     R3, R0, R2;
       ;       Answer is 17 - 8 = 9
