#pragma once

// outb sends 8/16/32 bit value to an I/O location
static inline void outb(unsigned short port, char val){
    //volatile stops compiler optimisations
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

// inb recieves 8/16/32 bit value to I/O location
static inline char inb(unsigned short port){
    char ret;
    asm volatile("inb %1, %0" : "=a"(ret):"Nd"(port));
    return ret;
}

// Forces cpu to wait for IO operations to complete.
static inline void io_wait(void){
    asm volatile("outb %%a1, $0x80" : : "a"(0));
}