section		.text
	global 	strlen:function

strlen:
		xor 	ecx, ecx
		cmp		rdi, 0
		je		fin

count:
		mov		bl, [rdi + rcx]
		cmp		bl, 0
		je		fin
		inc		rcx
		jmp		count

fin:
		mov		eax, ecx
		ret