section		.text
	global 	strcspn:function

strcspn:
			cmp 	rdi, 0
			je		fin_sig
			cmp 	rsi, 0
			je 		fin_sig
			xor		rdx, rdx
			push	255

init:
			mov		bl, [rsi + rdx]
			cmp		bl, 0
			je		search_zero
			xor		ecx, ecx

loop_strcspn:
			mov		al, [rdi + rcx]
			cmp		al, 0
			je		inc_rsi
			cmp		al, bl
			je		found
			inc		rcx
			jmp		loop_strcspn

inc_rsi:
			inc 	rdx
			jmp		init

found:
			pop		rax
			cmp		rax, rcx
			jg		push_to_stack
			push 	rax
			jmp		inc_rsi

push_to_stack:
			push 	rcx
			jmp		inc_rsi

search_zero:
			xor		rcx, rcx

loop_search:
			mov		al, [rdi + rcx]
			cmp		al, 0
			je		cmp_zero
			inc 	rcx
			jmp		loop_search

push_rax:
			push 	rax
			jmp		fin

cmp_zero:
			pop		rax
			cmp 	rax, rcx
			jl		push_rax
			push 	rcx

fin:
			pop		rax
			ret

fin_sig:
			xor		eax, eax
			ret
