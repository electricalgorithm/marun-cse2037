		MOV		R0, #0x09
		MOV		R1, #11
		MOV		R2, #0x0A
		
		;Arithmetic_operation_instructions
		ADD		R3, R0, R1
		SUB		R4, R2, #0x02
		
		;Logic	operation instructions
		MOV		R0, #0x0
		MOV		R1, #0x11
		MOV		R2, #0x0A
		
		AND		R1, R1, R2
		ORR		R4, R4, R2
		EOR		R5, R5, R2
		LSL		R6, R0, #2
		LSR		R7, R0, #2
