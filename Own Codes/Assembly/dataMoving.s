Mem_Addr    equ     0x20000040
BitBandAddr equ     0x22000810

            ;       Data moving instructions
            MOV     R3, #0x00
            LDR     R4, =Mem_Addr
            STR     R3, [R4]

            ;       Bit-band operation
            LDR     R5, =BitBandAddr
            LDR     R6, [R5]
            MOV     R6, #1
            STR     R6, [R5]

            ;       ÇALIŞMA MANTIĞI
            ;       R3 = 0
            ;       pointer R4 = 0x20000040
            ;       *R4 = 0
            ;
            ;       pointer R5 = 0x22000810
            ;       R6 = *R5
            ;       R6 = 1
            ;       *R5 = 1