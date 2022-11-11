	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 0
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$10, -8(%rbp)
	movq	_c@GOTPCREL(%rip), %rax
	movl	$30, (%rax)
	leaq	L_.str(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movq	_c@GOTPCREL(%rip), %rdx
	movb	$0, %al
	callq	_printf
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.comm	_c,4,2                          ## @c
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"extern base: %p, %p\n"

.subsections_via_symbols
