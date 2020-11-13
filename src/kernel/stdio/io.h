#pragma once
typedef unsigned char uint_8;
typedef unsigned short uint_16;
typedef unsigned int uint_32;
typedef unsigned long long uint_64;
typedef unsigned const char * string;

//MASTER AND SLAVE PIC CHIPS
#define PIC1_COMMAND 0x20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0xa0
#define PIC2_DATA 0xa1

#define ICW1_INIT 0x10
#define ICW1_ICW4 0x01
#define ICW4_8086 0x01

#define VGA_WIDTH 80
#define VIDEO_MEMORY (uint_8 *)0xB8000

class IOAccess
{
protected:
    static inline void outb(uint_16, uint_8);
    static inline char inb(uint_16);
    static inline void io_wait(void);
    static void PIC_remap(void);
};