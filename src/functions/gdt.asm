; Global descriptor table 
gdt_null_desc: 
    dd 0x0
    dd 0x0
gdt_code_desc:
    dw 0xffff ; Limit 
    dw 0x0000 ; Base (low)
    db 0x0 ; Base (medium)
    db 10011010b ; Flags 
    db 11001111b ; Flags + Upper limit
    db 0x0 ; Base (high)
gdt_data_desc:
    dw 0xffff
    dw 0x0000
    db 0x0
    db 10010010b ; executable bit zero
    db 11001111b
    db 0x0

gdt_end:

gdt_desc: ;gdt descriptor
    dw gdt_end - gdt_null_desc - 1
    dd gdt_null_desc

CODE_SEG equ gdt_code_desc - gdt_null_desc
DATA_SEG equ gdt_data_desc - gdt_null_desc