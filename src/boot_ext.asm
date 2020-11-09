[org 0x7e00]
; Extended Bootloader code.
;%include "functions/print.asm"
;Entering 32 bit protected mode
%include "functions/pm.asm"
[bits 32]

mov ebx, pm_string
call print_pm_func
jmp $

pm_string:
    db "Entering 32 bit protected mode...",0

%include "functions/print_pm.asm"

times 2048 - ($-$$) db 0