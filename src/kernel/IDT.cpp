#pragma once
#include"IDT.h"
#include"stdio/io.cpp"
#include"stdio/print.cpp"

IOAccess io;
extern "C" void LOAD_IDT();

void IDT::intitializeIDT64(){
    for(uint_64 index = 0; index < 256; index++){
        _idt[index].zero = 0;
        _idt[index].offset_1 = (uint_16)(((uint_64)&isr0 & 0x000000000000ffff));
        _idt[index].offset_2 = (uint_16)(((uint_64)&isr0 & 0x00000000ffff0000) >> 16);
        _idt[index].offset_3 = (uint_32)(((uint_64)&isr0 & 0xffffffff00000000) >> 32);
        _idt[index].ist = 0;
        _idt[index].selector = 0x08;
        _idt[index].type_attr = 0x8e;
    }
    io.outb(0x21,0xfd);
    io.outb(0xa1,0xff);
    LOAD_IDT();
}

void IDT::isr0_handler(){
    inb(0x60);
    screenOut.print("k");
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
