	.file	"ele.c"
	.text
	.p2align 4,,15
	.globl	ele
	.type	ele, @function
ele:
.LFB0:
	.cfi_startproc
	movl	$7, %eax
	subq	%rdi, %rax
	salq	$4, %rax
	subq	%rsi, %rax
	leaq	7(%rdx,%rax,8), %rax
	movq	A(,%rax,8), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	ele, .-ele
	.comm	A,7168,32
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-28)"
	.section	.note.GNU-stack,"",@progbits
