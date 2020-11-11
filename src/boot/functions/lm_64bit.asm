[bits 64]
extern _start
START_LM_64:
    mov edi, 0xb8000
    mov rax, 0xff20ff20ff20ff20
    mov ecx, 500
    rep stosq
    call _start
    jmp $

