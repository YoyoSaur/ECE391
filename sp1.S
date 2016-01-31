	/* TODO:
		ask TA about data types, maybe words for int?
		ask TA about stack
		ask TA about jumps
	*/
	/* Important people: Ben Miller, Grant Everett */
	/* Not so much: Jett Wang, Brandon Youseff, Ted */
	/* save registers */
	/* linear plan of attack good practice in x86 */
	pushl %ecx
	pushl %edx
	pushl %ebx
	/* get parameters */
	/* 16 for three on stack and return address */
	movl $16(%esp), %edx # for arg
	movl $20(%esp), %eax # for bitmask
	/* move stack pointer */
	#addl $12, %esp
	/* get arguments */
	#popl %edx # for arg
	#popl %eax # for bitmask
	/* reset stack pointer */
	#subl $20, %esp
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
	pushl %eax
	pushl %edx
	call *jump_table(, %ecx, 4) # array lookup
	/* does this set return value */
	addl 4, %esp # move stack pointer down
	/* restore registers */
	popl %eax
	popl %ebx
	popl %edx
	popl %ecx
	ret
bit_shift:
	shll $1, %ebx
	incl %ecx
	jmp for_loop
return:
	/* restore registers */
	popl %ebx
	popl %edx
	popl %ecx
	xorl %eax, %eax
	ret
