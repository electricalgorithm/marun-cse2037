        ;if     else
        MOV     R4, #0x05 ; R4 = 0x05
        CMP     R4, #0x06
        BHS     Greater ; Branch if higher or same
        SUB     R4, R4, #1 ; R4 = R4 - 1
        B       Done1
Greater 
        ADD     R4, R4, #1 ; R4 = R4 + 1
Done1   

        ;for
        MOV     R4, #0x0A ; R4 = 0x0A
Loop1   
        SUB     R4, R4, #1 ; R4 = R4 - 1
        BPL     Loop1 ; Branch if positive number or zero

        ;while
        MOV     R4, #0x06 ; R4 = 0x06
        MOV     R5, #0x02 ; R5 = 0x02
Loop2   
        SUB     R4, R4, #1 ; R4 = R4 - 1
        CMP     R4, R5
        BNE     Loop2

        ;       ÇALIŞMA MANTIĞI
        ;       R4'e 5 ver.
        ;       R4 ile 6'yı kıyasla.
        ;       Büyükse ya da eşitse "Greater"a dallan. (Gitmeyecek bu değerler ile.)
        ;       R4'e R4 ile 1'in çıkarımını ver.
        ;       "Done1"e dallan.
        ;       R4'e 10 ver.
        ;       R4'e R4 ile 1'in çıkarımını ver.
        ;       Eğer R4 >= 0 ise "Loop1"e dallan.
        ;       R4'e 6 ver.
        ;       R5'e 2 ver.
        ;       R4'e R4 ile 1'in çıkarımını ver.
        ;       R4 ile R5'i kıyasla.
        ;       Eşit değillerse "Loop2"ye dallan.
