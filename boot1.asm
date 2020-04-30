.code16

.global main

main:
    movb $0x0e, %ah
    mov $msg, %si

loop:
    lodsb
    cmp $0x00, %al
    je _hcf
    int $0x10
    jmp loop

_hcf:
    jmp .
    
msg: .asciz "Hello World!\n\r"

.fill 512-(.-main),1,0
