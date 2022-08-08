# produced by SYF compiler:
.WT:
	.string	"%d\n"
.RD:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbp
	pushq	%r8
	pushq	%r9
	movq	%rsp, %rbp
	subq	$4, %rsp
	subq	$4, %rsp
	subq	$8, %rsp
	leaq	.RD(%rip), %rdi
	leaq	-4(%rbp), %rsi
	call	__isoc99_scanf@PLT
	addq	$8, %rsp
	subq	$8, %rsp
	leaq	.RD(%rip), %rdi
	leaq	-8(%rbp), %rsi
	call	__isoc99_scanf@PLT
	addq	$8, %rsp
	subq	$4, %rsp
	movl	-4(%rbp), %r8d
	addl	-8(%rbp), %r8d
	movl	%r8d, -12(%rbp)
	subq	$4, %rsp
	leaq	.WT(%rip), %rdi
	movl	-12(%rbp), %esi
	call	printf@PLT
	addq	$4, %rsp
	movq	%rbp, %rsp
	movl	$0, %eax
	popq	%r9
	popq	%r8
	popq	%rbp
	retq
