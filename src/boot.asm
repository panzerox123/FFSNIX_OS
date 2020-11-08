[org 0x7c00]
mov sp,bp
mov dl, [BOOT_DRIVE]

call disk_read_func 

%include "functions/print.asm"
%include "functions/disk_read.asm"
times 510 - ($-$$) db 0
dw 0xaa55 ;MAGIC NUMERO