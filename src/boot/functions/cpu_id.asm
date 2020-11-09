DETECT_CPUID:
    pushfd
    pop eax
    mov ecx, eax
    xor eax, 1 << 21
    push eax
    popfd
    pushfd
    pop eax
    push ecx
    popfd
    xor eax, ecx
    jz noCPUID
    ret

DETECT_LONGMODE:
    mov eax, 0x80000001
    cpuid
    test edx, 1 << 29
    jz noLongMode
    ret

noLongMode:
    hlt ; no long mode support


noCPUID:    
    hlt ; no cpuid support
