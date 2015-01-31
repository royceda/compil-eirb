	.globl	fun
	.type	fun, @function
fun:
	movl	0(%ebp), %ebx
	movl	%ebx, %eax
	pushl	%eax
	movl	$10, %ebx
	movl	%ebx, %eax
	popl	%eax
	add	%ebx, %eax
	movl	%eax, 
	.size	fun, .-fun
	.globl	main
	.type	main, @function
main:
	movl	$0, %ebx
	movl	%ebx, %eax
	leave
	ret
	.size	main, .-main
