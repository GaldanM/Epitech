section		.text
	global 	strpbrk:function

strpbrk:
			push	rsi
			cmp 	rdi, 0
			je		fin
			cmp 	rsi, 0
			je 		fin

get_al:
			mov		al, [rdi]
			
compare_al:
			mov		bl, [rsi]
			cmp 	al, bl
			je		fin_found
			cmp 	bl, 0
			je		inc_al
			inc 	rsi
			jmp		compare_al

inc_al:
			inc 	rdi
			mov		cl, [rdi]
			cmp 	cl, 0
			je		fin
			pop		rsi
			push	rsi
			jmp		get_al

fin_found:
			mov		rax, rdi
			pop		rsi
			ret

fin:
			xor		eax, eax
			pop		rsi
			ret