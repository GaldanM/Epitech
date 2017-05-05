section		.text
	global	strchr:function

strchr:
			cmp		rdi, 0
			jle		fin_sig

loop_strchr:	
			mov		bl, [rdi]
			mov		edx, esi
			cmp		bl, dl
			je		fin_sig
			cmp		bl, 0
			jle		fin
			inc		rdi
			jmp		loop_strchr

fin:
			mov	rax, rdi
			ret

fin_sig:
			xor	rax, rax
			ret
