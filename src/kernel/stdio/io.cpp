#pragma once
#include "io.h"

// outb sends 8/16/32 bit value to an I/O location
inline void IOAccess::outb(uint_16 port, uint_8 val)
{
    //volatile stops compiler optimisations
    asm volatile("outb %0, %1"
                 :
                 : "a"(val), "Nd"(port));
}

// inb recieves 8/16/32 bit value to I/O location
inline char IOAccess::inb(uint_16 port)
{
    char ret;
    asm volatile("inb %1, %0"
                 : "=a"(ret)
                 : "Nd"(port));
    return ret;
}

// Forces cpu to wait for IO operations to complete.
inline void IOAccess::io_wait(void)
{
    asm volatile("outb %%a1, $0x80"
                 :
                 : "a"(0));
}

void IOAccess::PIC_remap(void){
    uint_8 a1,a2;
    a1 = inb(PIC1_DATA);
    a2 = inb(PIC2_DATA);
    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
    outb(PIC1_DATA, 0);
    outb(PIC2_DATA, 8);
    outb(PIC1_DATA, 4);
    outb(PIC2_DATA, 2);
    outb(PIC1_DATA, ICW4_8086);
    outb(PIC2_DATA, ICW4_8086);

    outb(PIC1_DATA, a1);
    outb(PIC2_DATA, a2);
}