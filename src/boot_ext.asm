[org 0x7e00]
; Extended Bootloader code.
;%include "functions/print.asm"
;Entering 32 bit protected mode
%include "functions/pm.asm"

[bits 32]

jmp $

times 2048 - ($-$$) db 0