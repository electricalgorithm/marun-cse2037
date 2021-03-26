.cpu cortex-m0plus
.thumb

.global main

main:

 MOV R0, #0x09; R0 = 0x09
 MOV R1, #0x11; R1 = 0x0B
 MOV R2, #10; R2 = 0x0A

 LDR R3, =0x20000040;
 STR R2, [R3];
 LDR R0, [R3];

END: B END

.end

