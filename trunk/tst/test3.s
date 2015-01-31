	.globl	f
	.type	f, @function
f:
	movl	$5, %ebx
	movl	%ebx, %eax
	movl	%eax, 
	.size	f, .-f
	.globl	main
	.type	main, @function
main:
	movl	$0, %ebx
	movl	%ebx, %eax
	leave
	ret
	.size	main, .-main
