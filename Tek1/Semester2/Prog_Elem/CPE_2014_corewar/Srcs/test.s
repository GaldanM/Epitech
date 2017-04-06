.name "Bonjour"
.comment "JE commente"

l1:
	or	r16,512,r4
	sti   	r6,%:l1,%2
	xor	5,6,r5
	zjmp	%5
	ldi	r5,r5, r5
	aff	r3,4,8,5
	fork	%1
	lfork	%1
	sti	r6,%:l1,%1
	ldi	2,r3,r3
	lldi	5, %4, r5
