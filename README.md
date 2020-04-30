# OS-dev

### Building

#### Building 'Stage 1'
    $ as boot0.asm -o boot0.out  
    $ ld boot0.out -o boot0.bin --oformat binary --Ttext 0x7c00  

#### Building 'Stage 2'
    $ as boot1.asm -o boot1.out  
    $ ld boot1.out -o boot1.bin --oformat binary --Ttext 0x500 -e main  

#### Chaining to 'Virtual Floppy Disk'
    $ cp boot0.bin boot.vfd  
    $ dd if=boot1.bin of=boot.vfd bs=512 count=1 seek=1  
    $ dd if=/dev/zero of=boot.vfd bs=512 count=2878 seek=2  

to build as ELF for debugging with gdb omit the `--oformat binary` argument and change filename/-extension  

---

### Running

 qemu-system-x86_64 -fda boot.vfd  
