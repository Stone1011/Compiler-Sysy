# produced by SYF compiler:
.WT:
	.string	"%d\n"
.RD:
	.string	"%d"
	.text
	.globl	N
	.section	.rodata
	.align	4
	.type	N, @object
	.size	N, 4
N:
	.long	10
	.text
	.bss
	.align	32
	.globl	a
	.type	a, @object
	.size	a, 40
a:
	.zero	40
	.text
	.bss
	.align	32
	.globl	b
	.type	b, @object
	.size	b, 40
b:
	.zero	40
	.text
	.bss
	.align	32
	.globl	c
	.type	c, @object
	.size	c, 40
c:
	.zero	40
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
	movl	$0, -12(%rbp)
.L2:
	movl	-12(%rbp), %r8d
	cmpl	-4(%rbp), %r8d
	jl		.L0
	jmp		.L1
.L0:
	subq	$4, %rsp
	subq	$16, %rsp
	leaq	.RD(%rip), %rdi
	leaq	-16(%rbp), %rsi
	call	__isoc99_scanf@PLT
	addq	$16, %rsp
	movl	-12(%rbp), %r8d
	movl	-16(%rbp), %r9d
	leaq	a, %rdi
	movslq	%r8d, %rsi
	movl	%r9d, (%rdi, %rsi, 4)
	movl	-12(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -12(%rbp)
	addq	$4, %rsp
	jmp		.L2
.L1:
	movl	$0, -12(%rbp)
.L5:
	movl	-12(%rbp), %r8d
	cmpl	-8(%rbp), %r8d
	jl		.L3
	jmp		.L4
.L3:
	subq	$4, %rsp
	subq	$16, %rsp
	leaq	.RD(%rip), %rdi
	leaq	-16(%rbp), %rsi
	call	__isoc99_scanf@PLT
	addq	$16, %rsp
	movl	-12(%rbp), %r8d
	movl	-16(%rbp), %r9d
	leaq	b, %rdi
	movslq	%r8d, %rsi
	movl	%r9d, (%rdi, %rsi, 4)
	movl	-12(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -12(%rbp)
	addq	$4, %rsp
	jmp		.L5
.L4:
	subq	$4, %rsp
	movl	$0, -16(%rbp)
	movl	$0, -12(%rbp)
.L11:
	movl	-12(%rbp), %r8d
	cmpl	-4(%rbp), %r8d
	jl		.L9
	jmp		.L10
.L9:
	movl	$0, -16(%rbp)
.L8:
	movl	-16(%rbp), %r8d
	cmpl	-8(%rbp), %r8d
	jl		.L6
	jmp		.L7
.L6:
	subq	$4, %rsp
	movl	-12(%rbp), %r8d
	leaq	a, %rdi
	movslq	%r8d, %rsi
	movl	(%rdi, %rsi, 4), %r9d
	movl	-16(%rbp), %r8d
	leaq	b, %rdi
	movslq	%r8d, %rsi
	movl	(%rdi, %rsi, 4), %r10d
	imull	%r10d, %r9d
	movl	%r9d, -20(%rbp)
	movl	-12(%rbp), %r8d
	addl	-16(%rbp), %r8d
	movl	-12(%rbp), %r9d
	addl	-16(%rbp), %r9d
	leaq	c, %rdi
	movslq	%r9d, %rsi
	movl	(%rdi, %rsi, 4), %r10d
	addl	-20(%rbp), %r10d
	leaq	c, %rdi
	movslq	%r8d, %rsi
	movl	%r10d, (%rdi, %rsi, 4)
	movl	-16(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -16(%rbp)
	addq	$4, %rsp
	jmp		.L8
.L7:
	movl	-12(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -12(%rbp)
	addq	$0, %rsp
	jmp		.L11
.L10:
	movl	$0, -12(%rbp)
.L14:
	movl	-4(%rbp), %r8d
	addl	-8(%rbp), %r8d
	subl	$1, %r8d
	cmpl	%r8d, -12(%rbp)
	jl		.L12
	jmp		.L13
.L12:
	movl	-12(%rbp), %r8d
	leaq	c, %rdi
	movslq	%r8d, %rsi
	movl	(%rdi, %rsi, 4), %r9d
	subq	$16, %rsp
	leaq	.WT(%rip), %rdi
	movl	%r9d, %esi
	call	printf@PLT
	addq	$16, %rsp
	movl	-12(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -12(%rbp)
	addq	$0, %rsp
	jmp		.L14
.L13:
	movq	%rbp, %rsp
	movl	$0, %eax
	popq	%r9
	popq	%r8
	popq	%rbp
	retq
