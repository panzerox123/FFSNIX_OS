#pragma once 
#include "io_def.h"
#include "io.cpp"

void set_cursor_position(uint_16 x, uint_16 y){
    uint_16 position = x+VGA_WIDTH*y;
    outb(0x3D4,0x0F);
    outb(0x3D5, position);
    outb(0x3D4, 0x0E);
    outb(0x3D5, position >> 8);   
}

void set_cursor_position(uint_16 pos){
    uint_16 x = 0, y = 0;
    set_cursor_position(pos%VGA_WIDTH, pos/VGA_WIDTH);
}

uint_16 get_cursor_position(void){
    uint_16 pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((uint_16)inb(0x3D5)) << 8;
    return pos;
}

void get_cursor_position_coords(uint_16 &x, uint_16 &y){
    uint_16 pos = get_cursor_position();    
    x = pos%VGA_WIDTH;
    y = pos/VGA_WIDTH;
}

void enable_cursor(uint_8 cursor_start, uint_8 cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

void disable_cursor(void){
    outb(0x3D4,0x0A);
    outb(0x3D5,0x20);
}