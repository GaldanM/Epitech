section		.text
	global	strcmp:function

strcmp:
			cmp 	rdi, 0
			je		fin_sig
			cmp 	rsi, 0
			je 		fin_sig
			xor		rcx, rcx

loop_strcmp:
			mov		al, [rdi + rcx]
			mov		bl, [rsi + rcx]
			cmp		al, bl
			jne		fin
			cmp		al, 0
			je 		fin
			inc		rcx
			jmp		loop_strcmp
fin:
			sub		al, bl
            cbw
            cwde
            ret

fin_sig:
			xor		eax, eax
			ret