sum_ADDR equ 0x200020

	LDR R0, =sum_ADDR
	MOV R1, #0
	STR R1, [R0]
	LDR R2, =0x20000010
	LDR R3, =0x20000014
	LDR R4, =0x20000018

	LDR R2, [R2]
	LDR R3, [R3]
	LDR R4, [R4]

	MOV R5, #2

adding:
	ADD R1, R1, R2
	ADD R1, R1, R3
	ADD R1, R1, R4
	SUBS R5, R5, #1
	BPL adding
