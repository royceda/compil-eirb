	.globl	main
	.type	main, @function
main:
	movl	$0, %ebx
	movl	%ebx, %eax
	leave
	ret
	.size	main, .-main
