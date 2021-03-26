       ;       Bu dosyayı dallanmaya tekrar olması için hazırladım.
       ;
       ;--------- BUYRUK LİSTESİ ---------
       ;       B : Dallan. (1 operand)
       ;       BL : Dallan ve geri dön. (1 operand)
       ;       CMP : Karşılaştırma, SUB ile. (2 operand)
       ;       CMN : Karşılaştırma, ADD ile. (2 operand)
       ;       TST : Karşılaştırma, AND ile. (2 operand)
       ;       TEQ : Karşılaştırma, EOR ile. (2 operand)
       ;
       ;       Not: Buyruğun sonuna eklenen -S takısı
       ;       yapılan işlemin bayraklara işlenmesini
       ;       sağlar. Örn, SUBS ADDS.
       ;
       ;--------- BAYRAK LİSTESİ ---------
       ;       N : Negative
       ;       The N flag is set by an instruction
       ;       if the result is negative.
       ;
       ;       Z : Zero
       ;       The Z flag is set if the result of
       ;       the flag-setting instruction is zero.
       ;
       ;       C : Carry (or Unsigned Overflow)
       ;       The C flag is set if the result of
       ;       an unsigned operation overflows the
       ;       32-bit result register. This bit can
       ;       be used to implement 64-bit unsigned
       ;       arithmetic, for example.
       ;
       ;       V : Signed Overflow
       ;       The V flag works the same as the C
       ;       flag, but for signed operations. For
       ;       example, 0x7fffffff is the largest
       ;       positive two's complement integer that
       ;       can be represented in 32 bits, so
       ;       0x7fffffff + 0x7fffffff triggers a
       ;       signed overflow, but not an unsigned
       ;       overflow (or carry): the result,
       ;       0xfffffffe, is correct if interpreted
       ;       as an unsigned quantity, but represents
       ;       a negative value (-2) if interpreted as
       ;       a signed quantity.
       ;
       ;       Example:
       ;       | ldr r1, =0xffffffff
       ;       | ldr r2, =0x00000001
       ;       | adds r0, r1, r2
       ;       Negative=0, Zero=1, Carry=1, V=0
       ;
       ;--------- ŞART BUYRUK EKLERİ LİSTESİ ---------
       ;       (Ek):(Anlam):(Baktığı Durum)
       ;
       ;       eq : equal : Z==1
       ;       ne : not equal : Z==0
       ;       cs/hs : unsigned higher or same : C==1
       ;       cc/lo : unsigned lower : C==0
       ;       mi : negative : N==1
       ;       pl : positive or zero : N==0
       ;       vs : signed overflow : V==1
       ;       vc : no signed overflow : V==0
       ;       hi : unsigned higher : (C==1) && (Z==0)
       ;       ls : unsigned lower or same : (C==0) || (Z==1)
       ;       ge : signed greater than equal : N==V
       ;       lt : signed less then : N!=V
       ;       gt : signed greater then : (Z==0) && (N==V)
       ;       le : signed less then equal : (Z==1) || (N!=V)
       ;       al : always executed : (None)
       ;
       ;       Bu komut eklemelerini normal (add, sub)
       ;       ile de kullanabiliriz. Branchlemeye gerek
       ;       kalmadan bunu yaparsak bytelardan tasarruf
       ;       etmiş oluruz.
       ;       Örnek:
       ;       | cmp     r0, #10
       ;       | movhs   r0, #10
       ;       | addlo   r0, r0, #1


       MOV     R0, #0
       ANDS    R1, R0, #1
