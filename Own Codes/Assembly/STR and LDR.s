       ;       Look to memory in binary


       MOV     R0, #120
       MOV     R1, #0x100
       MOV     R5, #0x1

       ;STRB   is for offset of (x1 byte)
       STRB    R5, [R1, #1]
       STRB    R5, [R1, #2]

       ;STRH   is for offset of (x1 halfword)
       ;       desteklenmiyor!

       ;STR    is for offset of (x1 word)
       ;       If you do this operation after before
       ;       stb's, the memory will be erased.
       ;       Run step by step.
       STR     R0, [R1]

       MOV     R2, #0x1FFFFFF
       MOV     R3, #0x120
       STRB    R2, [R3, #0x1]

       LDRB    R6, [R3, #0x1]

       STR     R7, [SP]
