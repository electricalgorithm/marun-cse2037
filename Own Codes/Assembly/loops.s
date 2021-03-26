       ;       A ARM program to calculate
       ;       power, (R1)^R0.
       MOV     R0, #9
       MOV     R1, #2

LOOP   SUB     R0, R0, #1
       ADD     R1, R1, R1
       CMP     R0, #0
       BNE     LOOP