EXT_BOOT equ 0x9000 ; Extended partition macro

disk_read_func:
    mov ah, 0x02 ; Move head to read mode
    mov bx, EXT_BOOT
    mov al, 32 ; Number of sectors to read
    mov dl, [BOOT_DRIVE] ; Get Disk number from BIOS
    mov ch, 0x00 ; Cylinder
    mov dh, 0x00 ; Head
    mov cl, 0x02 ; 2nd Sector. First one should store boot.bin
    int 0x13; Interrupt reads the hard drive
    jc disk_read_failure
    ret


BOOT_DRIVE:
    db 0


disk_read_failure_msg:
    db "Unable to read disk. ERRCODE 0", 0

disk_read_failure:
    mov bx, disk_read_failure_msg;
    call print_func
    jmp $