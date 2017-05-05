section		.text
	global	memcpy:function

memcpy:
			cmp		rdi, 0
			je 		fin
			cmp 	rsi, 0
			je 		fin
			cmp		edx, 0
			jle		fin
			xor		rcx, rcx

loop_cpy:
			cmp		rdx, 0
			je 		fin
			mov		al, [rsi + rcx]
			cmp		al, 0
			je		fin
			mov		[rdi + rcx], al
			inc		rcx
			dec		rdx
			jmp		loop_cpy

fin:
			mov		rax, rdi
			ret