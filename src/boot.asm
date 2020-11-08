[org 0x7c00]
mov [BOOT_DRIVE], dl
mov sp,bp

call disk_read_func 

jmp EXT_BOOT

%include "functions/print.asm"
%include "functions/disk_read.asm"

times 510 - ($-$$) db 0
dw 0xaa55 ;MAGIC NUMERO