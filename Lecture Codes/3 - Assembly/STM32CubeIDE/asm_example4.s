.cpu cortex-m0plus
.thumb

.global main

main:

 MOV R0, #0x09
 MOV R1, #11
 MOV R2, #0x0A

//Arithmetic_operation_instructions
 ADD R3, R0, R1
 SUB R4, R2, #0x02
 MOV R5, R2
 MUL R5, R0

//Logic operation instructions
 MOV R0, #0x0
 MOV R1, #0x11
 MOV R2, #0x0A

 AND R1, R1, R2
 ORR R4, R4, R2
 EOR R5, R5, R2
 LSL R6, R0, #2
 LSR R7, R0, #2


//overflow
 MOV R0, #0xFF
 MOV R1, #0x7F

 ADD R2, R1, R0

END: B END

 .end

