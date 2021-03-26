       ;while
       MOV     R4, #0x06 ; R4 = 0x06
       MOV     R5, #0x02 ; R5 = 0x02
Loop2  
       SUB     R4, R4, #1 ; R4 = R4 - 1
       CMP     R4, R5
       BNE     Loop2

       ;       ÇALIŞMA MANTIĞI
       ;       R4'e 6 ver.
       ;       R5'e 2 ver.
       ;       R4'e R4 ile 1'in çıkarımını ver.
       ;       R4 ile R5'i kıyasla.
       ;       Eşit değilse "Loop2"ye dallan.