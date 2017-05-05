section		.text
	global 	memmove:function

memmove:
			cmp 	rdi, 0
			je		fin_sig
			cmp 	rsi, 0
			je 		fin_sig
			cmp		edx, 0
			jle		fin_sig
			xor		rcx, rcx

loop_copy:
			mov 	al, [rsi + rcx]
			cmp		rdx, 0
			je		move
			push	rax
			inc		rcx
			dec		rdx
			jmp		loop_copy

move:
			pop		rax
			mov 	[rdi + rcx - 1], al
			loop 	move

fin:
			mov 	rax, rdi
			ret

fin_sig:
			xor		eax, eax
			ret