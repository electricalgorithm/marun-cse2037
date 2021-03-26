       MOV     R0, #0x0A
       MOV     R1, #0x0B

       B       Label

       MOV     R1, #0x00

Label  
       MOV     R1, #0xFF

       ;       ÇALIŞMA MANTIĞI
       ;       R0'a 10 ver.
       ;       R1'e 11 ver.
       ;       "Label" dalına git.
       ;       R1'e 255 ver.
       ;       NOT: R1'e 0 vermediğine dikkat edin.