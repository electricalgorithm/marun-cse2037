		;if		else
		MOV		R4, #0x05 ; R4 = 0x05
		CMP		R4, #0x06
		BHS		Greater ; Branch if higher or same
		SUB		R4, R4, #1 ; R4 = R4 - 1
		B		Done1
Greater
		ADD		R4, R4, #1 ; R4 = R4 + 1
Done1
		
		;for
		MOV		R4, #0x0A ; R4 = 0x0A
Loop1
		SUB		R4, R4, #1 ; R4 = R4 - 1
		BPL		Loop1
		
		;while
		MOV		R4, #0x06 ; R4 = 0x06
		MOV		R5, #0x02 ; R5 = 0x02
Loop2
		SUB		R4, R4, #1 ; R4 = R4 - 1
		CMP		R4, R5
		BNE		Loop2
