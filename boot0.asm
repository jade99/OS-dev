.code16

.global _start

_start:
    xorw %ax, %ax
    movw %ax, %ds
    movw %ax, %es
    
    movw $0x8000, %bx
    
    cli 
    movw %bx, %ss
    movw %ax, %sp
    sti

    cld

    ljmp $0x0000, $bootloader

.include "./bootloader.asm"

.fill 510-(.-_start),1,0
.word 0xaa55
