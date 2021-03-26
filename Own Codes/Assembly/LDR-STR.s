       MOV     R0, #0x09
       MOV     R1, #0x11
       MOV     R2, #10

       LDR     R3, =0x20000040
       STR     R2, [R3]
       LDR     R0, [R3]

       ;       ÇALIŞMA MANTIĞI
       ;       R0 = 9
       ;       R1 = 17
       ;       R2 = 10
       ;       pointer R3 = 0x20000040 (point mem_addr to R3)
       ;       *R3 = R2 (store R2's value to mem_addr that R3's point)
       ;       (mem_addr = 10)
       ;       R0 = *R3 (store the value from mem_addr to R0)
       ;       (R0 = 10)
