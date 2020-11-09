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

%include "functions/cpu_id.asm"
%include "functions/paging.asm"


Start_Protected:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax 
    mov fs, ax
    mov gs, ax
    mov ebp, 0x90000
    mov esp, ebp
    call DETECT_CPUID
    call DETECT_LONGMODE
    call SETUP_IDENTITY_PAGING
    call EDIT_GDT_LM
    jmp CODE_SEG:START_LM_64

%include "functions/lm_64bit.asm"
