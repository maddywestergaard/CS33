	.file	"creadcmov.c"
	.text
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB0:
	.cfi_startproc
	leaq	-8(%rdi), %rdx
	testq	%rdi, %rdi
	movl	$t, %eax
	cmovne	%rdx, %rax
	movq	(%rax), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	cread_alt, .-cread_alt
	.globl	t
	.data
	.align 8
	.type	t, @object
	.size	t, 8
t:
	.quad	-1
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-28)"
	.section	.note.GNU-stack,"",@progbits
