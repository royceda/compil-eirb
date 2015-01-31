	.globl	main
	.type	main, @function
main:
	movl	$0, %ebx
	movl	%ebx, %eax
	movl	%eax, 
LBL3:
	movl	(%ebp), %ebx
	add	$1, %ebx
	movl	%ebx, (%ebp)
	movl	%ebx, %eax
	jz	LBL4
	movl	0(%ebp), %ebx
	movl	%ebx, %eax
	movl	%eax, 
	movl	(%ebp), %ebx
	add	$1, %ebx
	movl	%ebx, (%ebp)
	movl	%ebx, %eax
	jmp	LBL3
LBL4:
	.size	main, .-main
