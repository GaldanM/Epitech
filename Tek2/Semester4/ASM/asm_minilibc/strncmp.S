section		.text
	global	strncmp:function

strncmp:
			cmp 	rdi, 0
			je		fin_sig
			cmp 	rsi, 0
			je 		fin_sig
			cmp		rdx, 0
			jl		fin_sig
			xor		ecx, ecx

loop_strncmp:
			mov		al, [rdi + rcx]
			mov		bl, [rsi + rcx]
			cmp		al, bl
			jne		fin
			cmp		al, 0
			je 		fin
			inc 	ecx
			cmp		ecx, edx
			jge 	fin
			jmp		loop_strncmp

fin:
			sub		al, bl
            cbw
            cwde
            ret

fin_sig:
			xor		eax, eax
			ret