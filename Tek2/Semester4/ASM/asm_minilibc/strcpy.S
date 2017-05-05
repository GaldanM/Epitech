section		.text
	global 	strcpy:function

strcpy:
			cmp		rdi, 0
			je		fin
			cmp		rsi, 0
			je		fin
			xor		rcx, rcx

loop_strcpy:
			mov		al, [rsi + rcx]
			mov		[rdi + rcx], al
			cmp		al, 0
			je		fin
			inc		rcx
			jmp		loop_strcpy

fin:
			mov	rax, rdi
			ret