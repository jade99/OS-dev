.code16

bootloader:
    xor %ax, %ax
    pushw %ax

    movw $0x0201, %ax
    movw $0x0002, %cx
    movw $0x0000, %dx
    movw $0x0500, %bx

    int $0x13

    jc _error
    
    ljmp $0x0000, $0x0500

_error:
    popw %ax
    addw $0x0001, %ax
    cmp $0x0003, %ax    
    je _print_error       
    pushw %ax
    jmp bootloader
    
_print_error:
    movb $0x0e, %ah
    mov $err, %si

loop:
    lodsb
    cmp $0x00, %al
    jc _hcf
    int $0x10
    jmp loop

_hcf:
    jmp .

    
err: .asciz "An error occured while trying to read from disk!\n\r"
