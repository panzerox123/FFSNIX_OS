; Code to enter Protected Mode

jmp Enter_Protected

%include "functions/gdt.asm"

Enter_Protected:
    cli ; Ignore BIOS Interrupts
    lgdt [gdt_desc] ; Load GDT 
    mov eax , cr0
    or eax, 1
    mov cr0, eax
    jmp CODE_SEG:Start_Protected

[bits 32]

Start_Protected:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax 
    mov fs, ax
    mov gs, ax
    mov ebp, 0x90000
    mov esp, ebp
