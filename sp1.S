	/* Important people: Ben Miller */
	/* Not so much: Jett, Youseff, Ted */
	/* Not at all: Grant */
	/* save registers */
	pushl %ecx
	pushl %edx
	pushl %ebx
	/* move stack pointer */
	addl $12, %esp
	/* get arguments */
	popl %edx # for arg
	popl %eax # for bitmask
	/* reset stack pointer */
	subl $18, %esp
	/* init registers */
	xorl %ecx, %ecx # for i counter
	xorl %ebx, %ebx # for bit
	incl %ebx # sets bit to 1
	/* for loop */
for_loop:
	cmpl $32, %ecx # compare for for loop
	jnb return
	testl %ebx, %ecx # sets flags
	jne bit_shift
	pushl %edx
	call *jump_table(, %ecx, 4) # array lookup
	addl 4, %esp # move stack pointer down
	/* restore registers */
	popl %ebx
	popl %edx
	popl %ecx
	ret
bit_shift:
	shll $1, %ebx
	jmp for_loop
return:
	/* restore registers */
	popl %ebx
	popl %edx
	popl %ecx
	xorl %eax, %eax
	ret