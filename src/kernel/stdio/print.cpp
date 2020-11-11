#pragma once
#include "io_def.h"
#include "color_codes.h"
#include "cursor_control.cpp"

void print(const char *str, uint_8 color = BG_GREY | FG_BLACK)
{
    uint_16 x_pos, y_pos;
    get_cursor_position_coords(x_pos, y_pos);
    char *temp_string = (char *)str;
    uint_16 index = 0;
    char curr;
    while (*temp_string != '\0')
    {
        switch (*temp_string)
        {
        case '\n':
            index += VGA_WIDTH-x_pos;
            x_pos = 0;
            y_pos++;
            set_cursor_position(x_pos, y_pos);
            *temp_string++;
            break;

        default:
            break;
        }
        *(VIDEO_MEMORY + index * 2) = *temp_string;
        *(VIDEO_MEMORY + index * 2 + 1) = color;
        index++;
        temp_string++;
        if (x_pos + 1 == VGA_WIDTH)
        {
            x_pos = 0;
            y_pos += 1;
        }
        else
            x_pos++;
    }
    set_cursor_position(x_pos,y_pos);
}

void clrscr(uint_64 color = BG_GREY | FG_BLACK){
    int i = 8;
    uint_64 clr_bits = 0;
    uint_64* j = (uint_64*)VIDEO_MEMORY;
    // Sending 2 byte vals
    for(; i<=56 ; i+=16) clr_bits += color << i;
    for(; j< (uint_64*)(VIDEO_MEMORY+4000) ;j++) *j = clr_bits;
    set_cursor_position(0,0);
    return;
}