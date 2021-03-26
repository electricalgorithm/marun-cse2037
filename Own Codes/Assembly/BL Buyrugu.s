        MOV     R5, #0x05
        MOV     R6, #0x06
        MOV     R7, #0x07
        BL       Replace ; Dallan ama geri dön.
        MOV     R10, #0x1A

        end

Replace 
        MOV     R4, R7
        MOV     R7, R6
        MOV     R6, R5
        MOV     R5, R4
        ;       PC: Program Counter, R15. Adım sayar işlevi.
        ;       LR: R14. BL'nin geri dönme için bıraktığı adım izi.
        MOV     PC, LR

        ;       ÇALIŞMA MANTIĞI
        ;       R5 = 5
        ;       R6 = 6
        ;       R7 = 7
        ;       Replace'e dallan ama geri dön işin bitince.
        ;       R4 = 7
        ;       R7 = 6
        ;       R6 = 5
        ;       R5 = 7
        ;       R10 = 25

        ;-------- BL BUYRUĞU --------;
        ; MOV     LR, #0x14          ;
        ; B       Replace            ;
        ; Yukarıdaki iki komut ile   ;
        ; alttaki komut aynıdır.     ;
        ; BL      Replace            ;
        ;----------------------------;
