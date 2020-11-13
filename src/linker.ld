OUTPUT_FORMAT(binary)

ENTRY (_start)

INPUT
(
    "out/boot/boot_ext.o"
    "out/boot/bin.o"
    "out/kernel/kernel.o"
)

OUTPUT
(
    "out/kernel/kernel.bin"
)

SECTIONS
{
    . = 0x9000;

    .text : ALIGN(0x1000)
    {
        *(.text)
    }

    .idt BLOCK(0x1000) : ALIGN(0x1000)
    {
        _idt = .;
        . = . + 0x1000;
    }

    .data : ALIGN(0x1000)
    {
        *(.data)
    }

    .rodata : ALIGN(0x1000)
    {
        *(.rodata)
    }

    .bss : ALIGN(0x1000)
    {
        *(COMMON)
        *(.bss)
    }
}