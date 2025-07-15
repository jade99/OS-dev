PUBLIC	__outb
PUBLIC	__inb

.CODE
__outb PROC FRAME
;; port: cx, byte dl
;; Moving parameters to Home-Space
	MOV	BYTE PTR [rsp+16],	dl
	MOV	WORD PTR [rsp+8],	cx
;; Aliging Stack to 16-byte boundry
	SUB	rsp,	8
.ALLOCSTACK	8
.ENDPROLOG
;; al: byte, dx: port
	MOV	al, BYTE PTR [rsp+24]
	MOV	dx,	WORD PTR [rsp+16]
	OUT	dx,	al
;; EPILOGUE
	ADD	rsp, 8
	RET
__outb ENDP

__inb PROC FRAME
;; port: cx
;; Moving parameters to Home-Space
	MOV	WORD PTR [rsp+8],	cx
;; Aligning Stack to 16-byte boundry
	SUB rsp,	8
.ALLOCSTACK	8
.ENDPROLOG
;; al: byte, dx: port
	XOR	rax, rax
	MOV	dx,	WORD PTR [rsp+16]
	IN	al,	dx
;; EPILOGUE
	ADD	rsp,	8
	RET
__inb ENDP
END