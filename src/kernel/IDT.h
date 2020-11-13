#pragma once
#include "stdio/io.h"

struct IDT64
{
    uint_16 offset_1; // offset bits between 0 - 15
    uint_16 selector; // code segment selector in the GDT
    uint_8 ist;       //Interrupt stack table
    uint_8 type_attr;
    uint_16 offset_2; //offset b/w 16-31
    uint_32 offset_3; //offset between 31-63
    uint_32 zero; //Reserved
};

extern IDT64 _idt[256];
extern uint_64 isr0;

class IDT : protected IOAccess
{
public:
    IDT();
    void intitializeIDT64();
    void isr0_handler();
};

IDT idt;
