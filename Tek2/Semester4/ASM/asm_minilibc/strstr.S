section		.text
	global	strstr:function

strstr:
			cmp 	rdi, 0
			je		fin_sig
			cmp 	rsi, 0
			je 		fin_sig
			xor		rcx, rcx
			xor		rdx, rdx

loop_strstr:
			mov		al, [rdi + rcx]
			mov		bl, [rsi]
			cmp		al, 0
			je		fin_sig
			cmp		al, bl
			je		test_occur
			inc		rcx
			jmp		loop_strstr

test_occur:
			push	rcx
			
loop_occur:
			inc		rcx
			inc		rdx
			mov		al, [rdi + rcx]
			mov		bl, [rsi + rdx]
			cmp		bl, 0
			je		found
			cmp		al, bl
			je		loop_occur
			pop		rcx
			inc		rcx
			xor		rdx, rdx
			jmp		loop_strstr

found:
			pop		rcx

fin:
			add		rdi, rcx
			mov		rax, rdi
			ret

fin_sig:
			xor		eax, eax
			ret
