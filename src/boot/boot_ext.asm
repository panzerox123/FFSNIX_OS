[org 0x9000]
; Extended Bootloader code.
;%include "functions/print.asm"
;Entering 32 bit protected mode
;And then entering 64 bit mode
%include "functions/pm.asm"
[bits 32]

mov ebx, enter_32pm_err
call print_pm_func
hlt 

enter_32pm_err:
    db "Entering 32 bit protected mode - 64 bit long mode not accessible! ERRCODE 1", 0

%include "functions/print_pm.asm"
times 16384 - ($-$$) db 0