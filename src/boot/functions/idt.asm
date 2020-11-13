extern _idt

%include "functions/stack_64.asm"

idt_desc:
    dw 4095
    dq _idt

extern isr0_asm_wrapper

isr0:
    PUSH_ALL_64
    call isr0_asm_wrapper
    POP_ALL_64
    iretq
    GLOBAL isr0 

LOAD_IDT:
    lidt [idt_desc]
    sti
    ret
    GLOBAL LOAD_IDT