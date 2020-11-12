#pragma once
typedef unsigned char uint_8;
typedef unsigned short uint_16;
typedef unsigned int uint_32;
typedef unsigned long long uint_64;

#define VGA_WIDTH 80
#define VIDEO_MEMORY (uint_8 *)0xB8000

class IOAccess
{
protected:
    static inline void outb(uint_16, uint_8);
    static inline char inb(uint_16);
    static inline void io_wait(void);
};