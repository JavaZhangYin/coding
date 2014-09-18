	.file	"pointer.cpp"
.lcomm __ZStL8__ioinit,1,1
	.globl	_fp
	.bss
	.align 4
_fp:
	.space 4
	.section	.text$_ZN7studentD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7studentD1Ev
	.def	__ZN7studentD1Ev;	.scl	2;	.type	32;	.endef
__ZN7studentD1Ev:
LFB972:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE972:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Shumin Guo\0"
LC2:
	.ascii "Function pointer ----->> \0"
LC3:
	.ascii "A is: \0"
LC4:
	.ascii "Pa is: \0"
LC5:
	.ascii "*Pa is: \0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB969:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA969
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	andl	$-16, %esp
	subl	$112, %esp
	.cfi_offset 3, -12
	call	___main
	movl	$5, 108(%esp)
	movl	$10, 80(%esp)
	movl	$4, 60(%esp)
	movl	$2, 64(%esp)
	movl	$4, 68(%esp)
	movl	$6, 72(%esp)
	movl	$7, 76(%esp)
	leal	32(%esp), %edx
	movl	$0, %ecx
	movl	$24, %eax
	andl	$-4, %eax
	movl	%eax, %ebx
	movl	$0, %eax
L4:
	movl	%ecx, (%edx,%eax)
	addl	$4, %eax
	cmpl	%ebx, %eax
	jb	L4
	addl	%eax, %edx
	movl	$30, 32(%esp)
	fldl	LC0
	fstpl	40(%esp)
	leal	87(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	87(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	leal	32(%esp), %eax
	addl	$16, %eax
	movl	%eax, (%esp)
LEHB0:
	call	__ZNSsC1EPKcRKSaIcE
LEHE0:
	leal	87(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	80(%esp), %eax
	movl	%eax, 104(%esp)
	leal	32(%esp), %eax
	movl	%eax, 28(%esp)
	leal	32(%esp), %eax
	movl	%eax, 100(%esp)
	leal	28(%esp), %eax
	movl	%eax, 96(%esp)
	leal	60(%esp), %eax
	movl	%eax, 92(%esp)
	movl	$5, 4(%esp)
	leal	60(%esp), %eax
	movl	%eax, (%esp)
LEHB1:
	call	__Z10printArrayIiEvPT_i
	movl	$5, 4(%esp)
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	__Z10printArrayIiEvPT_i
	movl	$5, 4(%esp)
	leal	60(%esp), %eax
	movl	%eax, (%esp)
	call	__Z13printArrayNewIiEvPT_i
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$__Z12printStudentP7student, _fp
	movl	_fp, %eax
	movl	%eax, 88(%esp)
	movl	_fp, %eax
	movl	28(%esp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	movl	88(%esp), %eax
	call	*%eax
	movl	80(%esp), %ebx
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC4, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	104(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPKv
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	104(%esp), %eax
	movl	(%eax), %ebx
	movl	$LC5, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	leal	32(%esp), %eax
	movl	%eax, (%esp)
	call	__Z12printStudentP7student
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z12printStudentP7student
LEHE1:
	leal	32(%esp), %eax
	movl	%eax, (%esp)
LEHB2:
	call	__ZN7studentD1Ev
LEHE2:
	movl	$0, %eax
	jmp	L13
L10:
	movl	%eax, %ebx
	leal	87(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	%ebx, %eax
	jmp	L8
L12:
	movl	%eax, %ebx
	leal	32(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN7studentD1Ev
	movl	%ebx, %eax
	jmp	L8
L11:
L8:
	movl	%eax, (%esp)
LEHB3:
	call	__Unwind_Resume
LEHE3:
L13:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE969:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA969:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE969-LLSDACSB969
LLSDACSB969:
	.uleb128 LEHB0-LFB969
	.uleb128 LEHE0-LEHB0
	.uleb128 L10-LFB969
	.uleb128 0
	.uleb128 LEHB1-LFB969
	.uleb128 LEHE1-LEHB1
	.uleb128 L12-LFB969
	.uleb128 0
	.uleb128 LEHB2-LFB969
	.uleb128 LEHE2-LEHB2
	.uleb128 L11-LFB969
	.uleb128 0
	.uleb128 LEHB3-LFB969
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
LLSDACSE969:
	.text
	.section .rdata,"dr"
LC7:
	.ascii "Student Info: \0"
LC8:
	.ascii "Name: \0"
LC9:
	.ascii "Age: \0"
LC10:
	.ascii "Height: \0"
	.text
	.globl	__Z12printStudentP7student
	.def	__Z12printStudentP7student;	.scl	2;	.type	32;	.endef
__Z12printStudentP7student:
LFB973:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$32, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	8(%ebp), %eax
	fldl	8(%eax)
	fstpl	-16(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %ebx
	movl	8(%ebp), %eax
	leal	16(%eax), %esi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC7, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC8, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC9, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fldl	-16(%ebp)
	fstpl	4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEd
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	addl	$32, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE973:
	.section	.text$_Z10printArrayIiEvPT_i,"x"
	.linkonce discard
	.globl	__Z10printArrayIiEvPT_i
	.def	__Z10printArrayIiEvPT_i;	.scl	2;	.type	32;	.endef
__Z10printArrayIiEvPT_i:
LFB988:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L16
L17:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	addl	$1, -12(%ebp)
L16:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L17
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE988:
	.section	.text$_Z13printArrayNewIiEvPT_i,"x"
	.linkonce discard
	.globl	__Z13printArrayNewIiEvPT_i
	.def	__Z13printArrayNewIiEvPT_i;	.scl	2;	.type	32;	.endef
__Z13printArrayNewIiEvPT_i:
LFB989:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L19
L20:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	addl	$1, -12(%ebp)
L19:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L20
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE989:
	.text
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1020:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L22
	cmpl	$65535, 12(%ebp)
	jne	L22
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
L22:
	cmpl	$0, 8(%ebp)
	jne	L21
	cmpl	$65535, 12(%ebp)
	jne	L21
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
L21:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1020:
	.def	__GLOBAL__sub_I_fp;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_fp:
LFB1021:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1021:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_fp
	.text
	.def	__GLOBAL__sub_D_fp;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_D_fp:
LFB1022:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$0, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1022:
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__sub_D_fp
	.section .rdata,"dr"
	.align 8
LC0:
	.long	858993459
	.long	1075262259
	.ident	"GCC: (GNU) 4.8.2"
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPKv;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEd;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
