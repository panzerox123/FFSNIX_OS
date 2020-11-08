; Extended Bootloader code.
mov bx, msg_string
call print_func
jmp $

msg_string:
    db "Successfully read from disk", 0

%include "functions/print.asm"
times 2048 - ($-$$) db 0