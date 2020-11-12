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