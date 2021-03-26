//STM32L4
.global main

MemAddr= 0x20000040 // Memory address
BitBandAddr= 0x22000810 // Bit-band address

main:

//Data moving instructions
 MOV R3, #0x00
 LDR R4, =MemAddr
 STR R3, [R4]

//Bit-band operation
 LDR R5, =BitBandAddr
 LDR R6, [R5]
 MOV R6, #1
 STR R6, [R5]

end: B end

