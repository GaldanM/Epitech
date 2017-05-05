section		.text
	global	rindex:function

rindex:
			cmp		rdi, 0
			je		fin_sig
			mov		rdx, rsi
			xor		rcx, rcx

start:
			mov		bl, [rdi + rcx]
			cmp		bl, dl
			je		fin
			cmp		bl, 0
			je		fin_sig
			inc		rcx
			jmp		start

fin:
			add		rdi, rcx
			mov		rax, rdi
			ret

fin_sig:
			xor		rax, rax
			ret