       ;for
       MOV     R4, #0x05
Loop1  
       SUBS    R4, R4, #0x1
       BPL     Loop1 ; ---> BPL: Branch Plus (x >= 0)
       MOV     R4, #0x0A

       ;       ÇALIŞMA MANTIĞI
       ;       R4' 5 ver.
       ;       R4'e R4 ile 1'in çıkarımını ver.
       ;       Eğer R4 pozitif veya 0 ise Loop1'e dallan.
       ;       Eğer değilse R4'e 10 ver.