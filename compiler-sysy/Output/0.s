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
	.long	100
	.text
	.bss
	.align	32
	.globl	a
	.type	a, @object
	.size	a, 400
a:
	.zero	400
	.text
	.globl	func
	.type	main, @function
func:
	endbr64
	pushq	%rbp
	pushq	%r8
	pushq	%r9
	movq	%rsp, %rbp
	subq	$4, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %r8d
	cmpl	$1, %r8d
	je		.L1
	jmp		.L0
.L0:
	movl	-4(%rbp), %r8d
	cmpl	$0, %r8d
	je		.L2
	jmp		.L3
.L1:
.L2:
	movq	%rbp, %rsp
	movl	$1, %eax
	popq	%r9
	popq	%r8
	popq	%rbp
	retq
	addq	$0, %rsp
	jmp		.L4
.L3:
	movl	-4(%rbp), %r8d
	subl	$1, %r8d
	movl	%r8d, %edi
	subq	$12, %rsp
	call	func
	addq	$12, %rsp
	movl	-4(%rbp), %r9d
	subl	$2, %r9d
	movl	%r9d, %edi
	subq	$12, %rsp
	call	func
	addq	$12, %rsp
	addl	%eax, %eax
	movq	%rbp, %rsp
	movl	%eax, %eax
	popq	%r9
	popq	%r8
	popq	%rbp
	retq
	addq	$0, %rsp
.L4:
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
	movl	$10, -4(%rbp)
	movl	$0, %r10d
	movl	-4(%rbp), %r11d
	addl	$2, %r11d
	movl	%r11d, %edi
	subq	$12, %rsp
	call	func
	addq	$12, %rsp
	leaq	a, %rdi
	movslq	%r10d, %rsi
	movl	%eax, (%rdi, %rsi, 4)
	movq	%rbp, %rsp
	movl	$0, %eax
	popq	%r9
	popq	%r8
	popq	%rbp
	retq
