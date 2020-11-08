[org 0x7e00]
; Extended Bootloader code.
mov bx, msg_string
call print_func
msg_string:
    db "Successfully read from disk", 0

jmp $

%include "functions/print.asm"
times 2048 - ($-$$) db 0