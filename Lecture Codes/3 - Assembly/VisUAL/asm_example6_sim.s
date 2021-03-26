		MOV		R5, #0x05
		MOV		R6, #0x06
		MOV		R7, #0x07
		BL		Replace
		
		end
		
Replace
		MOV		R4, R7
		MOV		R7, R6
		MOV		R6, R5
		MOV		R5, R4
		MOV		PC,LR
