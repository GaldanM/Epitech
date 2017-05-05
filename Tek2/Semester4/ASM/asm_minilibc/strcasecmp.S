section		.text
	global	strcasecmp:function

strcasecmp:
			cmp 	rdi, 0
			je		fin_sig
			cmp 	rsi, 0
			je 		fin_sig
			mov		ecx, 32

loop_strcase:
			mov		al, [rdi]
			mov		bl, [rsi]

check_a_maj:
			cmp 	al, 'A'
			jl		compare

check_a_maj2:
			cmp 	al, 'Z'
			jg		check_b_maj
			add		al, cl

check_b_maj:
			cmp 	bl, 'A'
			jl		compare

check_b_maj2:
			cmp 	bl, 'Z'
			jg		compare
			add 	bl, cl

compare:
			cmp		al, bl
			jne		fin
			cmp		al, 0
			je 		fin
			inc		rdi
			inc		rsi
			jmp		loop_strcase

fin:
			sub		al, bl
            cbw
            cwde
            ret

fin_sig:
			xor		eax, eax
			ret