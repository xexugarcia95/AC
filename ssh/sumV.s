	.file	"sumV.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Faltan no componentes del vector"
	.align 8
.LC3:
	.string	"Tiempo(seg.):%11.9f\t / Tama\303\261o Vectores:%u\n"
	.align 8
.LC4:
	.string	"/ V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	cmpl	$1, %edi
	jle	.L15
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	movq	%rax, %rbx
	movl	%eax, %r12d
	movl	%eax, %eax
	leaq	22(,%rax,8), %rcx
	shrq	$4, %rcx
	salq	$4, %rcx
	subq	%rcx, %rsp
	movq	%rsp, %r14
	subq	%rcx, %rsp
	movq	%rsp, %r15
	subq	%rcx, %rsp
	testl	%ebx, %ebx
	movq	%rsp, %r13
	je	.L3
	cvtsi2sdq	%rax, %xmm1
	xorl	%ecx, %ecx
	movsd	.LC1(%rip), %xmm3
	mulsd	%xmm3, %xmm1
	.p2align 4,,10
	.p2align 3
.L7:
	cvtsi2sd	%ecx, %xmm0
	movapd	%xmm1, %xmm4
	mulsd	%xmm3, %xmm0
	movapd	%xmm0, %xmm2
	subsd	%xmm0, %xmm4
	addsd	%xmm1, %xmm2
	movsd	%xmm4, (%r15,%rcx,8)
	movsd	%xmm2, (%r14,%rcx,8)
	addq	$1, %rcx
	cmpl	%ecx, %r12d
	ja	.L7
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L9:
	movsd	(%r14,%rcx,8), %xmm0
	addsd	(%r15,%rcx,8), %xmm0
	movsd	%xmm0, 0(%r13,%rcx,8)
	addq	$1, %rcx
	cmpl	%ecx, %r12d
	ja	.L9
	leaq	-64(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	movl	%ebx, %edx
	movl	$.LC3, %esi
	movl	$1, %edi
	xorl	%ebx, %ebx
	cvtsi2sdq	%rax, %xmm0
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC2(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
	.p2align 4,,10
	.p2align 3
.L11:
	movslq	%ebx, %rax
	movl	%ebx, %r8d
	movl	%ebx, %ecx
	movsd	(%r14,%rax,8), %xmm0
	movl	%ebx, %edx
	movsd	0(%r13,%rax,8), %xmm2
	movl	$.LC4, %esi
	movsd	(%r15,%rax,8), %xmm1
	movl	$1, %edi
	movl	$3, %eax
	addl	$1, %ebx
	call	__printf_chk
	cmpl	%ebx, %r12d
	ja	.L11
.L12:
	leaq	-40(%rbp), %rsp
	xorl	%eax, %eax
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L3:
	.cfi_restore_state
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	leaq	-64(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	xorl	%edx, %edx
	movl	$.LC3, %esi
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC2(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
	jmp	.L12
.L15:
	movl	$.LC0, %edi
	call	puts
	orl	$-1, %edi
	call	exit
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	2576980378
	.long	1069128089
	.align 8
.LC2:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
