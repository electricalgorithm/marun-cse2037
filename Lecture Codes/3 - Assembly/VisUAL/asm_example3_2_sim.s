Mem_Addr	equ		0x20000040
		
		LDR		R0, =Mem_Addr
		
		LDR		R1, =0xF0F1F2F3
		
		STR		R1, [R0]
		LDR		R2, [R0]
		
		MOV		R3, #00
		STR		R1, [R0, R3]
		
		ADD		R3, R3, #0x04
		STR		R1, [R0, R3]
		
		LDR		R4, =0xFF000000
		MOV		R5,R4
		AND		R5, R5, R1
		
		LSR		R6, R5, #8
		
		
		LDR		R4, =0x000000FF
		MOV		R7,R4
		ORR		R7, R7, R1
		
		LSL		R7, R7, #8