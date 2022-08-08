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
	subq	$144, %rsp
	subq	$4, %rsp
	movl	$1, -148(%rbp)
	subq	$4, %rsp
	movl	$1, -152(%rbp)
.L4:
	movl	-148(%rbp), %r8d
	cmpl	$5, %r8d
	jl		.L0
	jmp		.L2
.L0:
	movl	-152(%rbp), %r8d
	cmpl	$5, %r8d
	jl		.L1
	jmp		.L3
.L1:
	movl	-148(%rbp), %r8d
	movl	-152(%rbp), %r9d
	movl	$6, %r10d
	imull	%r8d, %r10d
	addl	%r9d, %r10d
	movl	-148(%rbp), %r8d
	addl	-152(%rbp), %r8d
	movslq	%r10d, %rsi
	movl	%r8d, -144(%rbp, %rsi, 4)
	movl	-152(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -152(%rbp)
	addq	$0, %rsp
	jmp		.L4
.L2:
.L3:
.L9:
	movl	-148(%rbp), %r8d
	cmpl	$5, %r8d
	jl		.L5
	jmp		.L7
.L5:
	movl	-152(%rbp), %r8d
	cmpl	$6, %r8d
	jl		.L6
	jmp		.L8
.L6:
	movl	-148(%rbp), %r8d
	movl	-152(%rbp), %r9d
	movl	$6, %r10d
	imull	%r8d, %r10d
	addl	%r9d, %r10d
	movl	-148(%rbp), %r8d
	subl	-152(%rbp), %r8d
	movslq	%r10d, %rsi
	movl	%r8d, -144(%rbp, %rsi, 4)
	movl	-148(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -148(%rbp)
	addq	$0, %rsp
	jmp		.L9
.L7:
.L8:
	movl	$7, %r8d
	movslq	%r8d, %rdi
	movl	-144(%rbp, %rdi, 4), %r9d
	movl	$10, %r8d
	movslq	%r8d, %rdi
	movl	-144(%rbp, %rdi, 4), %r10d
	addl	%r10d, %r9d
	movl	$29, %r8d
	movslq	%r8d, %rdi
	movl	-144(%rbp, %rdi, 4), %r10d
	addl	%r10d, %r9d
	subq	$8, %rsp
	leaq	.WT(%rip), %rdi
	movl	%r9d, %esi
	call	printf@PLT
	addq	$8, %rsp
	movq	%rbp, %rsp
	movl	$0, %eax
	popq	%r9
	popq	%r8
	popq	%rbp
	retq
