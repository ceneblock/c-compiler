	.file	"return_2.c"
	.text
	.globl	main
	.type	main, @function
main:
	movl	$2, %eax
	ret
	.size	main, .-main
	.ident	"GCC: (SUSE Linux) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
