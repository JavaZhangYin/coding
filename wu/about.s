	.file	"about.cpp"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%x, %x\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB7:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA7
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$10, 24(%esp)
	leal	24(%esp), %eax
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
LEHB0:
	call	_printf
LEHE0:
	movl	$0, %eax
	jmp	L5
L4:
	movl	%eax, (%esp)
LEHB1:
	call	__Unwind_Resume
LEHE1:
L5:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE7:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA7:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE7-LLSDACSB7
LLSDACSB7:
	.uleb128 LEHB0-LFB7
	.uleb128 LEHE0-LEHB0
	.uleb128 L4-LFB7
	.uleb128 0
	.uleb128 LEHB1-LFB7
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE7:
	.text
	.ident	"GCC: (GNU) 4.8.2"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
