[bits 64]
extern _start
START_LM_64:
    mov edi, 0xb8000
    mov rax, 0x7f207f207f207f20
    mov ecx, 500
    rep stosq
    call _start
    jmp $

