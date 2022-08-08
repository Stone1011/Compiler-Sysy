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
	.long	3
	.text
	.bss
	.align	32
	.globl	a
	.type	a, @object
	.size	a, 36
a:
	.zero	36
	.text
	.globl	f
	.type	main, @function
f:
	endbr64
	pushq	%rbp
	pushq	%r8
	pushq	%r9
	movq	%rsp, %rbp
	subq	$4, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %r8d
	cmpl	$1, %r8d
	je		.L0
	jmp		.L1
.L0:
	movq	%rbp, %rsp
	movl	$1, %eax
	popq	%r9
	popq	%r8
	popq	%rbp
	retq
	addq	$0, %rsp
.L1:
	subq	$4, %rsp
	movl	$1, -8(%rbp)
	movl	-4(%rbp), %r8d
	subl	$1, %r8d
	movl	%r8d, %edi
	subq	$8, %rsp
	call	f
	addq	$8, %rsp
	imull	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
	movq	%rbp, %rsp
	movl	-8(%rbp), %eax
	popq	%r9
	popq	%r8
	popq	%rbp
	retq
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
	movl	$10, %edi
	subq	$12, %rsp
	call	f
	addq	$12, %rsp
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %r9d
	cmpl	$3628800, %r9d
	jne		.L6
	jmp		.L2
.L2:
	movl	-4(%rbp), %r9d
	testl	%r9d, %r9d
	jnz		.L7
	jmp		.L8
.L6:
.L7:
	subq	$12, %rsp
	leaq	.WT(%rip), %rdi
	movl	$2333, %esi
	call	printf@PLT
	addq	$12, %rsp
	movl	-4(%rbp), %r9d
	testl	%r9d, %r9d
	jz		.L3
	jmp		.L4
.L3:
	movl	-4(%rbp), %r9d
	subl	$10, %r9d
	movl	%r9d, -4(%rbp)
	addq	$0, %rsp
	jmp		.L5
.L4:
	movl	-4(%rbp), %r9d
	addl	$10, %r9d
	movl	%r9d, -4(%rbp)
	addq	$0, %rsp
.L5:
	addq	$0, %rsp
	jmp		.L9
.L8:
	subq	$12, %rsp
	leaq	.WT(%rip), %rdi
	movl	-4(%rbp), %esi
	call	printf@PLT
	addq	$12, %rsp
	addq	$0, %rsp
.L9:
	subq	$12, %rsp
	leaq	.WT(%rip), %rdi
	movl	-4(%rbp), %esi
	call	printf@PLT
	addq	$12, %rsp
	subq	$4, %rsp
	movl	$0, -8(%rbp)
	subq	$4, %rsp
	movl	$0, -12(%rbp)
.L16:
	movl	-8(%rbp), %r9d
	cmpl	$3, %r9d
	jle		.L14
	jmp		.L15
.L14:
	movl	-8(%rbp), %r9d
	cmpl	$1, %r9d
	je		.L10
	jmp		.L11
.L10:
	movl	-8(%rbp), %r9d
	addl	$1, %r9d
	movl	%r9d, -8(%rbp)
	jmp		.L18
	addq	$0, %rsp
.L11:
	movl	-8(%rbp), %r9d
	cmpl	$3, %r9d
	je		.L12
	jmp		.L13
.L12:
	jmp		.L17
	addq	$0, %rsp
.L13:
	subq	$4, %rsp
	leaq	.WT(%rip), %rdi
	movl	-8(%rbp), %esi
	call	printf@PLT
	addq	$4, %rsp
	movl	-8(%rbp), %r9d
	addl	$1, %r9d
	movl	%r9d, -8(%rbp)
.L18:
	addq	$0, %rsp
	jmp		.L16
.L15:
.L17:
	subq	$36, %rsp
	movl	$1, -8(%rbp)
	movl	-8(%rbp), %r9d
	addl	-8(%rbp), %r9d
	movl	%r9d, -12(%rbp)
	movl	$0, %r9d
	movl	-12(%rbp), %r10d
	imull	$2, %r10d
	addl	-8(%rbp), %r10d
	movslq	%r9d, %rsi
	movl	%r10d, -48(%rbp, %rsi, 4)
	movl	-8(%rbp), %r9d
	movl	-12(%rbp), %r10d
	movl	$3, %r11d
	imull	%r9d, %r11d
	addl	%r10d, %r11d
	movslq	%r11d, %rsi
	movl	$3, -48(%rbp, %rsi, 4)
	movl	$0, %r9d
	movslq	%r9d, %rdi
	movl	-48(%rbp, %rdi, 4), %r10d
	subq	$16, %rsp
	leaq	.WT(%rip), %rdi
	movl	%r10d, %esi
	call	printf@PLT
	addq	$16, %rsp
	movl	-8(%rbp), %r9d
	movl	-12(%rbp), %r11d
	movl	$3, %eax
	imull	%r9d, %eax
	addl	%r11d, %eax
	movslq	%eax, %rdi
	movl	-48(%rbp, %rdi, 4), %r9d
	subq	$16, %rsp
	leaq	.WT(%rip), %rdi
	movl	%r9d, %esi
	call	printf@PLT
	addq	$16, %rsp
	subq	$4, %rsp
	movl	-8(%rbp), %r11d
	movl	-12(%rbp), %eax
	movl	$3, %ebx
	imull	%r11d, %ebx
	addl	%eax, %ebx
	movslq	%ebx, %rdi
	movl	-48(%rbp, %rdi, 4), %r11d
	movl	$0, %eax
	movslq	%eax, %rdi
	movl	-48(%rbp, %rdi, 4), %ebx
	addl	%ebx, %r11d
	movl	%r11d, -52(%rbp)
	subq	$12, %rsp
	leaq	.WT(%rip), %rdi
	movl	-52(%rbp), %esi
	call	printf@PLT
	addq	$12, %rsp
	movl	$0, %r11d
	leaq	a, %rdi
	movslq	%r11d, %rsi
	movl	$5, (%rdi, %rsi, 4)
	movl	$4, %r11d
	leaq	a, %rdi
	movslq	%r11d, %rsi
	movl	$2, (%rdi, %rsi, 4)
	movl	$0, %r11d
	leaq	a, %rdi
	movslq	%r11d, %rsi
	movl	(%rdi, %rsi, 4), %eax
	subq	$12, %rsp
	leaq	.WT(%rip), %rdi
	movl	%eax, %esi
	call	printf@PLT
	addq	$12, %rsp
	movl	$4, %r11d
	leaq	a, %rdi
	movslq	%r11d, %rsi
	movl	(%rdi, %rsi, 4), %ebx
	subq	$12, %rsp
	leaq	.WT(%rip), %rdi
	movl	%ebx, %esi
	call	printf@PLT
	addq	$12, %rsp
	movl	$4, %r11d
	leaq	a, %rdi
	movslq	%r11d, %rsi
	movl	(%rdi, %rsi, 4), %ecx
	subq	$12, %rsp
	leaq	.WT(%rip), %rdi
	movl	%ecx, %esi
	call	printf@PLT
	addq	$12, %rsp
	movq	%rbp, %rsp
	movl	$0, %eax
	popq	%r9
	popq	%r8
	popq	%rbp
	retq
