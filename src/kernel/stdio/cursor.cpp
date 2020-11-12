#pragma once
#include "io.cpp"
#include "cursor.h"

//uint_16 cursor_pos = 0;

void CursorController::set_cursor_position(uint_16 position)
{
    this->outb(0x3D4, 0x0F);
    this->outb(0x3D5, (uint_8)(position & 0xFF));
    this->outb(0x3D4, 0x0E);
    this->outb(0x3D5, (uint_8)((position >> 8) & 0xFF));
    this->cursor_pos = position;
}

void CursorController::set_cursor_position(int x, int y)
{
    this->set_cursor_position(x+y*VGA_WIDTH);
}

uint_16 CursorController::get_cursor_position(void)
{
    return this->cursor_pos;
}

void CursorController::get_cursor_position_coords(uint_16 &x, uint_16 &y)
{
    x = this->cursor_pos % VGA_WIDTH;
    y = this->cursor_pos / VGA_WIDTH;
}

void CursorController::enable_cursor(uint_8 cursor_start, uint_8 cursor_end)
{
    this->outb(0x3D4, 0x0A);
    this->outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
    this->outb(0x3D4, 0x0B);
    this->outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

void CursorController::disable_cursor(void)
{
    this->outb(0x3D4, 0x0A);
    this->outb(0x3D5, 0x20);
}

CursorController::CursorController(){
    this->set_cursor_position(0,0);
}