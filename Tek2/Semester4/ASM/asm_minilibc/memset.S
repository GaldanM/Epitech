section		.text
	global	memset:function

memset:
			cmp		edx, 0
			jl		fin
			cmp		rdi, 0
			je 		fin
			mov		rax, rsi
			xor		rcx, rcx

loop_set:
			cmp		edx, 0
			je		fin
			mov		[rdi + rcx], al
			inc		rcx
			dec		rdx
			jmp		loop_set

fin:
			mov		rax, rdi
			ret