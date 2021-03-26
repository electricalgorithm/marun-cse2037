        ;if     else
        MOV     R4, #0x07 ; R4 = 0x05
        CMP     R4, #0x06
        BHS     Greater ; Branch if higher or same
        SUB     R4, R4, #1 ; R4 = R4 - 1
        B       Done1
Greater 
        MOV     R4, #0x00 ; R4 = 0x00
Done1   


        ;       ÇALIŞMA MANTIĞI
        ;       R4'e 5 ver.
        ;       R4'i 6'yla kıyasla.
        ;       R4, 6'dan büyük ya da eşitse C'ye 1 yaz ve "Greater" dalına git. R4'e 0 ver.
        ;       Değilse N'ye 1 yaz.
        ;       R4'e R4 ile 1'in çıkarımını ekle.
        ;       "Done1" adlı dala git.