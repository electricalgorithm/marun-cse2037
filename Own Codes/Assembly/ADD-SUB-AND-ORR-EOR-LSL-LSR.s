       MOV     R0, #0x09
       MOV     R1, #11
       MOV     R2, #0x0A

       ;Arithmetic_operation_instructions
       ADD     R3, R0, R1
       SUB     R4, R2, #0x02

       ;Logic  operation instructions
       MOV     R0, #0x0
       MOV     R1, #0x11
       MOV     R2, #0x0A
       MOV     R9, #0b0001111

       AND     R1, R1, R2
       ORR     R4, R4, R2
       EOR     R5, R5, R2
       LSL     R6, R9, #2
       LSR     R7, R9, #2

       ;       Çalışma Mantığı
       ;       R0'a 9 ver.
       ;       R1'e 11 ver.
       ;       R2'ye 10 ver.
       ;       R3'e R0 ve R1'in toplamını ver. (20, 00010100)
       ;       R4'e R2 ile 2'nin çıkarmasını ver. (8, 00001000)
       ;       R0'a 0 ver. (00000000)
       ;       R1'e 17 ver. (00010001)
       ;       R2'e 10 ver. (00001010)
       ;       R1'e R1 && R2 ver. (00000000)
       ;       R4'e R4 || R2 ver. (00001010)
       ;       R5'e R5 xor R2 ver. (R5=0, 00001010)
       ;       R6'ya R9'un iki sola kaydırılmışını ver. (00111100)
       ;       R7'e R9'un iki sağ kaydırılmışını ver. (00000011)