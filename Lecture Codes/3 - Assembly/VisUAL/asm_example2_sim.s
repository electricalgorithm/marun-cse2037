		MOV		R0, #0x09
		MOV		R1, #0x11
		MOV		R2, #10
		
		LDR		R3, =0x20000040
		STR		R2, [R3]
		LDR		R0, [R3]