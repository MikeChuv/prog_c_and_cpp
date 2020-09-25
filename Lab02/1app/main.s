	.file	"main.cpp"
	.text
	.section	.rodata
	.align 4
	.type	_ZL4nmax, @object
	.size	_ZL4nmax, 4
_ZL4nmax:
	.long	10
	.align 8
.LC0:
	.string	"\320\235\320\265\320\264\320\276\321\201\321\202\320\260\321\202\320\276\321\207\320\275\320\276 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262"
.LC1:
	.string	"-sa"
.LC2:
	.string	"-sr"
.LC3:
	.string	"-da"
.LC4:
	.string	"-dr"
.LC5:
	.string	"Max_a = %lf\n"
.LC6:
	.string	"Max_b = %lf\n"
.LC7:
	.string	"Dynamic"
.LC8:
	.string	"Wrong key"
	.text
	.globl	main
	.type	main, @function
main:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1824, %rsp
	movl	%edi, -1796(%rbp)
	movq	%rsi, -1808(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -1764(%rbp)
	cmpl	$4, -1796(%rbp)
	jg	.L2
	movl	$1, -1764(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
.L2:
	movq	-1808(%rbp), %rax
	addq	$32, %rax
	movq	(%rax), %rax
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -1760(%rbp)
	movq	-1808(%rbp), %rax
	addq	$32, %rax
	movq	(%rax), %rax
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -1756(%rbp)
	movq	-1808(%rbp), %rax
	addq	$32, %rax
	movq	(%rax), %rax
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -1752(%rbp)
	movq	-1808(%rbp), %rax
	addq	$32, %rax
	movq	(%rax), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -1748(%rbp)
	cmpl	$0, -1760(%rbp)
	jne	.L3
	cmpl	$0, -1756(%rbp)
	je	.L4
.L3:
	cmpl	$0, -1764(%rbp)
	jne	.L4
	movq	-1808(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rcx
	leaq	-1776(%rbp), %rdx
	leaq	-1780(%rbp), %rsi
	leaq	-1616(%rbp), %rax
	movq	%rax, %rdi
	call	_Z5inputPA10_dRiS1_Pc@PLT
	testl	%eax, %eax
	jne	.L5
	movq	-1808(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rcx
	leaq	-1768(%rbp), %rdx
	leaq	-1772(%rbp), %rsi
	leaq	-816(%rbp), %rax
	movq	%rax, %rdi
	call	_Z5inputPA10_dRiS1_Pc@PLT
	testl	%eax, %eax
	je	.L6
.L5:
	movl	$1, %eax
	jmp	.L7
.L6:
	movl	$0, %eax
.L7:
	testb	%al, %al
	je	.L8
	movl	$1, -1764(%rbp)
	jmp	.L16
.L8:
	cmpl	$0, -1760(%rbp)
	je	.L10
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rcx
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %esi
	leaq	-1616(%rbp), %rax
	movl	$65, %r8d
	movq	%rax, %rdi
	call	_Z19print_static_matrixPA10_diiPcc@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rcx
	movl	-1768(%rbp), %edx
	movl	-1772(%rbp), %esi
	leaq	-816(%rbp), %rax
	movl	$66, %r8d
	movq	%rax, %rdi
	call	_Z19print_static_matrixPA10_diiPcc@PLT
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %ecx
	leaq	-1616(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z14static_max_allPA10_dii@PLT
	movq	%xmm0, %rax
	movq	%rax, -1728(%rbp)
	movl	-1768(%rbp), %edx
	movl	-1772(%rbp), %ecx
	leaq	-816(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z14static_max_allPA10_dii@PLT
	movq	%xmm0, %rax
	movq	%rax, -1720(%rbp)
	movq	-1728(%rbp), %rax
	movq	%rax, -1816(%rbp)
	movsd	-1816(%rbp), %xmm0
	leaq	.LC5(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movq	-1720(%rbp), %rax
	movq	%rax, -1816(%rbp)
	movsd	-1816(%rbp), %xmm0
	leaq	.LC6(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-1728(%rbp), %xmm0
	ucomisd	-1720(%rbp), %xmm0
	jbe	.L34
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %esi
	leaq	-1664(%rbp), %rcx
	leaq	-1616(%rbp), %rax
	movq	%rax, %rdi
	call	_Z25static_positive_count_allPA10_diiPi@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rdx
	movl	-1780(%rbp), %ecx
	leaq	-1664(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z12print_vectorPiiPc@PLT
	jmp	.L16
.L34:
	movl	-1768(%rbp), %edx
	movl	-1772(%rbp), %esi
	leaq	-1664(%rbp), %rcx
	leaq	-816(%rbp), %rax
	movq	%rax, %rdi
	call	_Z25static_positive_count_allPA10_diiPi@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rdx
	movl	-1772(%rbp), %ecx
	leaq	-1664(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z12print_vectorPiiPc@PLT
	jmp	.L16
.L10:
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rcx
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %esi
	leaq	-1616(%rbp), %rax
	movl	$65, %r8d
	movq	%rax, %rdi
	call	_Z19print_static_matrixPA10_diiPcc@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rcx
	movl	-1768(%rbp), %edx
	movl	-1772(%rbp), %esi
	leaq	-816(%rbp), %rax
	movl	$66, %r8d
	movq	%rax, %rdi
	call	_Z19print_static_matrixPA10_diiPcc@PLT
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %ecx
	leaq	-1616(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z15static_max_rowsPA10_dii@PLT
	movq	%xmm0, %rax
	movq	%rax, -1744(%rbp)
	movl	-1768(%rbp), %edx
	movl	-1772(%rbp), %ecx
	leaq	-816(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z15static_max_rowsPA10_dii@PLT
	movq	%xmm0, %rax
	movq	%rax, -1736(%rbp)
	movq	-1744(%rbp), %rax
	movq	%rax, -1816(%rbp)
	movsd	-1816(%rbp), %xmm0
	leaq	.LC5(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movq	-1736(%rbp), %rax
	movq	%rax, -1816(%rbp)
	movsd	-1816(%rbp), %xmm0
	leaq	.LC6(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-1744(%rbp), %xmm0
	ucomisd	-1736(%rbp), %xmm0
	jbe	.L35
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %esi
	leaq	-1664(%rbp), %rcx
	leaq	-1616(%rbp), %rax
	movq	%rax, %rdi
	call	_Z26static_positive_count_rowsPA10_diiPi@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rdx
	movl	-1780(%rbp), %ecx
	leaq	-1664(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z12print_vectorPiiPc@PLT
	jmp	.L16
.L35:
	movl	-1768(%rbp), %edx
	movl	-1772(%rbp), %esi
	leaq	-1664(%rbp), %rcx
	leaq	-816(%rbp), %rax
	movq	%rax, %rdi
	call	_Z26static_positive_count_rowsPA10_diiPi@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rdx
	movl	-1772(%rbp), %ecx
	leaq	-1664(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z12print_vectorPiiPc@PLT
	jmp	.L16
.L4:
	cmpl	$0, -1752(%rbp)
	jne	.L17
	cmpl	$0, -1748(%rbp)
	je	.L18
.L17:
	cmpl	$0, -1764(%rbp)
	jne	.L18
	movq	-1808(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	leaq	-1776(%rbp), %rcx
	leaq	-1780(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_Z20dynamic_matrix_inputRiS_Pc@PLT
	movq	%rax, -1712(%rbp)
	movq	-1808(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rdx
	leaq	-1768(%rbp), %rcx
	leaq	-1772(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_Z20dynamic_matrix_inputRiS_Pc@PLT
	movq	%rax, -1704(%rbp)
	cmpq	$0, -1712(%rbp)
	je	.L19
	cmpq	$0, -1704(%rbp)
	jne	.L20
.L19:
	movl	$1, -1764(%rbp)
	jmp	.L21
.L20:
	cmpl	$0, -1752(%rbp)
	je	.L22
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rcx
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %esi
	movq	-1712(%rbp), %rax
	movl	$65, %r8d
	movq	%rax, %rdi
	call	_Z20print_dynamic_matrixPPdiiPcc@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rcx
	movl	-1768(%rbp), %edx
	movl	-1772(%rbp), %esi
	movq	-1704(%rbp), %rax
	movl	$66, %r8d
	movq	%rax, %rdi
	call	_Z20print_dynamic_matrixPPdiiPcc@PLT
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %ecx
	movq	-1712(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z15dynamic_max_allPPdii@PLT
	movq	%xmm0, %rax
	movq	%rax, -1680(%rbp)
	movl	-1768(%rbp), %edx
	movl	-1772(%rbp), %ecx
	movq	-1704(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z15dynamic_max_allPPdii@PLT
	movq	%xmm0, %rax
	movq	%rax, -1672(%rbp)
	movsd	-1680(%rbp), %xmm0
	ucomisd	-1672(%rbp), %xmm0
	jbe	.L36
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %esi
	leaq	-1664(%rbp), %rcx
	movq	-1712(%rbp), %rax
	movq	%rax, %rdi
	call	_Z26dynamic_positive_count_allPPdiiPi@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rdx
	movl	-1780(%rbp), %ecx
	leaq	-1664(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z12print_vectorPiiPc@PLT
	jmp	.L21
.L36:
	movl	-1768(%rbp), %edx
	movl	-1772(%rbp), %esi
	leaq	-1664(%rbp), %rcx
	movq	-1704(%rbp), %rax
	movq	%rax, %rdi
	call	_Z26dynamic_positive_count_allPPdiiPi@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rdx
	movl	-1772(%rbp), %ecx
	leaq	-1664(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z12print_vectorPiiPc@PLT
	jmp	.L21
.L22:
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rcx
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %esi
	movq	-1712(%rbp), %rax
	movl	$65, %r8d
	movq	%rax, %rdi
	call	_Z20print_dynamic_matrixPPdiiPcc@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rcx
	movl	-1768(%rbp), %edx
	movl	-1772(%rbp), %esi
	movq	-1704(%rbp), %rax
	movl	$66, %r8d
	movq	%rax, %rdi
	call	_Z20print_dynamic_matrixPPdiiPcc@PLT
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %ecx
	movq	-1712(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z16dynamic_max_rowsPPdii@PLT
	movq	%xmm0, %rax
	movq	%rax, -1696(%rbp)
	movl	-1768(%rbp), %edx
	movl	-1772(%rbp), %ecx
	movq	-1704(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z16dynamic_max_rowsPPdii@PLT
	movq	%xmm0, %rax
	movq	%rax, -1688(%rbp)
	movsd	-1696(%rbp), %xmm0
	ucomisd	-1688(%rbp), %xmm0
	jbe	.L37
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %esi
	leaq	-1664(%rbp), %rcx
	movq	-1712(%rbp), %rax
	movq	%rax, %rdi
	call	_Z27dynamic_positive_count_rowsPPdiiPi@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rdx
	movl	-1780(%rbp), %ecx
	leaq	-1664(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z12print_vectorPiiPc@PLT
	jmp	.L21
.L37:
	movl	-1776(%rbp), %edx
	movl	-1780(%rbp), %esi
	leaq	-1664(%rbp), %rcx
	movq	-1712(%rbp), %rax
	movq	%rax, %rdi
	call	_Z27dynamic_positive_count_rowsPPdiiPi@PLT
	movq	-1808(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rdx
	movl	-1780(%rbp), %ecx
	leaq	-1664(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_Z12print_vectorPiiPc@PLT
.L21:
	leaq	.LC7(%rip), %rdi
	call	puts@PLT
	jmp	.L16
.L18:
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
	movl	$1, -1764(%rbp)
.L16:
	movl	-1764(%rbp), %eax
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L29
	call	__stack_chk_fail@PLT
.L29:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
