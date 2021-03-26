Mem_Addr equ     0x20000040

         MOV     R0, #0x09
         MOV     R1, #0xAA
         MOV     R2, #0xFA

         ;LDR    R3, =0x20000040
         LDR     R3, =Mem_Addr
         STR     R2, [R3]
         LDR     R0, [R3]

         MOV     R2, #00
         STR     R1, [R3, R2]

         ADD     R2, R2, #0x04
         STR     R1, [R3, R2]

         ;       Çalışma Mantığı
         ;       Mem_Addr = 0x20000040
         ;       R0 = 9
         ;       R1 = 170
         ;       R2 = 250
         ;       (pointer)*R3 = (Mem_Addr)
         ;       *R3 = 250
         ;       R0 = *R3 (R0 = 250)
         ;       R2 = 0
         ;       *(R3+R2) = R1 (0x20000040 = 170)
         ;       R2 = R2 + 4 (R2 = 4)
         ;       *(R3+R2) = 170 (0x20000044 = 170)