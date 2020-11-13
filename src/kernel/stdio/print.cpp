#pragma once
#include "print.h"

void ScreenOut::print(const char *str, uint_8 color = BG_BYELLOW | FG_BLACK)
{
    uint_16 index = cursorController.get_cursor_position();
    while (*str != '\0')
    {
        switch (*str)
        {
        case '\n':
            index += (VGA_WIDTH - index % VGA_WIDTH);
            break;
        default:
            *(VIDEO_MEMORY + 2 * index) = *str;
            *(VIDEO_MEMORY + 2 * index + 1) = color;
            index++;
            break;
        }
        str++;
    }
    cursorController.set_cursor_position(index);
}

void ScreenOut::clrscr(uint_64 color = BG_BYELLOW | FG_BLACK)
{
    int i = 8;
    uint_64 clr_bits = 0;
    uint_64 *j = (uint_64 *)VIDEO_MEMORY;
    // Sending 2 byte vals
    for (; i <= 56; i += 16)
        clr_bits += color << i;
    for (; j < (uint_64 *)(VIDEO_MEMORY + 4000); j++)
        *j = clr_bits;
    cursorController.set_cursor_position(0, 0);
    return;
}

void ScreenOut::printc(char c, uint_8 color = BG_BYELLOW | FG_BLACK)
{
    *(VIDEO_MEMORY + 2 * cursorController.get_cursor_position()) = c;
    *(VIDEO_MEMORY + 2 * cursorController.get_cursor_position() + 1) = color;
    cursorController.set_cursor_position(cursorController.get_cursor_position() + 1);
}

const char *ScreenOut::convertASCII(uint_8 input)
{
    char *temp;
    *temp = input;
    return temp;
}