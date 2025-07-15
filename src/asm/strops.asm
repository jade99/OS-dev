PUBLIC __outs
PUBLIC __ins
PUBLIC __cmps

.CODE
__outs PROC FRAME
;; port: cx, string: rdx, count: r8
;; Move parameters into Home-Space
	MOV	QWORD PTR [rsp+24],	r8
	MOV	QWORD PTR [rsp+16],	rdx
	MOV	WORD PTR [rsp+8],	cx
;; Push non-volatile registers
	PUSH	rsi
.PUSHREG	rsi
.ENDPROLOG
;; rcx: count, dx: port, rsi: string
	MOV	rcx,	QWORD PTR [rsp+32]
	MOV	dx,		WORD PTR [rsp+16]
	MOV	rsi,	QWORD PTR [rsp+24]
	REP	OUTSB
;; EPILOGUE
	POP	rsi
	RET
__outs ENDP

__ins PROC FRAME
;; port: cx, string: rdx, count: r8
;; Move parameters into Home-Space
	MOV	QWORD PTR [rsp+24],	r8
	MOV	QWORD PTR [rsp+16],	rdx
	MOV	WORD PTR [rsp+8], cx
;; Push non-volatile registers
	PUSH	rdi
.PUSHREG	rdi
.ENDPROLOG
;; rcx: count, dx: port, rdi: string
	MOV	rcx,	QWORD PTR [rsp+32]
	MOV	dx,		WORD PTR [rsp+16]
	MOV	rdi,	QWORD PTR [rsp+24]
	REP INSB
;; EPILOGUE
	POP	rdi
	RET
__ins ENDP

__cmps PROC FRAME
;; string1: rcx, string2: rdx, count: r8
;; Move parameters into Home-Space
	MOV	QWORD PTR [rsp+24],	r8
	MOV	QWORD PTR [rsp+16],	rdx
	MOV	QWORD PTR [rsp+8],	rcx
;; Push non-volatile registers
	PUSH	rsi
.PUSHREG	rsi
	PUSH	rdi
.PUSHREG	rdi
;; Align stack on 16-byte boundary
	SUB	rsp,	8
.ALLOCSTACK	8
.ENDPROLOG
;; rcx: count, rsi: string1, rdi: string2
	XOR	rax,	rax
	MOV	rcx,	QWORD PTR [rsp+48]
	MOV	rsi,	QWORD PTR [rsp+32]
	MOV	rdi,	QWORD PTR [rsp+40]
	REPE CMPSB			;; repeat while equal
	JNE	__cmps_epilog	;; jump if not equal
	MOV	RAX,	1
__cmps_epilog:
;; EPILOGUE
	ADD	rsp,	8
	POP	rdi
	POP	rsi
	RET
__cmps ENDP
END