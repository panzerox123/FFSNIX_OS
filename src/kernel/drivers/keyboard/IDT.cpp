#pragma once
#include"IDT.h"
#include"../../stdio/io.cpp"
#include"../../stdio/print.cpp"
#include"scancodes1.cpp"

IOAccess io;
extern "C" void LOAD_IDT();

void IDT::intitializeIDT64(){
    _idt[1].zero = 0;
    _idt[1].offset_1 = (uint_16)(((uint_64)&isr0 & 0x000000000000ffff));
    _idt[1].offset_2 = (uint_16)(((uint_64)&isr0 & 0x00000000ffff0000) >> 16);
    _idt[1].offset_3 = (uint_32)(((uint_64)&isr0 & 0xffffffff00000000) >> 32);
    _idt[1].ist = 0;
    _idt[1].selector = 0x08;
    _idt[1].type_attr = 0x8e;
    
    io.PIC_remap();
    io.outb(0x21,0xfd);
    io.outb(0xa1,0xff);
    LOAD_IDT();
}

void IDT::isr0_handler(){
    uint_8 scan_code = inb(0x60);
    if(scan_code < 0x3A)
        screenOut.printc(SCAN_CODES_1::lookup_table[scan_code]);
    outb(0x20,0x20);
    outb(0xa0,0x20);
}

extern "C" void isr0_asm_wrapper(){
    idt.isr0_handler();
}

IDT::IDT()
{
    intitializeIDT64();
}
