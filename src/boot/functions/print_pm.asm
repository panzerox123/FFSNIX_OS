; Write to ebx and call print_pm_function to print
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

print_pm_func:
    mov edx, VIDEO_MEMORY
    loop:
        mov al, [ebx]
        mov ah, WHITE_ON_BLACK
        cmp [ebx], byte 0
            je loop_end
            mov [edx], ax
            add edx, 2
            add ebx, 1
            jmp loop
    loop_end:
    ret
